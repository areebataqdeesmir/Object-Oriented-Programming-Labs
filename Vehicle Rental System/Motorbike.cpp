#include "Motorbike.h"

Motorbike::Motorbike() : Vehicle()
{
    engineCC = 0;
}

Motorbike::Motorbike(string id, string model, double rate, int cc)
    : Vehicle(id, model, rate)
{
    engineCC = cc;
}

double Motorbike::calculateCost(int days)
{
    double cost = dailyRate * days;

    // 10% discount if rental > 7 days
    if(days > 7)
    {
        cost = cost - (cost * 0.10);
    }

    return cost;
}

void Motorbike::display() const
{
    cout << "\n----- Motorbike -----" << endl;
    cout << "Vehicle ID : " << vehicleID << endl;
    cout << "Model      : " << model << endl;
    cout << "Daily Rate : " << dailyRate << endl;
    cout << "Engine CC  : " << engineCC << endl;

    if(available)
        cout << "Status     : Available" << endl;
    else
        cout << "Status     : Rented" << endl;
}
