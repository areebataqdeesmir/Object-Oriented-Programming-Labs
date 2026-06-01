#ifndef FIRSTCLASSPASSENGER_H
#define FIRSTCLASSPASSENGER_H

#include "Passenger.h"

class FirstClassPassenger : public Passenger {

public:
    FirstClassPassenger(int id, string name);

    double baggageAllowance();
    double refundPercentage();
    double loyaltyMultiplier();
};

#endif

