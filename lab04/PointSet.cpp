//
// Created by Kollo Szende-Roberta on 10/14/2024.
//

#include "PointSet.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <random>
bool exists[M+1][M+1]{false};

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i+1; j < points.size(); ++j) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

PointSet::PointSet(int n):n{n} {
    while(points.size() < n){
        int x = rand() % (M+1);
        int y = rand() % (M+1);
        if(exists[x][y] == false){
            points.push_back(Point(x,y));
            exists[x][y]= true;
        }
    }
    computeDistances();
    for (int i = 0; i <= M; ++i) {
        for (int j = 0; j <= M; ++j) {
            exists[i][j] = false;
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    for (auto& p:points) {
        cout << "X: " << p.getX() << "Y: " << p.getY() << endl;
    }
}

void PointSet::printDistances() const {
    for (auto& ps:distances) {
        cout << ps << endl;
    }
}

bool cmpX(const Point &a, const Point &b){
    return a.getX() < b.getX();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), cmpX);
}

bool cmpY(const Point &a, const Point &b){
    return a.getY() < b.getY();
}
void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), cmpY);
}

int PointSet::numDistinctDistances() {
    set<double> d (distances.begin(), distances.end());
    return d.size();
}




