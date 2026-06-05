#ifndef MOTORBIKE_H
#define MOTORBIKE_H

#include "Vehicle.h"

class Motorbike : public Vehicle
{
private:
    int engineCC;

public:
    Motorbike();
    Motorbike(string id, string model, double rate, int cc);

    double calculateCost(int days);
    void display() const;
};

#endif
