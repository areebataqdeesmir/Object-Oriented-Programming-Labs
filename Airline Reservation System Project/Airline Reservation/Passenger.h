#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
using namespace std;

class Passenger {

protected:
    int passengerID;
    string name;

    string history[20];
    int hCount;

public:
    Passenger(int id, string n);

    int getID();
    string getName();

    void addHistory(string h);
    void showHistory();
    virtual double refundPercentage()=0; 
    virtual void display();
};

#endif

