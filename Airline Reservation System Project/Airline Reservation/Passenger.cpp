#include "Passenger.h"

Passenger::Passenger(int id, string n) {
    passengerID = id;
    name = n;
    hCount = 0;
}

int Passenger::getID() {
    return passengerID;
}

string Passenger::getName() {
    return name;
}

void Passenger::addHistory(string h) {
    history[hCount++] = h;
}

void Passenger::showHistory() {
    cout << "\n===== BOOKING HISTORY =====\n";

    if(hCount == 0){
        cout << "No bookings yet!\n";
        return;
    }

    for(int i=0;i<hCount;i++)
        cout << history[i] << endl;
}

void Passenger::display() {
    cout << "\nPassenger ID: " << passengerID;
    cout << "\nName: " << name << endl;
}

