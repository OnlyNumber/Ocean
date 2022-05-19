#include "Random.h"
#define MAX 32767

void Random::intialize()
{
	seed1 = 3797;
	seed2 = 2117;
}
void Random::init(int s1, int s2)
{
	seed1 = s1;
	seed2 = s2;
}

float Random::randReal()
{
	int c;
	int static first = 1;

	if (first)
	{
		seed1 *= 2;
		seed2 *= 2;
		if (seed1 > MAX)
		{
			seed1 -= MAX;
		}
		if (seed2 > MAX)
		{
			seed2 -= MAX;
		}
		first = 0;

		for (int index = 1; index <= 30; index++)
		{
			randReal();
		}
	}
	c = seed1 + seed2;
	if (c > MAX)
	{
		c -= MAX;
	}
	c *= 2;
	if (c > MAX)
	{
		c -= MAX;
	}
	seed1 = seed2;
	seed2 = c;
	return  c / 32767.0f;
}

unsigned Random::nextIntBetween(int low, int high)
{
	float r, t;
	int c;

	r = float(high) - (float)low + 1.0f;
	t = r * randReal();
	c = (int)t;
	return (low + c);
}