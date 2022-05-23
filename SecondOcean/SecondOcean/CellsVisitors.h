#pragma once
#include "Cell.h"

class CellsVisitors
{
public:

	CellsVisitors(int size)
	{
		_lastIndex = 0;
		_visitedCells = new Cell*[size];
		_size = size;
	}

	void visit(Cell* item)
	{
		_visitedCells[_lastIndex++] = item;
	}
	bool isVisited(Cell* item)
	{
		bool result = false;
		
		for (int i = _lastIndex - 1; i >= 0; i--)
		{
			if (_visitedCells[i] == item)
			{
				result = true;
				break;
			}
		}

		return result;
	}

	void clear()
	{
		_lastIndex = 0;
	}

private:
	Cell** _visitedCells;
	int _size;
	int _lastIndex;
};

