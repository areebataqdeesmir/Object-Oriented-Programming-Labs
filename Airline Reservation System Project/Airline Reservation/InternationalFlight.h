#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"

class InternationalFlight : public Flight {

public:
    InternationalFlight(int fn, string o, string d, string dt, int ts);

    double calculateBaseFare();
    void display();
};

#endif

