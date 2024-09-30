#include <iostream>
#include "Point.h"

using namespace std;
int main(int argc, char** argv) {
    Point p1(2,2);
    p1.print("p1","\n");
    Point p2(2, 2);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    cout<<"Ket pont taolsaga: "<<distance(p1,p2) <<endl;
    bool result = isSquare(p1.getX(),p1.getY(),p2.getX(),p2.getY());
    cout << "Negyzet-e: "<< result << endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;



    ///exercise 6////

    return 0;
    ////cout = karakter output, standard bemenet
    ////<< = operator
    ///cout << x ;  out = ostream << operator  x = kifejezes

}

