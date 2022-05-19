#ifndef OCEAN_H
#define OCEAN_H
#include"Cell.h"
#include"Coordinate.h"
#include"Random.h"
#include"Constants.h"

#include<iostream>
#include<map>

class Ocean {
    int NumRows;
    int NumCols;
    int Size;
    std::map<Coordinate, Cell*>Cells;

private:
    Random Random;
    Coordinate GetEmptyCellCoord(void);
    Coordinate GetNeighborWithImage(Coordinate aCoord, char anImage);
    Coordinate GetEmptyNeighborCoord(Coordinate aCoord);
    Coordinate GetPreyNeighborCoord(Coordinate aCoord);

public:
    Ocean(int NumRows = DEFAULT_ROWS, int NumCols = DEFAULT_COLS) {
        SetNumRows(NumRows);
        SetNumCols(NumCols);
        SetSize(NumCols * NumRows);
    }
    Cell* GetCellAt(Coordinate aCorrd);
    void AssignCellAt(Coordinate aCoord, Cell* aCell);

    void AddEmptyCells(void);
    template <typename T> void AddDistinctCell(int NumOfCells) {
        Coordinate empty;
        for (int count = 0; count < NumOfCells; count++) {
            empty = GetEmptyCellCoord();
            AssignCellAt(Coordinate(empty), new T());
        }
    }

    void Process(Coordinate aCell);
    void ResetMoves( void );

    int GetNumRows(void) {
        return NumRows;
    }
    int GetNumCols(void) {
        return NumCols;
    }
    int GetSize(void) {
        return Size;
    }
    void SetNumRows(int NumRows) {
        this->NumRows = NumRows;
    }
    void SetNumCols(int NumCols) {
        this->NumCols = NumCols;
    }
    void SetSize(int Size) {
        this->Size = Size;
    }

    void ClearOcean(void);

    char GetCharOfCell(Coordinate aCell);

    ~Ocean (void) { ClearOcean(); }
};

#endif