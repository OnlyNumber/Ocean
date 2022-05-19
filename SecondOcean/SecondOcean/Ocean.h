#pragma once
#include "Cell.h"
#include "Constants.h"
#include "Random.h"
#include "Coordinate.h"
#include <iostream>

//class Cell;

class Ocean
{
	//todo: создать класс для инициализации и вывода клеток
public:
	Random GetRandom();
	Cell* getCell(int x, int y);
	void setCell(Coordinate aCoord, Cell* aCell);
	//void deleteCell(Coordinate aCoord);
	int getRows();
	int getColumns();
	Coordinate getEmptyCellCoord();
	void createObstacles();
	void createPrey();
	void run();
	//Random random;
private:
	int _rows;
	int _columns;
	Cell* _cells[DEFAULT_ROWS][DEFAULT_COLUMNS];
	
	Random random;

};

