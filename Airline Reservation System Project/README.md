Airline Reservation & Flight Management System

Student Information

Name: Areeba Taqdees Mir
Roll Number: 2025-SE-13
Department: Software Engineering

---

Project Title

Airline Reservation & Flight Management System

---

Project Description

The Airline Reservation & Flight Management System is a C++ Object-Oriented Programming (OOP) based application developed to manage airline operations efficiently. The system allows administrators to manage flights, register passengers, book and cancel tickets, generate reports, and maintain flight records.

The project demonstrates the practical implementation of major OOP concepts including Inheritance, Polymorphism, Abstraction, Encapsulation, File Handling, Exception Handling, and Templates.

---

Features

Flight Management

- Add new flights
- Remove existing flights
- View all available flights
- Search flights by:
  - Flight Number
  - Route
  - Date

Passenger Management

- Register passengers
- View passenger details
- View booking history

Ticket Management

- Book tickets
- Cancel tickets
- Prevent duplicate bookings
- Automatic seat allocation

Reports

- Today's Departures Report
- Occupancy Report
- Revenue Report

Data Storage

- Save system data to file
- Load saved data from file

---

OOP Concepts Implemented

1. Encapsulation

Data members are kept private and accessed through public member functions.

2. Inheritance

Different flight and passenger types inherit from base classes.

Flight Hierarchy

- Flight
  - DomesticFlight
  - InternationalFlight
  - CharterFlight

Passenger Hierarchy

- Passenger
  - EconomyPassenger
  - BusinessPassenger
  - FirstClassPassenger

3. Polymorphism

Virtual functions are used for displaying information and calculating fares.

4. Abstraction

Abstract behavior is provided through base classes and virtual functions.

5. Templates

A generic template function is used:

template <class T>
T getMax(T a, T b)
{
    return (a > b) ? a : b;
}

6. Exception Handling

Custom exceptions implemented:

- FlightNotFoundException
- PassengerNotFoundException
- FlightFullException
- AlreadyBookedException

---

Classes Used

Core Classes

- Airline
- Flight
- Passenger
- Ticket

Flight Classes

- DomesticFlight
- InternationalFlight
- CharterFlight

Passenger Classes

- EconomyPassenger
- BusinessPassenger
- FirstClassPassenger

Exception Classes

- AirlineException
- FlightNotFoundException
- PassengerNotFoundException
- FlightFullException
- AlreadyBookedException

---

Technologies Used

- C++
- Object-Oriented Programming
- File Handling
- Exception Handling
- Templates

---

How to Run

1. Open the project in Dev-C++ or any C++ IDE.
2. Add all ".cpp" and ".h" files to the project.
3. Compile the project.
4. Run the executable file.
5. Use the menu-driven interface to perform operations.

---

Sample Functionalities

Add Flight

Administrator can create Domestic, International, and Charter flights.

Register Passenger

Passengers can be registered with different classes.

Book Ticket

Passengers can reserve seats on available flights.

Cancel Ticket

Passengers can cancel bookings and receive refunds according to passenger class.

Generate Reports

The system can generate occupancy and revenue reports.

---

Conclusion

This project successfully demonstrates the implementation of a complete Airline Reservation and Flight Management System using C++. It applies important OOP principles, exception handling, templates, and file handling while providing a practical solution for managing airline operations. The project enhances understanding of software design, code reusability, and real-world application development.

---

Submitted By: Areeba Taqdees Mir
Roll Number: 2025-SE-13
Department: Software Engineering
