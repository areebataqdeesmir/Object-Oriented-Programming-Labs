#include "CharterFlight.h"
#include <iostream>
using namespace std;

CharterFlight::CharterFlight(int fn, string o, string d, string dt, int ts, string ch)
    : Flight(fn, o, d, dt, ts) {
    contractHolder = ch;
}

double CharterFlight::calculateBaseFare() {
    return 100000;   // charter cost
}

void CharterFlight::display() {
    cout << "\n===== CHARTER FLIGHT =====";
    cout << "\nContract Holder: " << contractHolder;
    Flight::display();
    cout << "Base Fare: " << calculateBaseFare() << endl;
}

