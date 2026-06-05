#include "Truck.h"

Truck::Truck() : Vehicle()
{
    payloadCapacity = 0;
}

Truck::Truck(string id, string model, double rate, double payload)
    : Vehicle(id, model, rate)
{
    payloadCapacity = payload;
}

double Truck::calculateCost(int days)
{
    double cost = dailyRate * days;

    // 20% surcharge
    cost = cost + (cost * 0.20);

    return cost;
}

void Truck::display() const
{
    cout << "\n----- Truck -----" << endl;
    cout << "Vehicle ID      : " << vehicleID << endl;
    cout << "Model           : " << model << endl;
    cout << "Daily Rate      : " << dailyRate << endl;
    cout << "Payload Capacity: " << payloadCapacity << " tons" << endl;

    if(available)
        cout << "Status          : Available" << endl;
    else
        cout << "Status          : Rented" << endl;
}
