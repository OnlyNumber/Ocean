#include "Ocean.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include "Obstacle.h"
#include "Constants.h"

Ocean::Ocean(int rows, int columns, int obstacles, int predators, int preys) :

	_rows(rows),
	_columns(columns),
	_obstacles(obstacles),
	_predators(predators),
	_preys(preys),
	_visitor(rows* columns)
{
	_cells = new Cell **[_rows];

	for (int x = 0; x < _rows; x++)
	{
		_cells[x] = new Cell *[_columns];

	}

	for (int x = 0; x < _rows; x++)
	{
		for (int y = 0; y < _columns; y++)
		{
			_cells[x][y] = nullptr;
		}

	}

	random.intialize();

	createObstacles();

	createPrey();

	createPredator();
}


Random Ocean::GetRandom()
{
	return random;
}

Cell* Ocean::getCell(int x, int y)
{
	return _cells[x][y];
}

void Ocean::setCell(Coordinate aCoord, Cell* aCell)
{
	_cells[aCoord.GetX()][aCoord.GetY()] = aCell;
}

int Ocean::getRows()
{
	return _rows;
}
int Ocean::getColumns()
{
	return _columns;
}

void Ocean::run()
{
	

		_visitor.clear();
		for (int x = 0; x < _rows; x++)
		{
			for (int y = 0; y < _columns; y++)
			{
				if (_cells[x][y] != nullptr)
				{
					Cell* currnetItem = _cells[x][y];

					if (!_visitor.isVisited(currnetItem))
					{
						_cells[x][y]->process();
						_visitor.visit(currnetItem);
					}
				}
			}
		}
};

Coordinate Ocean::getEmptyCellCoord()
{
	int x, y;
	
	do{
	x = random.nextIntBetween(0, _rows - 1);
	y = random.nextIntBetween(0, _columns - 1);
	} while (_cells[x][y] != nullptr);
	Coordinate empty(x,y);

	return empty;

}

void Ocean::createObstacles()
{
	Coordinate empty;
	for (int i = 0; i < _obstacles; i++)
	{
		empty = getEmptyCellCoord();
		_cells[empty.GetX()][empty.GetY()] = new Obstacle(*this, empty);
	}
	return;
}

void Ocean::createPrey()
{
	Coordinate empty;
	for (int i = 0; i < _preys; i++)
	{
		empty = getEmptyCellCoord();
		_cells[empty.GetX()][empty.GetY()] = new Prey(*this, empty);
	}
}

void Ocean::createPredator()
{
	Coordinate empty;
	for (int i = 0; i < _predators; i++)
	{
		empty = getEmptyCellCoord();
		_cells[empty.GetX()][empty.GetY()] = new Predator(*this, empty);
	}

}
void Ocean::destroyCell(Coordinate empty)
{

	delete _cells[empty.GetX()][empty.GetY()];
	_cells[empty.GetX()][empty.GetY()] = nullptr;
}

//todo: узнать о gof
//gof visitor
//gof flyweight