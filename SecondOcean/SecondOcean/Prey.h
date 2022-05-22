#pragma once
#include "Cell.h"

class Ocean;

class Prey : public Cell
{
public:
	Prey(Ocean& owner, Coordinate offset) : Cell(owner, offset)
	{
		//setOwner(owner);
		//setOffset(offset);

		setImage(PREY_IMAGE);
		timeToReproduce = DEFAULT_TIME_TO_REPRODUCE;
	};


	virtual ~Prey() {};
	virtual void MoveFrom(Coordinate from, Coordinate to);
	virtual void Reproduce(Coordinate anOffset);
	virtual void process();
	void setTimeToReproduce(int);
	int getTTimeToReproduce();


private:
	int timeToReproduce;

};

