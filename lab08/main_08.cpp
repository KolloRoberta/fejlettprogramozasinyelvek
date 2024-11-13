#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int x;
    cout << "Kerem valasszon feladatot:  ";
    cin >> x;
    switch (x) {
        case 1: {
            /////Határozza meg, hogy van-e olyan gyümölcsnév, amely tartalmaz egy adott karakterláncot? Pl.
            //“berry” (find_if algoritmus)///
            vector<string> fruits{
                    "melon", "strawberry", "raspberry", "apple", "banana", "walnut", "lemon"
            };
            string tartalmazz = "berry";
            auto result = find_if(fruits.begin(), fruits.end(), [tartalmazz](const string &f) {
                return f.find(tartalmazz) != string::npos;
            });
            if (result == fruits.end()) {
                cout << "Nincs" << endl;
            } else {
                cout << "Van : " << *result;
            }
            cout << endl;
            ///irjuk ki az osszes olyan gyumolcsot amely tartalmazza a berry szot///
            vector<string> results;
            copy_if(fruits.begin(), fruits.end(), back_inserter(results), [tartalmazz](const string &f) {
                return f.find(tartalmazz) != string::npos;
            });


            if (result->empty()) {
                cout << "Nincs " << endl;
            } else {
                for (auto &fruit: results) {
                    cout << fruit << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2: {
            ///. Adott egy egész számokat tartalmazó dinamikus tömb. Készítsen kódrészletet, amelyben eldönti,
            //hogy páros-e a tömb minden eleme (all_of algoritmus).////
            vector<int> tomb = {2, 4, 6, 8, 10};
            auto result = all_of(tomb.begin(), tomb.end(), [](int x) {
                return x % 2 == 0;
            });
            if (result) {
                cout << "Az osszes szam paros" << endl;
            } else {
                cout << "Nem paros az osszes szam" << endl;
            }
            break;
        }
        case 3: {
            ///Adott egy egész számokat tartalmazó dinamikus tömb. Készítsen kódrészletet, amelyben
            //megduplázza a tömb minden egyes elemét (for_each algoritmus).///
            vector<int> tomb = {1, 2, 3, 4};
            for_each(tomb.begin(), tomb.end(), [](int &x) {
                x *= 2;
            });
            for_each(tomb.begin(), tomb.end(), [](int &x) {
                cout << x << " ";
            });


            break;
        }

        case 4: {
            ////Adott a következő hónapok neveit tartalmazó tömb. Készítsen kódrészletet, amelyben
            //meghatározza az öt betűből álló hónapok számát.///
            vector<string> months{
                    "January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"
            };

            auto result = count_if(months.begin(), months.end(), [](const string &x) {
                if (x.length() == 5) {
                    return true;
                } else {
                    return false;
                }
            });
            cout << result << endl;


            ////melyek azok a honapok////
            vector<string> r;
            copy_if(months.begin(), months.end(), back_inserter(r), [](const string &x) {
                return x.size() == 5;
            });
            cout << "Ezek az 5 betus honapok: ";
            for (auto &e: r) {
                cout << e << " ";
            }
            cout << endl;
            break;
        }
        case 5: {
            ////Adott egy valós számokat tartalmazó dinamikus tömb. Rendezze a tömböt csökkenő sorrendbe.
            //Az összehasonlító függvényt adja meg kétféleképpen:
            //● Lambda kifejezéssel
            //● Használja a fejállományban deklarált greater<> funktort!////
            ///lambda kifejezes////
            vector<double> tomb = {3.4, 5.6, 7.8};
            sort(tomb.begin(), tomb.end(), [](const double &a, const double &b) {
                return a > b;
            });

            for_each(tomb.begin(), tomb.end(), [](double x) {
                cout << x << " ";
            });

            cout << endl;
            ////greater///ket elemet hasonlit ossze es truet add vissza az elso nagyobb mint a masodik///
            sort(tomb.begin(), tomb.end(), greater<>());

            for (auto &t: tomb) {
                cout << t << " ";
            }
            break;
        }
        case 6: {
            vector<pair<string, double>> honapok = {{"Januar",  2.3},
                                                    {"Februar", -2.3},
                                                    {"Aprilis", 9.3}};
            sort(honapok.begin(), honapok.end(), [](const pair<string, double> &a, const pair<string, double> &b) {
                return a.second < b.second;
            });
            for_each(honapok.begin(), honapok.end(), [](const pair<string, double> &x) {
                cout << x.first << " " << x.second << endl;
            });
            break;
        }
        case 7: {
            ///. Rendezzen egy valós számokat tartalmazó dinamikus tömböt az elemek abszolút értékei szerint
            //növekvő sorrendbe!///
            vector<double> tomb = {-6.7, -7.6, 4.9, 5.5, 433.555};
            sort(tomb.begin(), tomb.end(), [](const double &a, const double &b) {
                return abs(a) < abs(b);
            });

            for_each(tomb.begin(), tomb.end(), [](double &x) {
                cout << abs(x) << " ";
            });
            cout << endl;
            break;
        }
        case 8: {
            ////Alakítsa át a hónapokat tartalmazó tömböt úgy, hogy minden szó kisbetűvel kezdődjön.////
            vector<string> months{
                    "January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"
            };
            for_each(months.begin(), months.end(), [](string &x) {
                x[0] = tolower(x[0]);
            });
            for_each(months.begin(), months.end(), [](string &x) {
                cout << x << " ";
            });
            break;
        }
        case 9: {
            string abc = {"abcdefghijklmnopqrstuvwxzy"};
            random_shuffle(abc.begin(), abc.end());
            for (int i = 0; i < abc.length(); ++i) {
                cout << abc[i] << " ";
            }

            cout << endl;

            vector<string> months{
                    "January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"
            };
            unordered_map<char, int> pozicio;
            for (int i = 0; i < abc.size(); ++i) {
                pozicio[abc[i]] = i;
            }
            sort(months.begin(), months.end(), [&pozicio](const string &a, const string &b) {
                int minimum = min(a.size(), b.size());
                for (int i = 0; i < minimum; ++i) {
                    if (pozicio[a[i]] != pozicio[b[i]]) {
                        return pozicio[a[i]] < pozicio[b[i]];
                    }
                }
                return a.size() < b.size(); ///ha az elso nehany karakter megegyezik a rovidebb kerul elorebb
            });
            for (int i = 0; i < months.size(); ++i) {
                cout << months[i] << " ";
            }
            break;
        }


    }


    return 0;
}