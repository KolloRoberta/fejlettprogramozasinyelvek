//
// Created by Kollo Szende-Roberta on 9/30/2024.
//

#include "Point.h"
#include <iostream>
#include <cmath>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>

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
    string line;///egy-egy fajlsort fog tarolni
    while (getline(file, line)) {
        stringstream ss(line);
        int x1, y1, x2, y2, x3, y3, x4, y4;

        // Olvassa be a sorban található pontokat
        ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

        Point a(x1, y1);
        Point b(x2, y2);
        Point c(x3, y3);
        Point d(x4, y4);


        cout << "Pontok: ";
        a.print("", ", ");
        b.print("", ", ");
        c.print("", ", ");
        d.print("", " -> ");

        if (isSquare(a, b, c, d)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

Point *createArray(int numPoints) {
    Point *points = new Point[numPoints];
    if (!points) {
        cout << "Helytelen memoria foglalas";
        exit(EXIT_FAILURE);
    }
    ///veletlenszam generalas///
    //srand(static_cast<unsigned int>(time (NULL)));
    srand(time(NULL));
    for (int i = 0; i < numPoints; ++i) {
        int x = rand() % 2001;
        int y = rand() % 2001;
        points[i] = Point(x, y); ///pont letrehozasa es elhelyezese a tombben
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; ++i) {
        cout << "Pont" << i + 1 << " : ";
        points[i].print("", "\n");
    }

}

pair<Point, Point> closestPoints(Point *points, int numPoints) {
    if (numPoints < 2) {
        cout << "Nem jo";
    }
    double minDistance = INT_MAX;
    pair<Point, Point> closestPair;///eltarolja azt a ket pontot amelyek egymashoz legkozelebb vannak
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j < numPoints; ++j) {
            double dist = distance(points[i], points[j]);
            if(dist < minDistance)
            {
                minDistance =  dist;
                closestPair = make_pair(points[i], points[j]);
            }
        }
    }

    return closestPair;
}

void deletePoints(Point *points) {
    delete[] points;
}

pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    if(numPoints < 2)
    {
        cout<<"Ez helytelen";
        exit(EXIT_FAILURE);
    }
    double  max = INT_MIN;
    pair<Point, Point> maximum;
    for (int i = 0; i < numPoints; ++i) {
        for (int j = i+1; j <numPoints ; ++j) {
            double dis = distance(points[i], points[j]);
            if(dis >  max)
            {
                max = dis;
                maximum = make_pair(points[i], points[j]);
            }
        }
    }
    return maximum;
}

void sortPoints(Point *points, int numPoints) {
    sort(points,points+ numPoints, compareByx);
}

int compareByx(const Point &a, const Point &b) {
    return a.getX() < b.getX();
}
