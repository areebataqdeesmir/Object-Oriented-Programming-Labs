#include "Customer.h"

Customer::Customer()
{
    customerID = "";
    customerName = "";
    activeRental = false;
}

Customer::Customer(string id, string name)
{
    customerID = id;
    customerName = name;
    activeRental = false;
}

string Customer::getCustomerID() const
{
    return customerID;
}

string Customer::getCustomerName() const
{
    return customerName;
}

bool Customer::hasActiveRental() const
{
    return activeRental;
}

void Customer::setActiveRental(bool status)
{
    activeRental = status;
}

void Customer::display() const
{
    cout << "\nCustomer ID   : " << customerID << endl;
    cout << "Customer Name : " << customerName << endl;

    if(activeRental)
        cout << "Rental Status : Active" << endl;
    else
        cout << "Rental Status : None" << endl;
}
