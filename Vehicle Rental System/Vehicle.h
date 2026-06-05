#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string vehicleID;
    string model;
    double dailyRate;
    bool available;

public:
    Vehicle();
    Vehicle(string id, string m, double rate);

    virtual ~Vehicle();

    string getVehicleID() const;
    string getModel() const;
    double getDailyRate() const;

    bool isAvailable() const;
    void setAvailable(bool status);

    virtual double calculateCost(int days) = 0;
    virtual void display() const = 0;
};

#endif
