#pragma once
#define MAX 32767

class Random
{
private:
	int seed1, seed2;
public:
		void intialize();

		void init(int s1, int s2);

		float randReal();

		unsigned nextIntBetween(int low, int high);

	
};

