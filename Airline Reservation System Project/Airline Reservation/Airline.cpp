#include "Airline.h"

// Flights
#include "DomesticFlight.h"
#include "CharterFlight.h"
#include "InternationalFlight.h"

// Passengers
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"
#include "FirstClassPassenger.h"

// Core
#include "Ticket.h"
#include "Flight.h"
#include "Passenger.h"
#include "Exceptions.h"

#include <iostream>
#include <fstream>

using namespace std;
template <class T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

// ================= CONSTRUCTOR =================
// ================= CONSTRUCTOR =================
Airline::Airline() {

    fCount = 0;
    pCount = 0;
    tCount = 0;

    for (int i = 0; i < 100; i++) {
        passengers[i] = NULL;
        tickets[i] = NULL;
        flights[i] = NULL;
    }

    flights[fCount++] =
        new DomesticFlight(101, "Quetta", "Lahore", "2026-06-01", 50);

    flights[fCount++] =
        new CharterFlight(202, "Karachi", "Dubai", "2026-06-05", 40, "Owner");

    flights[fCount++] =
        new InternationalFlight(303, "Islamabad", "London", "2026-06-10", 60);
}
// ================= FLIGHTS =================
void Airline::addFlight(Flight* f) {

    if (fCount < 50) {
        flights[fCount++] = f;

    }
}

void Airline::removeFlight(int id) {
for (int i = 0; i < fCount; i++) {
if (flights[i]->getFlightNumber() == id) {

for (int j = i; j < fCount - 1; j++)  
            flights[j] = flights[j + 1];  

        fCount--;  
        cout << "Flight removed successfully\n";  
        return;  
    }  
}  
cout << "No such flight registered\n";

}

void Airline::listFlights() {
if (fCount == 0) {
cout << "No flights available\n";
return;
}

for (int i = 0; i < fCount; i++)  
    flights[i]->display();

}

// ================= SEARCH =================
void Airline::searchByFlightNumber(int id) {
for (int i = 0; i < fCount; i++) {
if (flights[i]->getFlightNumber() == id) {
flights[i]->display();
return;
}
}
cout << "Flight Not Found\n";
}

void Airline::searchByRoute(string o, string d) {
bool found = false;

for (int i = 0; i < fCount; i++) {  
    if (flights[i]->getOrigin() == o &&  
        flights[i]->getDestination() == d) {  
        flights[i]->display();  
        found = true;  
    }  
}  

if (!found) cout << "No flights found\n";

}

void Airline::searchByDate(string date) {
bool found = false;

for (int i = 0; i < fCount; i++) {  
    if (flights[i]->getDateTime() == date) {  
        flights[i]->display();  
        found = true;  
    }  
}  

if (!found) cout << "No flights found\n";

}

// ================= PASSENGERS =================
void Airline::registerPassenger(Passenger* p) {
if (pCount < 50)
passengers[pCount++] = p;
}

void Airline::viewPassenger(int id) {

if (id == -1) {  
    if (pCount == 0) {  
        cout << "No passengers available\n";  
        return;  
    }  

    cout << "\n--- ALL PASSENGERS ---\n";  
    for (int i = 0; i < pCount; i++)  
        passengers[i]->display();  

    return;  
}  

for (int i = 0; i < pCount; i++) {  
    if (passengers[i]->getID() == id) {  
        passengers[i]->display();  
        return;  
    }  
}  

cout << "Passenger Not Found\n";

}

void Airline::viewBookingHistory(int id) {
for (int i = 0; i < pCount; i++) {
if (passengers[i]->getID() == id) {
passengers[i]->showHistory();
return;
}
}
cout << "Passenger Not Found\n";
}

bool Airline::bookTicket(int tid, int pid, int fid) {

    Flight* f = NULL;
    Passenger* p = NULL;

    // find passenger
    for (int i = 0; i < pCount; i++) {
        if (passengers[i] != NULL && passengers[i]->getID() == pid) {
            p = passengers[i];
            break;
        }
    }

    // find flight
    for (int i = 0; i < fCount; i++) {
        if (flights[i] != NULL && flights[i]->getFlightNumber() == fid) {
            f = flights[i];
            break;
        }
    }

    // INVALID checks
    if (p == NULL) {
        cout << "Invalid Passenger ID\n";
        return false;
    }

    if (f == NULL) {
        cout << "Invalid Flight ID\n";
        return false;
    }

    if (!f->hasSeats()) {
        cout << "Flight Full\n";
        return false;
    }

    // duplicate booking check
    for (int i = 0; i < tCount; i++) {

        if (tickets[i] != NULL &&
            tickets[i]->getPassenger() != NULL &&
            tickets[i]->getFlight() != NULL &&
            tickets[i]->getPassenger()->getID() == pid &&
            tickets[i]->getFlight()->getFlightNumber() == fid) {

            cout << "Already Booked\n";
            return false;
        }
    }

    // booking
    f->bookSeat();

    int seat = f->getTotalSeats() - f->getAvailableSeats();

    tickets[tCount++] = new Ticket(tid, p, f, seat, 1000);

    p->addHistory("Booked Flight");

    return true;
}

