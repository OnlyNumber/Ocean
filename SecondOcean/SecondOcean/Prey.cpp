#include "Prey.h"
#include "Ocean.h"
#include <iostream>

class Ocean;

void Prey::MoveFrom(Coordinate from, Coordinate to)
{
	
	Cell* toCell;
	toCell = getOwner().getCell(to.GetX(), to.GetY());
	assignCellAt(to, this);
	this->setOffset(to);

	assignCellAt(from, toCell);
	toCell->setOffset(from);
}
void Prey::Reproduce(Coordinate anOffset)
	{
	//Cell* toCell;
	//toCell = _owner.getCell(anOffset.GetX(), anOffset.GetY());
	//delete toCell;
	
	deleteThisCell(anOffset);

	assignCellAt(anOffset, new Prey(_owner, anOffset));
	 

	}
 void Prey::process()
{

	 if (getTurnDoneCheck() == true)
	 {
		 
		 MoveFrom(getOffset(), getEmptyNeighborCoord());
		 
		 if (--timeToReproduce == 0)
		 {

			 Reproduce(getEmptyNeighborCoord());

			 timeToReproduce = DEFAULT_TIME_TO_REPRODUCE;
		 }
	 }
	setTurnDoneCheck(false);
 }

 void Prey::setTimeToReproduce(int ttr)
 {
	 timeToReproduce = ttr;
 }
 int Prey::getTTimeToReproduce()
 {
	 return timeToReproduce;
 }