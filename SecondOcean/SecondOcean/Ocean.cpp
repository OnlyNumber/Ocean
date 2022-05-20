#include "Ocean.h"
#include "Cell.h"
#include "Prey.h"
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
			_cells[x][y] = new Cell(*this, Coordinate(x,y));    // TODO: изменить на пустой указатель, Cell дол жен стать абстрактным
		}
	}

	createObstacles();
	
	createPrey();

	for (int i = 0; i < 100; i++)
	{
		std::cout << "\n";
		for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			std::cout << "\n";
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				std::cout << _cells[x][y]->getImage();
			}
		}
		for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				_cells[x][y]->process();
			}
		}
		for (int x = 0; x < DEFAULT_ROWS; x++)
		{
			for (int y = 0; y < DEFAULT_COLUMNS; y++)
			{
				_cells[x][y]->setTurnDoneCheck(true);
			}
		}

	}

};

Coordinate Ocean::getEmptyCellCoord()
{
	Coordinate empty;
	int x, y;
	
	do{
	x = random.nextIntBetween(0, DEFAULT_ROWS - 1);
	y = random.nextIntBetween(0, DEFAULT_COLUMNS - 1);
	//std::cout <<"\n"<< x << " " << y <<" ";
	} while (_cells[x][y]->getImage() != DEFAULT_IMAGE);


	empty = _cells[x][y]->getOffset();
	//std::cout << "\n" << empty.GetX() << " " << empty.GetY() << " ";
	delete _cells[x][y];


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
	empty = getEmptyCellCoord();
	_cells[empty.GetX()][empty.GetY()] = new Prey(*this, empty);
	//std::cout <<"Cell::"<< _cells[empty.GetX()][empty.GetY()];
}
void deleteCell(Coordinate aCoord)
{
	//delete _cells[aCoord.GetX()][aCoord.GetY()];
	//return;
}








//todo: узнать о gof
//gof visitor
//gof flyweight