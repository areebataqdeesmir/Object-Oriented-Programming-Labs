#include "Vehicle.h"

Vehicle::Vehicle()
{
    vehicleID = "";
    model = "";
    dailyRate = 0;
    available = true;
}

Vehicle::Vehicle(string id, string m, double rate)
{
    vehicleID = id;
    model = m;
    dailyRate = rate;
    available = true;
}

Vehicle::~Vehicle()
{
}

string Vehicle::getVehicleID() const
{
    return vehicleID;
}

string Vehicle::getModel() const
{
    return model;
}

double Vehicle::getDailyRate() const
{
    return dailyRate;
}

bool Vehicle::isAvailable() const
{
    return available;
}

void Vehicle::setAvailable(bool status)
{
    available = status;
}
