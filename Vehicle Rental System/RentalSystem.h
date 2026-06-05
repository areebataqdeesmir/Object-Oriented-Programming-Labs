#ifndef RENTALSYSTEM_H
#define RENTALSYSTEM_H

#include "Vehicle.h"
#include "Car.h"
#include "Motorbike.h"
#include "Truck.h"
#include "Customer.h"
#include "Rental.h"

class RentalSystem
{
private:
    Vehicle* vehicles[100];
    Customer customers[100];
    Rental rentals[100];

    int vehicleCount;
    int customerCount;
    int rentalCount;

public:
	// Demo Functions
void addVehicleDirect(Vehicle* vehicle);
void addCustomerDirect(Customer customer);
void rentVehicleDirect(string customerID,
                       string vehicleID,
                       int days);
void returnVehicleDirect(string vehicleID);
    RentalSystem();
    ~RentalSystem();

    // Vehicle Functions
    void addVehicle();
    void displayVehicles();

    // Customer Functions
    void registerCustomer();
    void displayCustomers();

    // Rental Functions
    void rentVehicle();
    void returnVehicle();
    void displayRentals();

    // Summary
    void printSummary();

    // Search Functions
    Vehicle* findVehicle(string id);
    Customer* findCustomer(string id);
};

#endif
