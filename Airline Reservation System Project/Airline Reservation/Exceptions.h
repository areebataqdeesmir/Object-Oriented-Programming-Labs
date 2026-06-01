#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>
using namespace std;

// ================= BASE EXCEPTION =================
class AirlineException {
public:
    virtual void showMessage() {
        cout << "Airline System Error!" << endl;
    }
};

// ================= FLIGHT EXCEPTIONS =================
class FlightFullException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Flight is FULL!" << endl;
    }
};

class FlightNotFoundException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Flight not found!" << endl;
    }
};

// ================= PASSENGER EXCEPTIONS =================
class PassengerNotFoundException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Passenger not found!" << endl;
    }
};

// ================= BOOKING EXCEPTIONS =================
class AlreadyBookedException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Passenger already booked this flight!" << endl;
    }
};

class BookingFailedException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Booking failed!" << endl;
    }
};

// ================= INPUT EXCEPTION =================
class InvalidInputException : public AirlineException {
public:
    void showMessage() {
        cout << "ERROR: Invalid input entered!" << endl;
    }
};

#endif

