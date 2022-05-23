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

		return (x != anOffset.x || y != anOffset.y);

	}

	bool operator == (Coordinate anOffset)
	{

		return (x == anOffset.x && y == anOffset.y);

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

