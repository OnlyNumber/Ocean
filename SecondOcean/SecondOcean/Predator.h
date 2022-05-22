#pragma once
#include "Prey.h"

class Predator : public Prey 
{

public:
	//todo: доделать хищника
	virtual ~Predator() {};
	virtual void process();

	Predator(Ocean& owner, Coordinate offset) : Prey(owner, offset)	
	{
		//setOwner(owner);
		//setOffset(offset);
		setImage(PREDATOR_IMAGE);
		setTimeToReproduce(DEFAULT_TIME_TO_REPRODUCE);
		timeToFeed = DEFAULT_TIME_TO_FEED;
	};
	void MoveFrom(Coordinate from, Coordinate to);


	void eatPrey(Coordinate from, Coordinate to);
	void Reproduce(Coordinate anOffset);
private:
	int timeToFeed;

};

