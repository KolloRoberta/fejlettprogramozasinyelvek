#include <iostream>

using namespace std;

#include "functions.h"

int main() {

    int x;
    cout << "Valassz egy feladatot: " << endl;
    cin >> x;
    switch (x) {
        case 1: {
            for (int i = 0; i <= 127; ++i) {

                int number = countBits(i);
                cout << number << endl;
            }
            cout << endl;
            break;
        }
        case 2: {
            for (int i = 0; i < 35; ++i) {
                int n = 0;
                if (setBit(n, i)) {
                    cout << i << " ---> " << n << endl;
                } else {
                    cout << "Impossible operation!" << endl;
                }
            }
            break;
        }
        case 3: {
            double array1[] = {2.4, 5.6, 7.8};
            double array2[] = {};
            cout << "AZ array1 tomb atlaga" << " " << mean(array1, 3);
            cout << endl;
            cout << "AZ array2 tomb atlaga" << " " << mean(array2, 0);
            break;
        }
        case 4: {
            double array1[] = {2.4, 5.6, 7.8};
            double array2[] = {};
            cout << "AZ array1 tomb szorasa" << " " << stddev(array1, 3);
            cout << endl;
            cout << "AZ array2 tomb szorasa" << " " << stddev(array2, 0);
            break;
        }

    }


    return 0;
}
