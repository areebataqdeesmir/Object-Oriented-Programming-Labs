#include "BusinessPassenger.h"

BusinessPassenger::BusinessPassenger(int id, string name)
    : Passenger(id, name) {}

double BusinessPassenger::refundPercentage(){
	return 70;
}

double BusinessPassenger::baggageAllowance() {
    return 35;
}


double BusinessPassenger::loyaltyMultiplier() {
    return 2;
}

