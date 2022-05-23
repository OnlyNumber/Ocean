#include "Cell.h"
#include "Ocean.h"

class Ocean;


Coordinate Cell::getNeighborCordWithAnImage(char anImage)
{
	int count = 0;
	Coordinate neighbors[4];

	if (anImage == getOffsetChar(getNorth()))
	{
		neighbors[count++] = getNorth();
	}

	if (anImage == getOffsetChar(getSouth()))
	{
		neighbors[count++] = getSouth();
	}

	if (anImage == getOffsetChar(getEast()))
	{
		neighbors[count++] = getEast();
	}

	if (anImage == getOffsetChar(getWest()))
	{
		neighbors[count++] = getWest();
	}

	if (count >= 1)
	{
		//std::cout << count;
		return neighbors[ rand() % count];
	}
	else
	{
		return getOffset();
	}

}

char Cell::getOffsetChar(Coordinate aCoord)
	{
		
		if (_owner.getCell(aCoord.GetX(), aCoord.GetY()) == nullptr)
		{
			return DEFAULT_IMAGE;
		}
		else
		{

			return _owner.getCell(aCoord.GetX(), aCoord.GetY())->getImage();
		}
	}


Coordinate Cell::getNorth()
{
	Coordinate empty(1, 1);

	if ((anOffset.GetX() - 1) < 0)
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY())->getOffset();
		}

		//return _owner.getCell(anOffset.GetX(), anOffset.GetY());
	}
	else
	{
		if (_owner.getCell(anOffset.GetX() - 1, anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX() - 1, anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX() - 1, anOffset.GetY())->getOffset();
		}
		//return _owner.getCell(anOffset.GetX() - 1, anOffset.GetY() );
	}

}
Coordinate Cell::getSouth()
{
	if ((anOffset.GetX() + 1) == DEFAULT_ROWS)
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY())->getOffset();
		}
	}
	else
	{
		if (_owner.getCell(anOffset.GetX() + 1, anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX() + 1, anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX() + 1, anOffset.GetY())->getOffset();
		}
	}

}

Coordinate Cell::getWest()
{
	if ((anOffset.GetY() - 1) < 0)
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY())->getOffset();
		}
	}
	else
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY() - 1) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY() - 1);
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY() - 1)->getOffset();
		}
	}

}
Coordinate Cell::getEast()
{
	if ((anOffset.GetY() + 1) == DEFAULT_COLUMNS)
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY()) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY());
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY())->getOffset();
		}
	}
	else
	{
		if (_owner.getCell(anOffset.GetX(), anOffset.GetY() + 1) == nullptr)
		{
			return Coordinate(anOffset.GetX(), anOffset.GetY() + 1);
		}
		else
		{
			return _owner.getCell(anOffset.GetX(), anOffset.GetY() + 1)->getOffset();
		}
	}
}

Coordinate Cell::getEmptyNeighborCoord()
{
	return getNeighborCordWithAnImage(DEFAULT_IMAGE);
}

Coordinate Cell::getPreyNeighborCoord()
{
	return getNeighborCordWithAnImage(PREY_IMAGE);
}

Cell* Cell::getCellAt(Coordinate aCoord)
{
	return  _owner.getCell(aCoord.GetY(), aCoord.GetX());
}

void Cell::assignCellAt(Coordinate aCoord, Cell* aCell)
{
	_owner.setCell(aCoord, aCell);
}

void Cell::setImage(char needImage)
{
	image = needImage;
}

char Cell::getImage()
{
	return image;
}

Coordinate& Cell::getOffset()
{
	return anOffset;
}

void Cell::setOffset(Coordinate& aCoord)
{
	anOffset = aCoord;
}

Ocean Cell::getOwner()
{
	return _owner;
}

void Cell::setOwner(Ocean* owner)
{
	_owner = *owner;
	return;
}

bool Cell::getTurnDoneCheck()
{
	return isTurnDoneCheck;
}
void Cell::setTurnDoneCheck(bool turn)
{
	isTurnDoneCheck = turn;
}

void Cell::deleteThisCell(Coordinate aCoord)
{
	_owner.destroyCell(aCoord);
}

