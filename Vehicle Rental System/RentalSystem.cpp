#include "RentalSystem.h"

RentalSystem::RentalSystem()
{
    vehicleCount = 0;
    customerCount = 0;
    rentalCount = 0;
}

RentalSystem::~RentalSystem()
{
    for(int i = 0; i < vehicleCount; i++)
    {
        delete vehicles[i];
    }
}

Vehicle* RentalSystem::findVehicle(string id)
{
    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i]->getVehicleID() == id)
        {
            return vehicles[i];
        }
    }

    return NULL;
}

Customer* RentalSystem::findCustomer(string id)
{
    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].getCustomerID() == id)
        {
            return &customers[i];
        }
    }

    return NULL;
}

void RentalSystem::addVehicle()
{
    int choice;

    cout << "\n===== Add Vehicle =====" << endl;
    cout << "1. Car" << endl;
    cout << "2. Motorbike" << endl;
    cout << "3. Truck" << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    string id, model;
    double rate;

    cout << "Vehicle ID: ";
    cin >> id;

    cin.ignore();

    cout << "Model: ";
    getline(cin, model);

    cout << "Daily Rate: ";
    cin >> rate;

    if(choice == 1)
    {
        int seats;

        cout << "Seats: ";
        cin >> seats;

        vehicles[vehicleCount++] =
            new Car(id, model, rate, seats);
    }
    else if(choice == 2)
    {
        int cc;

        cout << "Engine CC: ";
        cin >> cc;

        vehicles[vehicleCount++] =
            new Motorbike(id, model, rate, cc);
    }
    else if(choice == 3)
    {
        double payload;

        cout << "Payload Capacity (tons): ";
        cin >> payload;

        vehicles[vehicleCount++] =
            new Truck(id, model, rate, payload);
    }

    cout << "\nVehicle Added Successfully!" << endl;
}

void RentalSystem::registerCustomer()
{
    string id, name;

    cout << "\n===== Register Customer =====" << endl;

    cout << "Customer ID: ";
    cin >> id;

    cin.ignore();

    cout << "Customer Name: ";
    getline(cin, name);

    customers[customerCount++] =
        Customer(id, name);

    cout << "\nCustomer Registered Successfully!" << endl;
}

void RentalSystem::displayVehicles()
{
    cout << "\n===== VEHICLES =====" << endl;

    if(vehicleCount == 0)
    {
        cout << "No vehicles available." << endl;
        return;
    }

    for(int i = 0; i < vehicleCount; i++)
    {
        vehicles[i]->display();
    }
}

void RentalSystem::displayCustomers()
{
    cout << "\n===== CUSTOMERS =====" << endl;

    if(customerCount == 0)
    {
        cout << "No customers registered." << endl;
        return;
    }

    for(int i = 0; i < customerCount; i++)
    {
        customers[i].display();
    }
}

void RentalSystem::rentVehicle()
{
    string customerID;
    string vehicleID;
    int days;

    cout << "\n===== Rent Vehicle =====" << endl;

    cout << "Customer ID: ";
    cin >> customerID;

    Customer* customer =
        findCustomer(customerID);

    if(customer == NULL)
    {
        cout << "Customer Not Found!" << endl;
        return;
    }

    if(customer->hasActiveRental())
    {
        cout << "Customer Already Has Active Rental!" << endl;
        return;
    }

    cout << "Vehicle ID: ";
    cin >> vehicleID;

    Vehicle* vehicle =
        findVehicle(vehicleID);

    if(vehicle == NULL)
    {
        cout << "Vehicle Not Found!" << endl;
        return;
    }

    if(!vehicle->isAvailable())
    {
        cout << "Vehicle Already Rented!" << endl;
        return;
    }

    cout << "Days: ";
    cin >> days;

    rentals[rentalCount].createRental(
        customer,
        vehicle,
        days
    );

    vehicle->setAvailable(false);
    customer->setActiveRental(true);

    cout << "\nRental Cost: "
         << rentals[rentalCount].getTotalCost()
         << endl;

    rentalCount++;

    cout << "Vehicle Rented Successfully!" << endl;
}

void RentalSystem::returnVehicle()
{
    string vehicleID;

    cout << "\n===== Return Vehicle =====" << endl;
    cout << "Vehicle ID: ";
    cin >> vehicleID;

    for(int i = 0; i < rentalCount; i++)
    {
        if(rentals[i].isActive())
        {
            if(rentals[i].getVehicle()->getVehicleID()
                == vehicleID)
            {
                rentals[i].closeRental();

                rentals[i].getVehicle()
                    ->setAvailable(true);

                rentals[i].getCustomer()
                    ->setActiveRental(false);

                cout << "\nVehicle Returned Successfully!"
                     << endl;

                return;
            }
        }
    }

    cout << "Active Rental Not Found!" << endl;
}

void RentalSystem::displayRentals()
{
    cout << "\n===== RENTALS =====" << endl;

    if(rentalCount == 0)
    {
        cout << "No Rentals Found." << endl;
        return;
    }

    for(int i = 0; i < rentalCount; i++)
    {
        rentals[i].display();
    }
}
void RentalSystem::printSummary()
{
    int availableCount = 0;
    int rentedCount = 0;

    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i]->isAvailable())
            availableCount++;
        else
            rentedCount++;
    }

    cout << "\n================================";
    cout << "\n           SUMMARY";
    cout << "\n================================";

    cout << "\nTotal Vehicles   : "
         << vehicleCount;

    cout << "\nTotal Customers  : "
         << customerCount;

    cout << "\nTotal Rentals    : "
         << rentalCount;

    cout << "\nAvailable Vehicles : "
         << availableCount;

    cout << "\nRented Vehicles    : "
         << rentedCount;

    cout << "\n================================\n";
}

// ==========================
// DEMO FUNCTIONS
// ==========================

void RentalSystem::addVehicleDirect(Vehicle* vehicle)
{
    vehicles[vehicleCount++] = vehicle;
}

void RentalSystem::addCustomerDirect(Customer customer)
{
    customers[customerCount++] = customer;
}

void RentalSystem::rentVehicleDirect(string customerID,
                                     string vehicleID,
                                     int days)
{
    Customer* customer = findCustomer(customerID);
    Vehicle* vehicle = findVehicle(vehicleID);

    if(customer == NULL || vehicle == NULL)
        return;

    if(customer->hasActiveRental())
        return;

    if(!vehicle->isAvailable())
        return;

    rentals[rentalCount].createRental(
        customer,
        vehicle,
        days
    );

    customer->setActiveRental(true);
    vehicle->setAvailable(false);

    rentalCount++;
}

void RentalSystem::returnVehicleDirect(string vehicleID)
{
    for(int i = 0; i < rentalCount; i++)
    {
        if(rentals[i].isActive())
        {
            if(rentals[i].getVehicle()->getVehicleID() == vehicleID)
            {
                rentals[i].closeRental();

                rentals[i].getVehicle()->setAvailable(true);
                rentals[i].getCustomer()->setActiveRental(false);

                return;
            }
        }
    }
}
