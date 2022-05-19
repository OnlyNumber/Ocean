#pragma once
#include "Prey.h"

class Predator : public Prey
{

public:
	//todo: доделать хищника
	virtual ~Predator() {};
	virtual void Process();

private:
	int timeToFeed;

};

