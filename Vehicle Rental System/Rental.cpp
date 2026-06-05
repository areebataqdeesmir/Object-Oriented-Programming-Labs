#include "Rental.h"

Rental::Rental()
{
    customer = NULL;
    vehicle = NULL;
    days = 0;
    totalCost = 0;
    active = false;
}

void Rental::createRental(Customer* c, Vehicle* v, int d)
{
    customer = c;
    vehicle = v;
    days = d;

    totalCost = vehicle->calculateCost(days);

    active = true;
}

Customer* Rental::getCustomer() const
{
    return customer;
}

Vehicle* Rental::getVehicle() const
{
    return vehicle;
}

int Rental::getDays() const
{
    return days;
}

double Rental::getTotalCost() const
{
    return totalCost;
}

bool Rental::isActive() const
{
    return active;
}

void Rental::closeRental()
{
    active = false;
}

void Rental::display() const
{
    if(customer == NULL || vehicle == NULL)
        return;

    cout << "\n=========================" << endl;
    cout << "Customer : "
         << customer->getCustomerName() << endl;

    cout << "Vehicle  : "
         << vehicle->getModel() << endl;

    cout << "Days     : "
         << days << endl;

    cout << "Cost     : "
         << totalCost << endl;

    if(active)
        cout << "Status   : Active" << endl;
    else
        cout << "Status   : Closed" << endl;

    cout << "=========================" << endl;
}
