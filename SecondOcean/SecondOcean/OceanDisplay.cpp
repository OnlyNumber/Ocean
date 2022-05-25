#include "OceanDisplay.h"

void OceanDisplay::displayOcean(Ocean ocean, int iter)
{
	std::cout << "\nIteration: " << iter <<" Preys: " <<ocean.getPreys() <<" Predators: " << ocean.getPredators();
	for (int x = 0; x < ocean.getRows(); x++)
	{
		std::cout << "\n";
		for (int y = 0; y < ocean.getColumns(); y++)
		{
			if (ocean.getCell(x, y) == nullptr)
			{
				std::cout << DEFAULT_IMAGE;
			}
			else
			{
				std::cout << ocean.getCell(x, y)->getImage();
			}
		}
	}
}