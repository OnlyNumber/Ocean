#pragma once
class Coordinate
{
public:
	Coordinate() {};
	
	Coordinate(int X, int Y)
	{
		x = X;
		y = Y;
	}
	virtual ~Coordinate() {};
	void operator = (Coordinate anOffset)
	{
		x = anOffset.x;
		y = anOffset.y;

	};

	bool operator != (Coordinate anOffset)
	{
		x == anOffset.x;
		y == anOffset.y;
		if (x != anOffset.x || y != anOffset.y)
		{
			return true;
	    }
	}

	bool operator == (Coordinate anOffset)
	{
		x == anOffset.x;
		y == anOffset.y;
		if (x == anOffset.x && y == anOffset.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
private:
	int x;
	int y;

	


};

