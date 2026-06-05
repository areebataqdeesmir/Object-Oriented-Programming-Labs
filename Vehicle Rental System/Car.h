#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int seats;

public:
    Car();
    Car(string id, string model, double rate, int seats);

    double calculateCost(int days);
    void display() const;
};

#endif
