#ifndef GLOGIC_H
#define GLOGIC_H
#include"Ocean.h"
#include"Prey.h"
#include"Predator.h"
#include"Obstacle.h"

#include<iostream>
#include<vector>
#include<array>
#include<string>

class DisplayOcean;

class OceanLogic{
private:
    int NumPrey;
    int NumPredators;
    int NumObstacles;
    int NumIterations;
    Ocean OMap;
    
    void InitOcean(void);
    void UpdateOcean(void);
    void ResetOcean(void);
    std::vector<std::string> GetCurrentOceanMap(void);
    void FindNumPrey(void);
    void FindNumPredators(void);

public:
    OceanLogic(int NumPrey = DEFAULT_NUM_PREY, 
               int NumPredators = DEFAULT_NUM_PREDATORS, 
               int NumObstacles = DEFAULT_NUM_OBSRACLES, 
               int NumCols = DEFAULT_COLS, 
               int NumRows = DEFAULT_ROWS,
               int NumIterations = DEFAULT_NUM_ITERATOINS) {
        OMap.SetNumCols(NumCols);
        OMap.SetNumRows(NumRows);
        OMap.SetSize(NumCols * NumRows);

        this->NumPrey = NumPrey;
        this->NumObstacles = NumObstacles;
        this->NumPredators = NumPredators;
        this->NumIterations = NumIterations;
    }

    std::vector<std::pair<std::vector<std::string>, std::array<int,4>>> Run(void);

    int GetNumPrey ( void ) { 
        return NumPrey; 
    }

    int GetNumPredators ( void ) { 
        return NumPredators; 
    }

    int GetNumObstacles ( void ) { 
        return NumObstacles; 
    }

    int GetNumIterations(void) { 
        return NumIterations; 
    }

    ~OceanLogic( void ) {};
};

#endif