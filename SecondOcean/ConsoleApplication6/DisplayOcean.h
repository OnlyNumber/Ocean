#ifndef DISOCEAN_H
#define DISOCEAN_H

#include<iostream>
#include<vector>
#include<array>
#include<string>

class DisplayOcean{
private:
    void DisplayStats(int iteration, int numObstacles, int numPredators, int numPrey);
    void DisplayBorder(int numCols);

public:
    void DisplayMaps(std::vector<std::pair<std::vector<std::string>, std::array<int, 4>>> AllMaps);
   };

#endif