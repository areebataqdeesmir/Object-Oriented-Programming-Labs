#ifndef RENTAL_H
#define RENTAL_H

#include <iostream>
#include <string>
#include "Vehicle.h"
#include "Customer.h"

using namespace std;

class Rental
{
private:
    Customer* customer;
    Vehicle* vehicle;
    int days;
    double totalCost;
    bool active;

public:
    Rental();

    void createRental(Customer* c, Vehicle* v, int d);

    Customer* getCustomer() const;
    Vehicle* getVehicle() const;

    int getDays() const;
    double getTotalCost() const;

    bool isActive() const;
    void closeRental();

    void display() const;
};

#endif
