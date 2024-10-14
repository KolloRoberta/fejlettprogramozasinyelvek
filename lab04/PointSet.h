//
// Created by Kollo Szende-Roberta on 10/14/2024.
//

#ifndef LAB4_POINTSET_H
#define LAB4_POINTSET_H

#include "Point.h"
#include <vector>

using namespace std;

class PointSet {
    ////kulonbozo pontok
    vector<Point> points;
    ///kulonbozo pontok szama
    int n;
    ///pontok kozotti tavolsag
    vector<double> distances;

    ///segedfuggveny, amely feltolti a distance tombot
    void computeDistances();

public:
    //konstruktor: előállítja a points tömböt
//kiszámítja a pontok közötti távolságokat (tavolsagok tömb),
    PointSet(int n = 100);

//maximum kiválasztás a tavolsag tömbből
    double maxDistance() const;

//minimum kiválasztás a tavolsag tömbből
    double minDistance() const;

//összesen hány távolság értelmezhető n
//különböző pont között
    int numDistances() const;

//a pontok tároló kiíratása
    void printPoints() const;

//a tavolsagok tároló kiíratása
    void printDistances() const;

//növekvő sorrendbe rendezi a pontokat x koordináta szerint
    void sortPointsX();

//u. a. y koordináta szerint
    void sortPointsY();

//a tavolsagok tároló rendezése
    void sortDistances();

//hány darab különböző távolságot tartalmaz a tavolsagok tömb
    int numDistinctDistances();

};


#endif //LAB4_POINTSET_H
