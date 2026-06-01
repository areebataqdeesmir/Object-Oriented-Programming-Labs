#ifndef CHARTERFLIGHT_H
#define CHARTERFLIGHT_H

#include "Flight.h"

class CharterFlight : public Flight {

    string contractHolder;

public:
    CharterFlight(int fn, string o, string d, string dt, int ts, string ch);

    double calculateBaseFare();
    void display();
};

#endif


