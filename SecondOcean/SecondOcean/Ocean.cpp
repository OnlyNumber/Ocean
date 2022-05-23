#include "Ocean.h"
#include "Cell.h"
#include "Prey.h"
#include "Predator.h"
#include "Obstacle.h"
#include "Constants.h"

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
	return _rows;
}

void Ocean::run()
{
	random.intialize();
	for (int x = 0; x < DEFAULT_ROWS; x++)
	{
		for (int y = 0; y < DEFAULT_COLUMNS; y++)
		{
			_cells[x][y] = nullptr;    
		}
	}

	createObstacles();
	
	createPrey();

	createPredator();

	for (int i = 0; i < 10; i++)
	{
		_visitor.clear();
		std::cout << "\n ";// Int i" << i;
		for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				if (_cells[x][y] != nullptr)
				{
					Cell* currnetItem = _cells[x][y];

					if (!_visitor.isVisited(currnetItem))
					{

					//std::cout << "work";
						_cells[x][y]->process();
						_visitor.visit(currnetItem);
					}
				}
			}
		}
		for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			std::cout << "\n";
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				if (_cells[x][y] == nullptr)
				{
					std::cout << DEFAULT_IMAGE;
				}
				else
				{
					std::cout << _cells[x][y]->getImage();
				}
			}
		}
		/*for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				if (_cells[x][y] != nullptr)
				{
					_cells[x][y]->setTurnDoneCheck(true);
				}
			}
		}*/

	}

};

Coordinate Ocean::getEmptyCellCoord()
{
	int x, y;
	
	do{
	x = random.nextIntBetween(0, DEFAULT_ROWS - 1);
	y = random.nextIntBetween(0, DEFAULT_COLUMNS - 1);
	} while (_cells[x][y] != nullptr);

	Coordinate empty(x,y);

	return empty;

}

void Ocean::createObstacles()
{
	Coordinate empty;
	for (int i = 0; i < 10; i++)
	{
		empty = getEmptyCellCoord();
		std::cout << "\n" << empty.GetX() << " " << empty.GetY() << " ";
		_cells[empty.GetX()][empty.GetY()] = new Obstacle(*this, empty);
	}
	return;
}

void Ocean::createPrey()
{
	Coordinate empty;
	//std::cout << "tut";
	empty = getEmptyCellCoord();
	//std::cout << "tut2";
	_cells[empty.GetX()][empty.GetY()] = new Prey(*this, empty);
	//std::cout <<"Cell::"<< _cells[empty.GetX()][empty.GetY()];
}

void Ocean::createPredator()
{
	Coordinate empty;
	empty = getEmptyCellCoord();
	_cells[empty.GetX()][empty.GetY()] = new Predator(*this, empty);
	//std::cout <<"Cell::"<< _cells[empty.GetX()][empty.GetY()];
}
void Ocean::destroyCell(Coordinate empty)
{
	
	//std::cout << "\n" << empty.GetX() << " " << empty.GetY() << " ";
	delete _cells[empty.GetX()][empty.GetY()];
	_cells[empty.GetX()][empty.GetY()] = nullptr;
}

//todo: узнать о gof
//gof visitor
//gof flyweight