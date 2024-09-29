#include <iostream>
#include <sstream>

using namespace std;

#include "functions.h"

int main(int argc, char *argv[]) {

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
        case 5: {
            double arr[] = {1.5, 3.2, 7.4, 6.8, 2.1};
            int n = sizeof(arr) / sizeof(arr[0]);


            pair<double, double> result = max2(arr, n);


            cout << "A ket legnagyobb elem: " << result.first << " " << result.second << endl;
            break;
        }
            ////STRINGES FELADATOK////
        case 6: {
            /* istringstream  inputstream("1 2 3 alma 4");
             string word;
             while(inputstream >> word)
             {
                 istringstream  wordstream(word);
                 double number;
                 if(wordstream >>  number)
                 {
                     cout<<  word << ": NUMERICAL"<<endl;
                 }
                 else {
                     cout << word << ": TEXTUAL" << endl;
                 }
             }*/

            string text = "1 2 3 alma 4";
            int number = countWords(text);
            cout << number;
            break;
        }
        case 7: {
            string text = "Ma nagyon erossen esik az eso";
            int number = countWords2(text);
            cout << number;
            break;
        }
        case 8: {
            string szoveg = "Hello Nagy Vilag";
            cout << endl;


            string kodolt = code(szoveg);
            cout << "KODOLT: " << kodolt << endl;


            string dekodolt = decode(kodolt);
            cout << "DEKODOLT: " << dekodolt << endl;
            break;
        }
        case 9:{
            string sor;
            while(getline(cin, sor))
            {
                if(sor == "vege")
                {
                    break;
                }
                cout << capitalizeWords(sor) <<endl;
            }
            break;
        }
        default:
            cout << "ILYEN FELADAT NEM LETEZIK";

    }


    return 0;
}