// ================= CANCEL =================
void Airline::cancelTicket(int tid) {

    bool found = false;

    for (int i = 0; i < tCount; i++) {

        if (tickets[i] != NULL &&
            tickets[i]->getTicketID() == tid) {

            found = true;

            double fare = 1000;

            Passenger* p = tickets[i]->getPassenger();
            Flight* f = tickets[i]->getFlight();

            double refundPercent = p->refundPercentage();
            double refundAmount = (fare * refundPercent) / 100;

            // 🔴 IMPORTANT FIX: seat restore
            f->cancelSeat();

            tickets[i]->cancelTicket();
            p->addHistory("Cancelled Ticket");

            cout << "\n=================================\n";
            cout << "        TICKET CANCELLED        \n";
            cout << "=================================\n";

            cout << "Ticket ID        : " << tid << endl;
            cout << "Refund Percent   : " << refundPercent << "%\n";
            cout << "Refund Amount    : Rs. " << refundAmount << endl;

            cout << "=================================\n";

            return;
        }
    }

    if (!found) {
        cout << "Ticket Not Found\n";
    }
}
// ================= REPORTS =================
void Airline::todaysDepartures() {
cout << "\n--- TODAY'S FLIGHTS ---\n";
listFlights();
}

void Airline::occupancyReport() {
cout << "\n--- OCCUPANCY REPORT ---\n";

for (int i = 0; i < fCount; i++) {  
    cout << "Flight " << flights[i]->getFlightNumber()  
         << " : "  
         << (flights[i]->getTotalSeats() - flights[i]->getAvailableSeats())  
         << "/" << flights[i]->getTotalSeats() << endl;  
}

}

void Airline::topRevenueFlights() {

    cout << "\n=====================================\n";
    cout << "       TOP REVENUE FLIGHTS REPORT\n";
    cout << "=====================================\n";

    if (fCount == 0) {
        cout << "No Flights Available\n";
        return;
    }

    for (int i = 0; i < fCount; i++) {

        int bookedSeats =
            flights[i]->getTotalSeats() -
            flights[i]->getAvailableSeats();

        int revenue = bookedSeats * 1000;

        cout << "\nFlight ID      : "
             << flights[i]->getFlightNumber() << endl;

        cout << "Booked Seats   : "
             << bookedSeats << endl;

        cout << "Total Revenue  : Rs. 5000"
             << revenue << endl;

        cout << "-------------------------------------\n";
    }

    cout << "End of Revenue Report\n";
    cout << "=====================================\n";
}
// ================= SAVE / LOAD =================
void Airline::saveData() {
ofstream f("data.txt");
f << fCount << " " << pCount << " " << tCount;
}

void Airline::loadData() {
ifstream f("data.txt");
if (!f) return;
f >> fCount >> pCount >> tCount;
}

