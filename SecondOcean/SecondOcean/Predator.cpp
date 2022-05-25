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
	_owner.setPredators(_owner.getPredators() + 1);
	assignCellAt(anOffset, new Predator(_owner, anOffset));


}
void Predator::process()
{
	//std::cout << timeToFeed;
	if (--timeToFeed <= 0)
	{
		Coordinate prey = getPreyNeighborCoord();
		
		if (prey != getOffset())
		{
			std::cout << prey.GetX() << " " << prey.GetY()<< " ";
			eatPrey(getOffset(), getPreyNeighborCoord());
			timeToFeed = DEFAULT_TIME_TO_FEED;
			return;
		}
		else
		{
			_owner.setPredators(_owner.getPredators() - 1);
			assignCellAt(getOffset(), nullptr);
			_owner.destroyCell(getOffset());
			return;
		}

	}


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

}

void Predator::eatPrey(Coordinate from, Coordinate to)
{
	_owner.setPreys(_owner.getPreys() - 1);
	_owner.destroyCell(to);
	assignCellAt(from, nullptr);

	assignCellAt(to, this);
	this->setOffset(to);

	/*Cell* toCell;
	toCell = new Cell(_owner,from);
	assignCellAt(to, this);
	this->setOffset(to);

	assignCellAt(from, toCell);
	toCell->setOffset(from);*/
}

