#ifndef AIRLINE_H
#define AIRLINE_H

#include "Flight.h"
#include "Passenger.h"
#include "Ticket.h"
#include "Exceptions.h"
#include <string>

using namespace std;

class Airline {

private:
Flight* flights[100];
Passenger* passengers[100];
Ticket* tickets[100];

int fCount;  
int pCount;  
int tCount;
 
public:
Airline();

// FLIGHTS  
void addFlight(Flight*);  
void removeFlight(int);  
void listFlights();  
void searchByFlightNumber(int);  
void searchByRoute(string, string);  
void searchByDate(string);  

// PASSENGERS  
void registerPassenger(Passenger*);  
void viewPassenger(int);  
void viewBookingHistory(int);  

// BOOKING  
void bookTicket(int, int, int);  
void cancelTicket(int);  

// REPORTS  
void todaysDepartures();  
void occupancyReport();  
void topRevenueFlights();  

// FILE  
void saveData();  
void loadData();  

// MENU  
void menu();

};

#endif

