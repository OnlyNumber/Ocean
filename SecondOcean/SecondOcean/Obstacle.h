#pragma once
#include "Cell.h"
#include "Constants.h"

class Obstacle : public Cell
{

public:
	Obstacle(Ocean* owner, Coordinate offset) :Cell(owner, offset)
	{
		setOwner(owner);
		setOffset(offset);
		setImage(OBSTACLE_IMAGE);
	};
	virtual ~Obstacle() {};
	//todo: доделать припятствие
private:
	
	
};

