#pragma once
#include "Prey.h"

class Predator : public Prey
{

public:
	//todo: �������� �������
	virtual ~Predator() {};
	virtual void Process();

private:
	int timeToFeed;

};

