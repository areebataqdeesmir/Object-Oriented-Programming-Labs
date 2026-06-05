#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string customerID;
    string customerName;
    bool activeRental;

public:
    Customer();
    Customer(string id, string name);

    string getCustomerID() const;
    string getCustomerName() const;

    bool hasActiveRental() const;
    void setActiveRental(bool status);

    void display() const;
};

#endif
