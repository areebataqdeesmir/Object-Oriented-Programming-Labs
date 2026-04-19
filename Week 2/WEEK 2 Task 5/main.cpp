#include <iostream>
#include "Calculator.h"
using namespace std;
int main() {

    Calculator c;
    int choice;

    cout << "Enter first number: ";
    cin >> c.num1;

    cout << "Enter second number: ";
    cin >> c.num2;

    cout << "\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n";
    cout << "Choose operation: ";
    cin >> choice;

    switch(choice)
    {
        case 1: cout << "Result: " << c.add(); break;
        case 2: cout << "Result: " << c.subtract(); break;
        case 3: cout << "Result: " << c.multiply(); break;
        case 4: cout << "Result: " << c.divide(); break;
        default: cout << "Invalid choice";
    }

    return 0;
}
