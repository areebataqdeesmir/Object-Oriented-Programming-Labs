#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "Passenger.h"
#include "Flight.h"
using namespace std;

// =======================
// TICKET CLASS
// =======================
class Ticket {

private:
    int ticketID;
    Passenger* passenger;
    Flight* flight;

    int seatNumber;
    double farePaid;
    string status;   // Booked / Cancelled

public:
    Ticket(int tid, Passenger* p, Flight* f, int seat, double fare);
  bool operator==(const Ticket &t);
    int getTicketID();
    Passenger* getPassenger();
    Flight* getFlight();

    void cancelTicket();
    string getStatus();

    void display();
};

#endif


