#include <iostream>
#include "Point.h"

using namespace std;
int main(int argc, char** argv) {
    /*Point p1(2,2);
    p1.print("p1","\n");
    Point p2(2, 2);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    cout<<"Ket pont tavolsaga: "<<distance(p1,p2) <<endl;
    bool result = isSquare(p1.getX(),p1.getY(),p2.getX(),p2.getY());
    cout << "Negyzet-e: "<< result << endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;*/


    int x;
    cout<<"Kerem valasszon feladatot: ";
    cin>>x;
    switch (x) {
        case 6:{
            ///exercise 6////
            testIsSquare("points.txt");
            break;
        }
        case 7:{
            int N;
            cout<<"Kerem a pontok szamat: ";
            cin>>N;
            ///a tomb letrehozasa
            Point *points = createArray(N);
            printArray(points,N);
            delete[]points;
            break;
        }
        case 9:{
            int N;
            cout<<"Kerem a pontok szamat: ";
            cin>>N;

            Point *points = createArray(N);
            pair<Point,Point> closest = closestPoints(points,N);
            printArray(points,N);
            cout << "A legkozelebbi pontpar: ";
            closest.first.print("", " es");
            closest.second.print("", "\n");
            delete[] points;
            break;
        }
        case 10 :{
            int N;
            cout<<"Kerem a pontokat";
            cin>>N;

            Point *points = createArray(N);
            pair<Point, Point> maxim = farthestPoints(points, N);
            printArray(points,N);
            cout<<"A legtabolibb pontok: ";
            maxim.first.print("", " es ");
            maxim.second.print("", "\n");
            deletePoints(points);
            break;
        }
        case 11:{
            int N;
            cout<<"Kerem a pontokat";
            cin>>N;
            Point *points = createArray(N);
            printArray(points, N);
            cout<<endl;
            sortPoints(points, N);
            cout<<endl;
            printArray(points, N);
            deletePoints(points);
            break;
        }
        default:
            cout<<"Ilyen feladat nem letezik";
    }

    return 0;
    ////cout = karakter output, standard bemenet
    ////<< = operator
    ///cout << x ;  out = ostream << operator  x = kifejezes

}

