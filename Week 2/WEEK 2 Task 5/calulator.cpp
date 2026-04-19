#include "Calculator.h"

float Calculator::add() {
    return num1 + num2;
}

float Calculator::subtract() {
    return num1 - num2;
}

float Calculator::multiply() {
    return num1 * num2;
}

float Calculator::divide() {
    if(num2 != 0)
        return num1 / num2;
    else {
        cout << "Cannot divide by zero!" << endl;
        return 0;
    }
}