// ================= MENU =================
void Airline::menu() {

int ch;  

do {  
    cout << "\n===== AIRLINE MENU =====\n";  
    cout << "1. Add Flight\n";  
    cout << "2. Remove Flight\n";  
    cout << "3. Search/List Flights\n";  
    cout << "4. Register Passenger\n";  
    cout << "5. View Passenger\n";  
    cout << "6. Book Ticket\n";  
    cout << "7. Cancel Ticket\n";  
    cout << "8. Booking History\n";  
    cout << "9. Reports\n";  
    cout << "!0. Exit\n";  

    cout << "Enter choice: ";  
    cin >> ch;  

    switch (ch) {  

   case 1: {

    int id, seats, type;
    string o, d, dt;

    // ===== Flight Number =====
    cout << "Enter Flight Number: ";
    cin >> id;

    if (cin.fail() || id <= 0) {
        cout << "Invalid Flight Number (digits only)\n";
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
    }

    // ===== Origin =====
    cout << "Enter Origin: ";
    cin >> o;

    bool valid = true;
    for (char c : o) {
        if (!isalpha(c)) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "Invalid Origin (alphabets only)\n";
        break;
    }

    // ===== Destination =====
    cout << "Enter Destination: ";
    cin >> d;

    valid = true;
    for (char c : d) {
        if (!isalpha(c)) {
            valid = false;
            break;
        }
    }

    if (!valid) {
        cout << "Invalid Destination (alphabets only)\n";
        break;
    }

    // ===== Date =====
    cout << "Enter Date (YYYY-MM-DD): ";
cin >> dt;

valid = true;

// format check first
if (dt.length() != 10 || dt[4] != '-' || dt[7] != '-') {
    cout << "Invalid Date format\n";
    break;
}

// check only digits except '-'
for (char c : dt) {
    if (!(isdigit(c) || c == '-')) {
        valid = false;
        break;
    }
}

if (!valid) {
    cout << "Invalid Date format\n";
    break;
}

// ===== YEAR CHECK WITHOUT stoi =====
int year = (dt[0] - '0') * 1000 +
           (dt[1] - '0') * 100 +
           (dt[2] - '0') * 10 +
           (dt[3] - '0');

if (year < 2026) {
    cout << "Invalid Date! Only 2026 or future bookings allowed\n";
    break;
}

    if (!valid) {
        cout << "Invalid Date format\n";
        break;
    }

    // ===== Seats =====
    cout << "Enter Seats: ";
    cin >> seats;

    if (cin.fail() || seats <= 0) {
        cout << "Invalid Seats (numbers only)\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    // ===== Type =====
    cout << "Enter Type (1.Domestic 2.Charter 3.International): ";
    cin >> type;

    if (type < 1 || type > 3) {
        cout << "Invalid Type\n";
        break;
    }

    // ===== Add Flight =====
    if (type == 1)
        addFlight(new DomesticFlight(id, o, d, dt, seats));
    else if (type == 2)
        addFlight(new CharterFlight(id, o, d, dt, seats, "Owner"));
    else
        addFlight(new InternationalFlight(id, o, d, dt, seats));

   cout << "\n====================================\n";
cout << "             FLIGHT CREATED              \n";
cout << "====================================\n";

cout << " Flight Number : " << id << endl;
cout << " Origin         : " << o << endl;
cout << " Destination    : " << d << endl;
cout << " Date           : " << dt << endl;
cout << " Seats          : " << seats << endl;

cout << " Type           : ";
if (type == 1) cout << "Domestic\n";
else if (type == 2) cout << "Charter\n";
else cout << "International\n";

cout << "------------------------------------\n";
cout << "       Flight Added Successfully  \n";
cout << "====================================\n";
    break;
} 

case 2: {

    int id;
    cout << "Enter Flight ID to Remove: ";
    cin >> id;

    if (cin.fail()) {
        cout << "Invalid Input\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    bool found = false;

    for (int i = 0; i < fCount; i++) {
        if (flights[i]->getFlightNumber() == id) {

            for (int j = i; j < fCount - 1; j++) {
                flights[j] = flights[j + 1];
            }

            fCount--;
            found = true;
            cout << "Flight " << id << " removed successfully\n";
            break;
        }
    }

    if (!found)
        cout << "No flight found\n";

    break;
}
case 3: {


    int opt;
    cout << "\n1. Search Flight\n2. List Flights\n";
    cin >> opt;

    if (opt == 1) {

        int id;
        cout << "Enter Flight ID: ";
        cin >> id;

        bool found = false;

        for (int i = 0; i < fCount; i++) {
            if (flights[i]->getFlightNumber() == id) {
                flights[i]->display();
                found = true;
                break;
            }
        }

        if (!found)
            cout << "No Flight Found\n";
    }

    else if (opt == 2) {

        if (fCount == 0)
            cout << "No Flights Available\n";
        else {
            for (int i = 0; i < fCount; i++)
                flights[i]->display();
        }
    }

    break;
}

case 4: {

    int id, type;
    string name;

    cout << "Enter Passenger ID: ";
    cin >> id;

    if (cin.fail() || id <= 0) {
        cout << "Invalid ID (must be positive number)\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }
cout << "Enter Name: ";
cin >> ws;
getline(cin, name);

if (name.empty()) {
    cout << "Invalid Name\n";
    break;
}

bool validName = true;

for (char c : name) {
    if (!isalpha(c) && c != ' ') {
        validName = false;
        break;
    }
}

if (!validName) {
    cout << "Invalid Name (only alphabets allowed)\n";
    break;
}
cout << "Enter Type (1.Economy 2.Business 3.FirstClass): ";
cin >> type;
if(type < 1 || type > 3){
    cout << "Invalid Type\n";
    break;
}
    if (type == 1)
        registerPassenger(new EconomyPassenger(id, name));
    else if (type == 2)
        registerPassenger(new BusinessPassenger(id, name));
    else
        registerPassenger(new FirstClassPassenger(id, name));

    cout << "\nPassenger Registered Successfully\n";
    break;
}
case 5: {

    int id;
    cout << "Enter Passenger ID: ";
    cin >> id;

    if (cin.fail()) {
        cout << "Invalid Input\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    if (pCount == 0) {
        cout << "No Passenger Registered\n";
        break;
    }

    bool found = false;

    for (int i = 0; i < pCount; i++) {

        if (passengers[i] != NULL &&
            passengers[i]->getID() == id) {

            passengers[i]->display();

            cout << "\nPassenger Found\n";

            found = true;
            break;
        }
    }

    if (!found)
        cout << "Passenger Not Found\n";

    break;
}

case 6: {

    int tid, pid, fid;

    cout << "Enter Ticket ID: ";
    cin >> tid;

    cout << "Enter Passenger ID: ";
    cin >> pid;

    cout << "Enter Flight ID: ";
    cin >> fid;

    if (cin.fail()) {
        cout << "Invalid Input\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    bool ok = bookTicket(tid, pid, fid);

    if (ok)
        cout << "Booking Process Completed\n";
    else
        cout << "Booking Failed\n";

    break;
}
case 7: {

    int tid;

    cout << "Enter Ticket ID: ";
    cin >> tid;

    if (cin.fail() || tid <= 0) {
        cout << "Invalid Ticket ID\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    cancelTicket(tid);   // 🔴 ONLY THIS

    break;
}
case 8: {

    cout << "====================================================\n";
    cout << "               TICKET BOOKING RECEIPT               \n";
    cout << "====================================================\n\n";

    if (fCount == 0) {
        cout << "No Flight Bookings Available\n";
        break;
    }

    // Fixed 2 passengers names
    string names[2] = {"Hasaan Mir", "Areeba Mir"};

    int showCount = (fCount < 2) ? fCount : 2;

    for (int i = 0; i < showCount; i++) {

        cout << "PASSENGER NAME : " << names[i] << endl;
        cout << "FLIGHT NO      : " << flights[i]->getFlightNumber() << endl;
        cout << "FROM           : " << flights[i]->getOrigin() << endl;
        cout << "TO             : " << flights[i]->getDestination() << endl;
        cout << "DATE           : " << flights[i]->getDateTime() << endl;

        int bookedSeats =
            flights[i]->getTotalSeats() -
            flights[i]->getAvailableSeats();

        cout << "BOOKED SEATS   : " << bookedSeats << endl;

        cout << "----------------------------------------------------\n";
    }

    cout << "\n====================================================\n";
    cout << "            THANK YOU FOR BOOKING WITH US          \n";
    cout << "====================================================\n";

    break;
}
case 9: {

   
    int opt;

    cout << "\n===== REPORTS MENU =====\n";
    cout << "1. Today's Flights\n";
    cout << "2. Occupancy Report\n";
    cout << "3. Top Revenue\n";
    cout << "Enter option: ";
    cin >> opt;
    cout<<"\n---TEMPLATE DEMO----\n";
    cout<<"Max Seats Example: "<<getMax(50, 100)<<endl;
    
    if (cin.fail()) {
        cout << "Invalid Input\n";
        cin.clear();
        cin.ignore(1000, '\n');
        break;
    }

    switch (opt) {

        case 1:
            cout << "\n--- TODAY'S FLIGHTS ---\n";
            listFlights();
            break;

        case 2:
            cout << "\n--- OCCUPANCY REPORT ---\n";
            occupancyReport();
            break;

        case 3:
            cout << "\n--- TOP REVENUE ---\n";
            topRevenueFlights();
            break;

        default:
            cout << "Invalid Report Option\n";
    }

    break;
}
  
    case 0:  
        cout << "Exit\n";  
        break;  

    default:  
        cout << "Invalid Choice\n";  
    }  

} while (ch != 0);

}

