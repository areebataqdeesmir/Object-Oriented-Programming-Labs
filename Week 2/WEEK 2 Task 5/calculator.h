#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;

class Calculator {
public:
    float num1;
    float num2;

    float add();
    float subtract();
    float multiply();
    float divide();
};

#endif
