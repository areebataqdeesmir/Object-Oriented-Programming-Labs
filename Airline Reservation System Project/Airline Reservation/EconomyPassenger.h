#ifndef ECONOMYPASSENGER_H
#define ECONOMYPASSENGER_H

#include "Passenger.h"

class EconomyPassenger : public Passenger {

public:
    EconomyPassenger(int id, string name);

    double baggageAllowance();
    double refundPercentage();
    double loyaltyMultiplier();
};

#endif

