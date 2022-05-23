#pragma once
#include "Cell.h"
#include "Constants.h"
#include "Random.h"
#include "Coordinate.h"
#include "CellsVisitors.h"
#include <iostream>
//class Cell;

class Ocean
{
	//todo: создать класс для инициализации и вывода клеток
public:
	Ocean() : _visitor(DEFAULT_ROWS* DEFAULT_COLUMNS)
	{
		
	}
	Random GetRandom();
	Cell* getCell(int x, int y);
	void setCell(Coordinate aCoord, Cell* aCell);
	//void deleteCell(Coordinate aCoord);
	int getRows();
	int getColumns();
	Coordinate getEmptyCellCoord();
	void createObstacles();
	void createPrey();
	void createPredator();

	void destroyCell(Coordinate );

	void run();
	//Random random;
private:
	int _rows;
	int _columns;
	Cell* _cells[DEFAULT_ROWS][DEFAULT_COLUMNS];
	CellsVisitors _visitor;
	Random random;

};

