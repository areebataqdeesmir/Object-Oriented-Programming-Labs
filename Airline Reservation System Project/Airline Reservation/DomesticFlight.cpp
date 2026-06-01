#include "DomesticFlight.h"
#include <iostream>
using namespace std;

DomesticFlight::DomesticFlight(int fn, string o, string d, string dt, int ts)
    : Flight(fn, o, d, dt, ts) {}

double DomesticFlight::calculateBaseFare() {
    return 5000;   // simple fixed fare
}

void DomesticFlight::display() {
    cout << "\n===== DOMESTIC FLIGHT =====";
    Flight::display();
    cout << "Base Fare: " << calculateBaseFare() << endl;
}


