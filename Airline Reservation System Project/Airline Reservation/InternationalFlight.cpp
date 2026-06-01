#include "InternationalFlight.h"
#include <iostream>
using namespace std;

InternationalFlight::InternationalFlight(int fn, string o, string d, string dt, int ts)
    : Flight(fn, o, d, dt, ts) {}

double InternationalFlight::calculateBaseFare() {
    return 20000;   // simple fixed fare
}

void InternationalFlight::display() {
    cout << "\n===== INTERNATIONAL FLIGHT =====";
    cout << "\nVisa Required: YES";
    Flight::display();
    cout << "Base Fare: " << calculateBaseFare() << endl;
}

