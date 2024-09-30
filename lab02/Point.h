//
// Created by Kollo Szende-Roberta on 9/30/2024.
//

#ifndef LAB2_POINT_H
#define LAB2_POINT_H
#include <iostream>
#include <string>
using namespace std;
class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);///implicit kezdoertek
    int getX() const;///amelyek nem valtoztatjak az objektum allapotat, a geterek altal
    int getY() const;
    void print(const string &prefix, const string &preffix = "") const;

};
double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
#endif //LAB2_POINT_H
