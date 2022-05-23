#pragma once
#include "Constants.h"
#include "Coordinate.h"
#include "Random.h"


class Ocean;

class Cell
{

public: 
	Cell();
	Cell(Ocean& owner, Coordinate offset) : _owner(owner), anOffset(offset) 
	{
		setImage(DEFAULT_IMAGE);
	};

	
	

	virtual ~Cell() {};
	virtual void process() = 0;

	void setImage(char needImage);
	char getImage();

	bool getTurnDoneCheck();
	void setTurnDoneCheck(bool turn);

	Coordinate& getOffset();
	void setOffset(Coordinate& aCoord);
	Ocean getOwner();
	void setOwner(Ocean* owner);

	Coordinate getNeighborCordWithAnImage(char anImage);
	Coordinate getEmptyNeighborCoord();
	Coordinate getPreyNeighborCoord();
	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	void deleteThisCell(Coordinate);
	
	Coordinate getNorth();
	Coordinate getSouth();
	Coordinate getWest();
	Coordinate getEast();
	
	char getOffsetChar(Coordinate);

protected:
	Ocean& _owner;

private:
	bool isTurnDoneCheck = false;
	Coordinate anOffset;
	char image = DEFAULT_IMAGE;
	
};

