#include "Car.h"

Car::Car() : Vehicle()
{
    seats = 0;
}

Car::Car(string id, string model, double rate, int s)
    : Vehicle(id, model, rate)
{
    seats = s;
}

double Car::calculateCost(int days)
{
    return dailyRate * days;
}

void Car::display() const
{
    cout << "\n----- Car -----" << endl;
    cout << "Vehicle ID : " << vehicleID << endl;
    cout << "Model      : " << model << endl;
    cout << "Daily Rate : " << dailyRate << endl;
    cout << "Seats      : " << seats << endl;

    if(available)
        cout << "Status     : Available" << endl;
    else
        cout << "Status     : Rented" << endl;
}
