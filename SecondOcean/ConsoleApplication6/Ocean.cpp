#include"Ocean.h"
#include"Prey.h"
#include"Predator.h"
#include"Obstacle.h"
#include<time.h>

Coordinate Ocean::GetEmptyCellCoord(void) {
    int x, y;
    Coordinate empty;

    do {
        x = Random.NextBetween(0, NumCols - 1);
        y = Random.NextBetween(0, NumRows - 1);
        empty.setX(x);
        empty.setY(y);
    } while (GetCellAt(empty) != nullptr);

    return empty;
}

Cell* Ocean::GetCellAt(Coordinate aCoord) {
    auto SearchCell = Cells.find(aCoord);
    return SearchCell->second;
}

void Ocean::AssignCellAt(Coordinate aCoord, Cell* aCell) {
    auto SearchCell = Cells.find(aCoord);
    SearchCell->second = aCell;
    return;
}

Coordinate Ocean::GetNeighborWithImage(Coordinate aCoord, char anImage) {
    Coordinate neighbors[4];
    int count = 0;

    Coordinate NorthCoordinate = aCoord.North();
    Coordinate SouthCoordinate = aCoord.South(this->NumRows);
    Coordinate EastCoordinate = aCoord.East(this->NumCols);
    Coordinate WestCoordinate = aCoord.West();

    Cell* CellNorth = GetCellAt(NorthCoordinate);
    Cell* CellSouth = GetCellAt(SouthCoordinate);
    Cell* CellEast = GetCellAt(EastCoordinate);
    Cell* CellWest = GetCellAt(WestCoordinate);

    if (GetCharOfCell(NorthCoordinate) == anImage)
        neighbors[count++] = NorthCoordinate;
    if (GetCharOfCell(SouthCoordinate) == anImage)
        neighbors[count++] = SouthCoordinate;
    if (GetCharOfCell(EastCoordinate) == anImage)
        neighbors[count++] = EastCoordinate;
    if (GetCharOfCell(WestCoordinate) == anImage)
        neighbors[count++] = WestCoordinate;

    if (count == 0) {
        return aCoord;
    }
    else {
        return neighbors[Random.NextBetween(0, count - 1)];
    }
}

Coordinate Ocean::GetEmptyNeighborCoord(Coordinate aCoord) {
    return GetNeighborWithImage(aCoord, DEFAULT_IMAGE);
}

Coordinate Ocean::GetPreyNeighborCoord(Coordinate aCoord) {
    return GetNeighborWithImage(aCoord, DEFAULT_PREY_IMAGE);
}

void Ocean::AddEmptyCells(void) {
    for (int x = 0; x < NumCols; x++) {
        for (int y = 0; y < NumRows; y++) {
            Cells.insert(std::pair<Coordinate, Cell *>(Coordinate(x, y),nullptr));
        }
    }
}

void Ocean::Process(Coordinate aCell) {
    auto SearchCell = Cells.find(aCell);
    if (SearchCell->second == nullptr || SearchCell->second->getImage() == DEFAULT_OBSTACLE_IMAGE) {
        return;
    }

    auto ClosestEmptyCell = GetEmptyNeighborCoord(aCell);
    auto ClosestPreyCell = GetPreyNeighborCoord(aCell);

    if (SearchCell->second->IsHunger()) {
        if (aCell == ClosestPreyCell) {
            delete SearchCell->second;
            AssignCellAt(aCell, nullptr);
            return;
        }
    }
    if (SearchCell->second->IsMoving()) {
        auto AppointmentCell = Cells.find(aCell);
        if (SearchCell->second->IsHunting() && ClosestPreyCell != aCell) {
            AppointmentCell = Cells.find(ClosestPreyCell);
            std::swap(AppointmentCell->second, SearchCell->second);
            delete SearchCell->second;
            SearchCell->second = AppointmentCell->second->Copy();
            AppointmentCell->second->Eaten();
        }
        else {
            if (ClosestEmptyCell == aCell) {
                return;
            }
            AppointmentCell = Cells.find(ClosestEmptyCell);
            std::swap(AppointmentCell->second, SearchCell->second);
        }

        AppointmentCell->second->Moved();

        if (AppointmentCell->second->IsReproducible()){
            AppointmentCell->second->Reproduct();
            SearchCell->second = AppointmentCell->second->Copy();
        }
    }
}

void Ocean::ResetMoves(void) {
    std::map<Coordinate, Cell*>::iterator it = Cells.begin();

    while (it != Cells.end()) {
        if (it->second != nullptr) {
            it->second->ResetMoves();
        }
        it ++;
    }
}

char Ocean::GetCharOfCell(Coordinate aCell) {
    Cell* SearchCell = GetCellAt(aCell);
    if (SearchCell == nullptr) {
        return DEFAULT_IMAGE;
    }
    else {
        return SearchCell->getImage();
    }
}

void Ocean::ClearOcean(void) {
    std::map<Coordinate, Cell*>::iterator it = Cells.begin();

    while (it != Cells.end()) {
        if (it->second != nullptr) {
            delete it->second;
            it->second = nullptr;
        }
        it++;
    }
    Cells.clear();
}