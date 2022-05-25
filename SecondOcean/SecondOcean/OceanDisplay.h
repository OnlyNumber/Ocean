#pragma once
#include <iostream>
#include "Ocean.h"

//class Ocean;

class OceanDisplay 
{
public:

	int getRows()
	{
		return _rows;
	}

	int getColumns()
	{
		return _columns;
	}

	int getPredators()
	{
		return _predators;
	}
	int getPreys()
	{
		return _preys;
	}
	int getIterations()
	{
		return _iterations;
	}
	int getObstacles()
	{
		return _obstacles;
	}
	void initializeOcean()
	{
		int set;
		std::cout << "Enter amount Rows ->";
		std::cin >> _rows;
		std::cout << "Enter amount Columns ->";
		std::cin >> _columns;

		std::cout << "Enter amount Predators ->";
		std::cin >> _predators;

		std::cout << "Enter amount Preys ->";
		std::cin >> _preys;

		std::cout << "Enter amount Obstacles ->";
		std::cin >> _obstacles;

		std::cout << "Enter amount Iterations ->";
		std::cin >> _iterations;
	}

	void displayOcean(Ocean ocean, int iter);
private:

	int _rows;
	int _columns;
	int _predators;
	int _preys;
	int _obstacles;
	int _iterations;
	//Ocean& _owner;
	
	


};

