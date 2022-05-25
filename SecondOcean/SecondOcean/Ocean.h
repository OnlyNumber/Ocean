#pragma once
#include "Cell.h"
#include "Constants.h"
#include "Random.h"
#include "Coordinate.h"
#include "CellsVisitors.h"
#include "OceanDisplay.h"
#include <iostream>
//class Cell;

class Ocean
{
	//todo: создать класс для инициализации и вывода клеток
public:

	Ocean(int rows, int columns, int obstacles, int predators, int preys);

	Random GetRandom();
	Cell* getCell(int x, int y);
	void setCell(Coordinate aCoord, Cell* aCell);

	int getRows();
	int getColumns();

	void setRows(int set)
	{
		_rows = set;
	}

	void setColumns(int set)
	{
		_columns = set;
	}

	void setPredators(int set)
	{
		 _predators = set;
	}
	void setPreys(int set)
	{
		_preys = set;
	}
	
	void setObstacles(int set)
	{
		_obstacles = set;
	}

	int getPredators()
	{
		return _predators;
	}
	int getPreys()
	{
		return _preys;
	}
	int getIterations(int i)
	{
		return i;
	}




	Coordinate getEmptyCellCoord();
	void createObstacles();
	void createPrey();
	void createPredator();

	void destroyCell(Coordinate );

	void run();
	//Random random;
private:
	Cell*** _cells;
	CellsVisitors _visitor;
	Random random;
	//OceanDisplay& _display;

	int _iteration;
	int _rows;
	int _columns;
	int _obstacles;
	int _predators;
	int _preys;

};