#include "Cell.h"
#include "Ocean.h"

class Ocean;


Coordinate Cell::getNeighborCordWithAnImage(char anImage)
{
	int count = 0;
	Cell* neighbors[4];

	if (anImage == getNorth()->getImage())
	{
		neighbors[count++] = getNorth();
	}

	if (anImage == getSouth()->getImage())
	{
		neighbors[count++] = getSouth();
	}

	if (anImage == getEast()->getImage())
	{
		neighbors[count++] = getEast();
	}

	if (anImage == getWest()->getImage())
	{
		neighbors[count++] = getWest();
	}

	if (count >= 1)
	{
		return neighbors[/*getOwner().GetRandom().nextIntBetween(0, count - 1)*/ rand() % count]->getOffset();
	}
	else
	{
		return getOffset();
	}

}
//TODO: Идиот вы допустили ошибку в координатах, это будет стоить вам в 510 лет
Cell* Cell::getNorth()
{
	if ((anOffset.GetX() - 1) < 0)
	{
		//std::cout << anOffset.GetX();
		return _owner.getCell(anOffset.GetX(), anOffset.GetY());
	}
	else
	{
		return _owner.getCell(anOffset.GetX() - 1, anOffset.GetY() );
	}

}
Cell* Cell::getSouth()
{
	if ((anOffset.GetX() + 1) == DEFAULT_ROWS)
	{
		return _owner.getCell(anOffset.GetX(), anOffset.GetY());
	}
	else
	{
		return _owner.getCell(anOffset.GetX() + 1, anOffset.GetY());
	}

}

Cell* Cell::getWest()
{
	if ((anOffset.GetY() - 1) < 0)
	{
		return _owner.getCell(anOffset.GetX(), anOffset.GetY());
	}
	else
	{
		return _owner.getCell(anOffset.GetX(), anOffset.GetY() - 1);
	}

}
Cell* Cell::getEast()
{
	if ((anOffset.GetY() + 1) == DEFAULT_COLUMNS)
	{
		return _owner.getCell(anOffset.GetX(), anOffset.GetY());
	}
	else
	{
		return _owner.getCell(anOffset.GetX(), anOffset.GetY() + 1);
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
