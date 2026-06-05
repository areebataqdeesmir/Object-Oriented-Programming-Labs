#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle
{
private:
    double payloadCapacity;

public:
    Truck();
    Truck(string id, string model, double rate, double payload);

    double calculateCost(int days);
    void display() const;
};

#endif
