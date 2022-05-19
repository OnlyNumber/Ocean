#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
private:
    int x;
    int y;

public:
    Coordinate(int aX, int aY) :x(aX), y(aY) {}
    Coordinate(void) { x = 0; y = 0; }
    Coordinate(const Coordinate& aCoord) {
        this->x = aCoord.x;
        this->y = aCoord.y;
    }

    ~Coordinate(void) {}

    int getX(void) { return x; }
    int getY(void) { return y; }
    void setX(int aX) { x = aX; }
    void setY(int aY) { y = aY; }

    Coordinate North() {
        int y;

        if (this->getY() == 0) {
            y = 0;
        }
        else {
            y = this->getY() - 1;
        }
        return Coordinate(this->x, y);
    }

    Coordinate South(int NumCols) {
        int y;
        
        if (this->y >= (NumCols - 1)) {
            y = NumCols - 1;
        }
        else {
            y = this->y + 1;
        }
        return Coordinate(this->x, y);
    }

    Coordinate West() {
        int x;

        if (this->x == 0) {
            x = 0;
        }
        else {
            x = this->x - 1;
        }
        return Coordinate(x, this->y);
    }

    Coordinate East(int NumRows) {
        int x;

        if (this->x >= (NumRows - 1)) {
            x = (NumRows - 1);
        }
        else {
            x = this->x + 1;
        }
        return Coordinate(x, this->y);
    }

    void operator = (const Coordinate& aCoord) {
        x = aCoord.x;
        y = aCoord.y;
    }

    bool operator == (const Coordinate& aCoord) {
        return x == aCoord.x && y == aCoord.y;
    }

    bool operator < (const Coordinate& aCoord) const noexcept {
        if (x < aCoord.x) return true;
        if (x > aCoord.x) return false;
        
        if (y < aCoord.y) return true;
        if (y > aCoord.y) return false;
        
        return false;
    }

    bool operator != (const Coordinate& aCoord) {
        return x != aCoord.x || y != aCoord.y;
    }
};

#endif