//
// Created by Kollo Szende-Roberta on 10/14/2024.
//

#include <valarray>
#include "Point.h"

Point::Point(int x, int y) : x(x), y(y) {}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    int dx = x - point.getX();
    int dy = y - point.getY();
    return sqrt(dx * dx + dy * dy);
}
