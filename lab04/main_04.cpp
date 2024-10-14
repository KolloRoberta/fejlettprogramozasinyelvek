#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include "PointSet.h"
#include "Point.h"
#define MAX 1000
using namespace std;

int main() {
    int x;
    cout<<"Kerem valasszon feladatot: ";
    cin>>x;
    switch (x) {
        case 1:{
            Point point1(3,4);
            Point point2 (5,6);
            double disttance = point1.distanceTo(point2);
            cout<< disttance << endl;
            break;
        }
        case 2:{
            int n = 2;
            cout<<"Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok"<<endl;
            cout<< fixed;
            for( int i= 0; i<12; ++i ){
                PointSet pSet( n );
                cout<<setw(6)<<n<<" ";
                cout<<setw(8)<<setprecision(2)<<pSet.minDistance()<<" ";
                cout<<setw(8)<<setprecision(2)<<pSet.maxDistance()<<" ";
                cout<<setw(10) << pSet.numDistances()<<" ";
                //cout<<endl;
                cout<<setw(16) << pSet.numDistinctDistances()<<endl;
                n = n << 1;
            }
            break;

        }
        default:cout<<"ILYEN FELADAT NINCS";
    }


    return 0;
}