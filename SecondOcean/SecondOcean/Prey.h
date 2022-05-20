#pragma once
#include "Cell.h"

class Ocean;

class Prey : public Cell
{
public:
	//todo:доделать жертву
	Prey(Ocean& owner, Coordinate offset) : Cell(owner, offset)
	{
		//setOwner(owner);
		setOffset(offset);
		setImage(PREY_IMAGE);
		timeToReproduce = DEFAULT_TIME_TO_REPRODUCE;
	};

	Prey(Prey &mother)
	{
		//this->setOwner(mother.getOwner());
	}

	virtual ~Prey() {};
	virtual void MoveFrom(Coordinate from, Coordinate to);
	virtual void Reproduce(Coordinate anOffset);
	virtual void process();

private:
	int timeToReproduce;

};

