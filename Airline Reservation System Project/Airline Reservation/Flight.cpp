#include "Flight.h"

// ================= CONSTRUCTOR =================
Flight::Flight(int fn, string o, string d, string dt, int ts) {
    flightNumber = fn;
    origin = o;
    destination = d;
    dateTime = dt;
    totalSeats = ts;
    availableSeats = ts;
}

// ================= DISPLAY =================
void Flight::display() {
    cout << "\n------------------------";
    cout << "\nFlight No: " << flightNumber;
    cout << "\nFrom: " << origin;
    cout << "\nTo: " << destination;
    cout << "\nDate/Time: " << dateTime;
    cout << "\nSeats: " << availableSeats << "/" << totalSeats;
    cout << "\n------------------------\n";
}

// ================= GETTERS =================
int Flight::getFlightNumber() {
    return flightNumber;
}

string Flight::getOrigin() {
    return origin;
}

string Flight::getDestination() {
    return destination;
}

string Flight::getDateTime() {
    return dateTime;
}

int Flight::getTotalSeats() {
    return totalSeats;
}

int Flight::getAvailableSeats() {
    return availableSeats;
}

// ================= SEAT MANAGEMENT =================
bool Flight::hasSeats() {
    return availableSeats > 0;
}

void Flight::cancelSeat(){
	availableSeats++;
}

void Flight::bookSeat() {
    if (availableSeats > 0)
        availableSeats--;
}

