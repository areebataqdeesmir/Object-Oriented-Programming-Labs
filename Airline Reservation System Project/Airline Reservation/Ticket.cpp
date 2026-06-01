#include "Ticket.h"

// ================= CONSTRUCTOR =================
Ticket::Ticket(int tid, Passenger* p, Flight* f, int seat, double fare) {
    ticketID = tid;
    passenger = p;
    flight = f;
    seatNumber = seat;
    farePaid = fare;
    status = "Booked";
}

// ================= GETTERS =================
int Ticket::getTicketID() {
    return ticketID;
}

Passenger* Ticket::getPassenger() {
    return passenger;
}

Flight* Ticket::getFlight() {
    return flight;
}

string Ticket::getStatus() {
    return status;
}

// ================= CANCEL =================
void Ticket::cancelTicket() {
    status = "Cancelled";

    cout << "Ticket Cancelled Successfully!\n";
}

// ================= DISPLAY =================
void Ticket::display() {
    cout << "\n========== TICKET ==========";
    cout << "\nTicket ID: " << ticketID;
    cout << "\nPassenger: " << passenger->getName();
    cout << "\nFlight No: " << flight->getFlightNumber();
    cout << "\nSeat No: " << seatNumber;
    cout << "\nFare Paid: " << farePaid;
    cout << "\nStatus: " << status;
    cout << "\n============================\n";
}
bool Ticket::operator==(const Ticket &t) {
    return ticketID == t.ticketID;
}

