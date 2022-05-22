#include "Predator.h"
#include "Ocean.h"
#include <iostream>

class Ocean;

void Predator::MoveFrom(Coordinate from, Coordinate to)
{

	assignCellAt(from, nullptr);

	assignCellAt(to, this);
	this->setOffset(to);
}

void Predator::Reproduce(Coordinate anOffset)
{	
	assignCellAt(anOffset, new Predator(_owner, anOffset));


}
void Predator::process()
{

	if (getTurnDoneCheck() == true)
	{

		MoveFrom(getOffset(), getEmptyNeighborCoord());
		
		setTimeToReproduce(getTTimeToReproduce() - 1);

		if(getTTimeToReproduce() == 0)
		{
			Coordinate empty = getEmptyNeighborCoord();
			if (empty != getOffset())
			{
				Reproduce(getEmptyNeighborCoord());

				setTimeToReproduce(DEFAULT_TIME_TO_REPRODUCE);
			}
		}

		

		if (--timeToFeed  <=5)
		{
			//assignCellAt(getOffset(), new Cell(_owner, getOffset()));
			//delete this;
		}
		else
		{
			eatPrey(getOffset(),getPreyNeighborCoord());
		}
	}
	setTurnDoneCheck(false);
}

void Predator::eatPrey(Coordinate from, Coordinate to)
{
	/*Cell* toCell;
	toCell = new Cell(_owner,from);
	assignCellAt(to, this);
	this->setOffset(to);

	assignCellAt(from, toCell);
	toCell->setOffset(from);*/
}

