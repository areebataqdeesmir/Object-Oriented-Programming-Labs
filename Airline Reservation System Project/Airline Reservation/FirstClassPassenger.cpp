#include "FirstClassPassenger.h"
#include<string>
FirstClassPassenger::FirstClassPassenger(int id, string name)
    : Passenger(id, name) {}
    

double FirstClassPassenger::baggageAllowance() {
    return 50;
}

double FirstClassPassenger::refundPercentage() {
    return 90;
}

double FirstClassPassenger::loyaltyMultiplier() {
    return 3;
}
