#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <iostream>
using namespace std;

class Calculator {
public:
    float num1, num2;

    float add() { return num1 + num2; }
    float subtract() { return num1 - num2; }
    float multiply() { return num1 * num2; }

    float divide() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Cannot divide by zero!" << endl;
            return 0;
        }
    }
};

#endif
