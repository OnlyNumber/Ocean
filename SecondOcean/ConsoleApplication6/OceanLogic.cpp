#include "OceanLogic.h"

std::vector<std::pair<std::vector<std::string>, std::array<int, 4>>> OceanLogic::Run(void) {
    std::vector<std::pair<std::vector<std::string>, std::array<int, 4>>> AllMaps;
    int NumIterations = DEFAULT_NUM_ITERATOINS;

    //std::cout << "\n\nEnter number of iteraions (default max = 1000): ";
    //std::cout.flush();
    //std::cin >> NumIterations;
    //if (NumIterations > 1000) NumIterations = 1000;
    //std::cout << "\nNumber iterations = " << NumIterations << "\nbegin run...\n";
    //std::cout.flush();
    InitOcean();

    for (int iteration = 0; iteration < NumIterations; iteration++) {
        if (NumPredators > 0 && NumPrey > 0) {
            std::array<int, 4> data = { iteration, NumObstacles, NumPredators, NumPrey };
            AllMaps.push_back(std::pair<std::vector<std::string>, std::array<int, 4>>(GetCurrentOceanMap(), data));
            UpdateOcean();
            //Display.DisplayStats(iteration, NumObstacles, NumPredators, NumPrey);
            //Display.DisplayBorder(OMap.GetNumRows());
            //Display.DisplayCells(OMap.GetNumRows(), OMap.GetNumCols(), OMap);
            //Display.DisplayBorder(OMap.GetNumRows());
            //std::cout.flush();
        }
    }
    return AllMaps;
    //std::cout << "\n\nEnd of Simulation\n";
    //std::cout.flush();
}

void OceanLogic::InitOcean(void) {
    OMap.AddEmptyCells();

    OMap.AddDistinctCell<Obstacle>(NumObstacles);
    OMap.AddDistinctCell<Predator>(NumPredators);
    OMap.AddDistinctCell<Prey>(NumPrey);

    //std::cout << "\n\nEnter number of obstacles (max = " << OMap.GetSize() <<"): ";
    //std::cout.flush();
    //std::cin >> NumObstacles;
    //if (NumObstacles >= OMap.GetSize()) NumObstacles = OMap.GetSize();
    //std::cout << "\nNumber obstacles accepted = " << NumObstacles;
    //std::cout.flush();

    //std::cout << "\n\nEnter number of prey (default = " << OMap.GetSize() - NumObstacles <<"): ";
    //std::cout.flush();
    //std::cin >> NumPrey;
    //if (NumPrey >= (OMap.GetSize() - NumObstacles)) {
    //   NumPrey = OMap.GetSize() - NumObstacles;
    //}
    //std::cout << "\nNumber prey accepted = " << NumPrey << "\n\n";
    //std::cout.flush();

    //std::cout << "\n\nEnter number of predators (default = " << OMap.GetSize() - NumObstacles - NumPrey <<"): ";
    //std::cout.flush();
    //std::cin >> NumPredators;
    //if (NumPrey >= (OMap.GetSize() - NumObstacles - NumPrey)) {
    //    NumPrey = OMap.GetSize() - NumObstacles - NumPrey;
    //}
    //std::cout << "\nNumber predators accepted = " << NumPredators << "\n\n";
    //std::cout.flush();

    
    //Display.DisplayStats(-1, NumObstacles, NumPredators, NumPrey);
    //Display.DisplayBorder(OMap.GetNumRows());
    //Display.DisplayCells(OMap.GetNumRows(), OMap.GetNumCols(), OMap);
    //Display.DisplayBorder(OMap.GetNumRows());
}

void OceanLogic::UpdateOcean(void) {
    for (int x = 0; x < OMap.GetNumCols(); x++) {
        for (int y = 0; y < OMap.GetNumRows(); y++) {
            OMap.Process(Coordinate(x, y));
        }
    }
    OMap.ResetMoves();
    FindNumPredators();
    FindNumPrey();
}

void OceanLogic::ResetOcean(void) {
    OMap.ClearOcean();
}

std::vector<std::string> OceanLogic::GetCurrentOceanMap(void) {
    std::vector<std::string> Map;
    std::string Column;

    for (int x = 0; x < OMap.GetNumCols(); x++) {
        Column = "";
        for(int y = 0; y < OMap.GetNumRows(); y++) {
            Column += OMap.GetCharOfCell(Coordinate(x, y));
        }
        Map.push_back(Column);
    }
    return Map;
}

void OceanLogic::FindNumPrey(void) {
    int count = 0;

    for (int x = 0; x < OMap.GetNumCols(); x++) {
        for (int y = 0; y < OMap.GetNumRows(); y++) {
            if (OMap.GetCharOfCell(Coordinate(x, y)) == DEFAULT_PREY_IMAGE) {
                count++;
            }
        }
    }

    this->NumPrey = count;
}

void OceanLogic::FindNumPredators(void) {
    int count = 0;

    for (int x = 0; x < OMap.GetNumCols(); x++) {
        for (int y = 0; y < OMap.GetNumRows(); y++) {
            if (OMap.GetCharOfCell(Coordinate(x, y)) == DEFAULT_PRDATOR_IMAGE) {
                count++;
            }
        }
    }

    this->NumPredators = count;
}