#include "Prey.h"
#include "Ocean.h"
#include <iostream>

class Ocean;

void Prey::MoveFrom(Coordinate from, Coordinate to)
{

	assignCellAt(from, nullptr);

	assignCellAt(to, this);
	this->setOffset(to);
}
void Prey::Reproduce(Coordinate anOffset)
	{
	_owner.setPreys(_owner.getPreys() + 1);
	assignCellAt(anOffset, new Prey(_owner, anOffset));
	 

	}
 void Prey::process()
{
		 MoveFrom(getOffset(), getEmptyNeighborCoord());
		 
		 if (--timeToReproduce == 0)
		 {

			 Reproduce(getEmptyNeighborCoord());

			 timeToReproduce = DEFAULT_TIME_TO_REPRODUCE;
		 }
 }

 void Prey::setTimeToReproduce(int ttr)
 {
	 timeToReproduce = ttr;
 }
 int Prey::getTTimeToReproduce()
 {
	 return timeToReproduce;
 }