#include <iostream>
#include "Airline.h"

using namespace std;

int main() {

    Airline system;

    system.loadData();   // startup restore (if file exists)

    cout << "\n===== AIRLINE SYSTEM STARTED =====\n";

    system.menu();       // main menu

    system.saveData();   // exit save

    cout << "\n===== SYSTEM CLOSED =====\n";
    

    return 0;
}

