#pragma once

#include "Grid.h"
#include "Point.h"

class Map {
public:
    Map(const unsigned &rowCnt_, const unsigned &colCnt_);
    ~Map();

    /*
    Forbid copy
    */
    Map(const Map &m) = delete;
    Map& operator=(const Map &m) = delete;

    /*
    Return the grid at row x and column y.
    */
    Grid& at(const unsigned &x, const unsigned &y);
    const Grid& at(const unsigned &x, const unsigned &y) const;

    /*
    Check if the point hits the boundary of the map.

    @param p the point to check
    */
    bool hitBoundary(const Point &p) const;

    /*
    Check if the point is inside the map.

    @param p the point to check
    */
    bool isInside(const Point &p) const;

    /*
    Create a food on the map randomly.
    */
    void createFood();

    /*
    Clear food if exists
    */
    void clearFood();

    /*
    Check if there is food on the map.
    */
    bool hasFood() const;

    /*
    Return the count of the rows.
    */
    unsigned getRowCount() const;

    /*
    Return the count of the columns.
    */
    unsigned getColCount() const;

    /*
    Return the food point.
    */
    const Point* getFoodPos() const;

private:
    int rowCnt;
    int colCnt;
    Point *foodPos = nullptr;
    Grid **content = nullptr;

    /*
    Return a random number in [min, max]
    */
    static int random(const int min, const int max);
};
