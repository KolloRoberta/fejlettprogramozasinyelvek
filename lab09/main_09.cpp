#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

void testManager();

void testAlkalmazott();

void testSzemely();

using namespace std;

int main() {
/*    testSzemely();
    testAlkalmazott();
    testManager();*/

    Ceg ceg;

    // 2. Hire 10 people, 3 of them should be managers

    Manager *manager1 = new Manager("Kovacs", "Anna", 1975);
    Manager *manager2 = new Manager("Szabo", "Peter", 1980);
    Manager *manager3 = new Manager("Nagy", "Eva", 1985);

    ceg.alkalmaz(manager1);
    ceg.alkalmaz(manager2);
    ceg.alkalmaz(manager3);

    // Hire 7 non-manager employees
    for (int i = 1; i <= 7; ++i) {
        ceg.alkalmaz(
                new Alkalmazott("Vezetek" + std::to_string(i), "Kereszt" + std::to_string(i), 1990 + i, "developer"));
    }
    // 3. List all employees
    std::cout << "\n--- All employees ---\n";
    ceg.listazOsszesAlkalmazott();

    // 4. Assign each of the 7 non-manager employees to a random manager
    std::cout << "\n--- Assigning employees to managers ---\n";
    for (int i = 1; i <= 7; ++i) {
        if (i % 3 == 1) {
            ceg.hozzarendelManagerhez(i, manager1); // 1st manager
        } else if (i % 3 == 2) {
            ceg.hozzarendelManagerhez(i, manager2); // 2nd manager
        } else {
            ceg.hozzarendelManagerhez(i, manager3); // 3rd manager
        }
    }

    // 5. List only the manager type employees
    std::cout << "\n--- Only managers ---\n";
    ceg.listazManager();

    // 6. Move one employee from one manager to another
    std::cout << "\n--- Moving an employee between managers ---\n";
    ceg.levalasztManagerrol(3, manager1); // Unassign from the first manager
    ceg.hozzarendelManagerhez(3, manager2); // Reassign to the second manager

    // 7. List only the manager type employees again
    std::cout << "\n--- Only managers after move ---\n";
    ceg.listazManager();
    return 0;
}


void testManager() {
    std::cout << "\n--- Manager osztály teszt ---\n";

    Manager manager1("Kiss", "Bela", 1980);
    Manager manager2("Farkas", "Janos", 1983);

    Alkalmazott alkalmazott1("Toth", "Gabor", 1992, "fejleszto");
    Alkalmazott alkalmazott2("Nagy", "Erika", 1995, "tesztelo");
    Alkalmazott alkalmazott3("Horvath", "Zoltan", 1997, "adminisztrator");

    manager1.addAlkalmazaott(&alkalmazott1);
    manager1.addAlkalmazaott(&alkalmazott2);
    manager2.addAlkalmazaott(&alkalmazott3);

    std::cout << "Manager 1:\n" << manager1 << "\n";
    std::cout << "Manager 2:\n" << manager2 << "\n";

    std::cout << "Manager 1: Alkalmazott törlése (ID: 1)\n";
    manager1.deleteAlkalmazott(1);
    std::cout << "Manager 1 frissítve:\n" << manager1 << "\n";
}

void testAlkalmazott() {
    std::cout << "\n--- Alkalmazott osztály teszt ---\n";

    Alkalmazott alkalmazott1("Toth", "Gabor", 1992, "fejleszto");
    Alkalmazott alkalmazott2("Nagy", "Erika", 1995, "tesztelo");

    std::cout << "Alkalmazott 1: " << alkalmazott1 << "\n";
    std::cout << "Alkalmazott 2: " << alkalmazott2 << "\n";
    std::cout << "Alkalmazott 1 ID: " << alkalmazott1.getId() << "\n";
    std::cout << "Alkalmazott 2 ID: " << alkalmazott2.getId() << "\n";
}

void testSzemely() {
    std::cout << "\n--- Személy osztály teszt ---\n";

    Szemely szemely1("Kovacs", "Anna", 1985);
    Szemely szemely2("Szabo", "Peter", 1990);

    std::cout << "Személy 1: " << szemely1 << "\n";
    std::cout << "Személy 2: " << szemely2 << "\n";
}
