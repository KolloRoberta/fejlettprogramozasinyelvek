//
// Created by Kollo Szende-Roberta on 9/30/2024.
//

#include "Point.h"
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <sstream>

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000) {
        this->x = x;
        this->y = y;
    } else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {///::hatokoroperator
    return x;
}

int Point::getY() const {///csak tagfuggvenynek van ilyen tulajdonsaga
    return y;
}

void Point::print(const string &prefix, const string &preffix) const {
    cout << prefix << "( " << this->x << ", " << this->y << " )" << preffix;
}

double distance(const Point &a, const Point &b) {
    return sqrt(pow(b.getX() - a.getX(), 2) + pow(b.getY() - a.getY(), 2));
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    set<double> set;
    set.insert(distance(a, b));
    set.insert(distance(a, c));
    set.insert(distance(a, d));
    set.insert(distance(b, c));
    set.insert(distance(b, d));
    set.insert(distance(c, d));
    if (set.size() == 1) {
        return true;
    }
    return false;
}

void testIsSquare(const char *filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Helytelen fajl" << endl;
        return;
    }
    string line;
    while (getline(file, line))
        stringstream ss(line);
    int x1, y1, x2, y2, x3, y3, x4, y4;


   // ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;


    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);
    Point d(x4, y4);
    file.close();
}
