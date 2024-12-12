#include <iostream>
#include "EvesKiadas.h"
#include "Eremtablazat.h"
#include "SimpleTextGenerator.h"

using namespace std;

int main() {
    int x;
    cout << "Valassz feladatot: ";
    cin >> x;
    switch (x) {
        case 1: {
            EvesKiadas evesKiadas("be.txt");
            //evesKiadas.listazas();
            evesKiadas.ujKiadas("Szeptember", "lakber", 400);
            evesKiadas.listazas();

            auto kategoria = evesKiadas.kiadasiKategoriak();
            for (const auto &k: kategoria) {
                cout << k << " " << endl;
            }

            cout << endl;
            evesKiadas.kategoriankentiAtlagKiadas();
            break;
        }
        case 2: {
            Eremtablazat eremtablazat("in.txt");
            eremtablazat.listazas();
            auto sportolok = eremtablazat.sportolok();
            for (const auto &temp: sportolok) {
                cout << temp << " ";
            }

            break;
        }
        case 3: {
            SimpleTextGenerator generator;
            string text = "Now is not the time for sleep, now is the time for party!";
            generator.trainFromText(text);
            generator.printData();
            for (int i = 0; i < 3; ++i) {
                cout << "Generated text: " << generator.generate("now is", 6) << endl;
            }
            generator.printData();
            cout << "FILEBOL";
            cout << endl;
            generator.trainFromFile("words.txt");
            generator.printData();
            break;
        }
    }


    return 0;
}