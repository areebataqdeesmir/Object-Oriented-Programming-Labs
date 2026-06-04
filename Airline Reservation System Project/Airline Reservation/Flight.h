#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
using namespace std;

// =========================
// ABSTRACT BASE CLASS
// =========================
class Flight {

protected:
    int flightNumber;
    string origin;
    string destination;
    string dateTime;
    int totalSeats;
    int availableSeats;

public:
    Flight(int fn, string o, string d, string dt, int ts);

    // pure virtual function
    virtual double calculateBaseFare() = 0;

    virtual void display();

    // getters (IMPORTANT for search)
    int getFlightNumber();
    string getOrigin();
    string getDestination();
    string getDateTime();

    int getTotalSeats();
    int getAvailableSeats();
    
    void cancelSeat();
    bool hasSeats();
    void bookSeat();
};

#endif


