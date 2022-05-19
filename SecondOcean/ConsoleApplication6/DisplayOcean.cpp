#include "DisplayOcean.h"

void DisplayOcean::DisplayMaps(std::vector<std::pair<std::vector<std::string>, std::array<int, 4>>> AllMaps) {
    std::vector<std::pair<std::vector<std::string>, std::array<int, 4>>>::iterator Maps = AllMaps.begin();
    for (Maps; Maps != AllMaps.end(); Maps++) {
        std::array<int, 4>::iterator data = Maps->second.begin();
        int Iteration = *data;
        ++data;
        int NumObstacles = *data;
        ++data;
        int NumPredators = *data;
        ++data;
        int NumPrey = *data;
        DisplayStats(Iteration, NumObstacles, NumPredators, NumPrey);

        std::vector<std::string>::iterator cells = Maps->first.begin();
        int BorderSize = cells->size();
        DisplayBorder(BorderSize);
        for (cells; cells != Maps->first.end(); cells++) {
            std::cout << "|";
            std::cout << *cells;
            std::cout << "|" << std::endl;
        }
        DisplayBorder(BorderSize);
    }
}

void DisplayOcean::DisplayBorder(int numRows) {
    std::cout << "*";
    for (int x = 0; x < numRows; x++) {
        std::cout << char(196);
    }
    std::cout << "*";
    std::cout << "\n";
}

void DisplayOcean::DisplayStats(int iteration, int numObstacles, int numPredators, int numPrey) {
    std::cout << "\n\n";
    std::cout << "Iteration number: " << ++iteration << " ";
    std::cout << "Obstacles: " << numObstacles << " ";
    std::cout << "Predators: " << numPredators << " ";
    std::cout << "Prey: " << numPrey << "\n";
    std::cout.flush();
}