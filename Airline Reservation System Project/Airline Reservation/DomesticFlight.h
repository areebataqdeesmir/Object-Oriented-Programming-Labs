#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include "Flight.h"

class DomesticFlight : public Flight {

public:
    DomesticFlight(int fn, string o, string d, string dt, int ts);

    double calculateBaseFare();
    void display();
};

#endif

