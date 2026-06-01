#include "EconomyPassenger.h"

EconomyPassenger::EconomyPassenger(int id, string name)
    : Passenger(id, name) {}
    
double EconomyPassenger::refundPercentage(){
	return 50;
} 

double EconomyPassenger::baggageAllowance() {
    return 20;
}


double EconomyPassenger::loyaltyMultiplier() {
    return 1;
}

