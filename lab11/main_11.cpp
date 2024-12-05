#include <iostream>
#include "SettlementStatistics.h"
#include "SettlementStatisticsImpl.h"
#include "Indexer.h"

using namespace std;

int main() {
    int x;
    cout<<" Choose the exercise : ";
    cin>>x;
    switch (x) {
        case 1:{
            SettlementStatisticsImpl stats("telepulesek.csv");
            cout << " Telepulesek szama " << stats.numSettlements() << endl;
            cout << "Megyek szama: " << stats.numCounties() << endl;

            string keresettMegye = "Alba Iulia";
            cout << keresettMegye << " megyeben levo telepulesek szama: "
                 << stats.numSettlementsByCounty(keresettMegye) << endl;

            string keresettNev = "Aiud";
            Settlement settlement = stats.findSettlementsByNameAndCounty(keresettNev, keresettMegye);
            cout << "Talalt telepules: " << settlement.getName() << " (" << settlement.getPopulation() << ")" << endl;

            Settlement maxPop = stats.maxPopulation();
            cout << "Legnagyobb nepesseg: " << maxPop.getName() << " (" << maxPop.getPopulation() << ")" << endl;

            Settlement minPop = stats.minPopulation();
            cout << "Legkisebb nepesseg: " << minPop.getName() << " (" << minPop.getPopulation() << ")" << endl;
            break;
        }
        case 2:{
            Indexer indexer;

            indexer.proccessFile("bemenet.txt");
            ////index generalasa///

            indexer.generateIndex();
            break;
        }

    }

    return 0;
}