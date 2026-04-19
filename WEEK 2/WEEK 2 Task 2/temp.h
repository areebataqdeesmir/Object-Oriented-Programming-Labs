#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <iostream>
using namespace std;

class Temperature {
public:
    float celsius;

    float convert();   // function declaration
    void display();    // function declaration
};

#endif
