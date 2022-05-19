#pragma once
#include "Constants.h"
#include "Coordinate.h"
#include "Random.h"

class Ocean;

class Cell
{

public: 
	Cell();
	Cell(Ocean* owner, Coordinate offset) : _owner(*owner), anOffset(offset) 
	{
		setImage(DEFAULT_IMAGE);
	};

	
	

	virtual ~Cell() {};
	//todo: сделать проверку на то, была ли у клетка задействована 
	virtual void process() {};

	void setImage(char needImage);
	char getImage();

	bool getTurnDoneCheck();
	void setTurnDoneCheck(bool turn);

	Coordinate& getOffset();
	void setOffset(Coordinate& aCoord);
	Ocean getOwner();
	void setOwner(Ocean* owner);

	void selfDestroy()
	{
		delete(this);
	};

	Ocean* returnUkazatel()
	{
		return &_owner;
	}

	Coordinate getNeighborCordWithAnImage(char anImage);
	Coordinate getEmptyNeighborCoord();
	Coordinate getPreyNeighborCoord();
	Cell* getCellAt(Coordinate aCoord);
	void assignCellAt(Coordinate aCoord, Cell* aCell);
	
	Cell* getNorth();
	Cell* getSouth();
	Cell* getWest();
	Cell* getEast();
	
private:
	bool isTurnDoneCheck = false;
	Coordinate anOffset;
	Ocean& _owner;
	char image = DEFAULT_IMAGE;
	
};

