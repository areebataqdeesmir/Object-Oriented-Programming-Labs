#include <iostream>
using namespace std;

class Calculator {
public:
    float num1, num2;

    float add() {
        return num1 + num2;
    }

    float subtract() {
        return num1 - num2;
    }

    float multiply() {
        return num1 * num2;
    }

    float divide() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Cannot divide by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    Calculator c;
    int choice;

    cout << "Enter first number: ";
    cin >> c.num1;

    cout << "Enter second number: ";
    cin >> c.num2;

    cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n";
    cout << "Choose operation: ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Result: " << c.add();
            break;
        case 2:
            cout << "Result: " << c.subtract();
            break;
        case 3:
            cout << "Result: " << c.multiply();
            break;
        case 4:
            cout << "Result: " << c.divide();
            break;
        default:
            cout << "Invalid choice!";
    }

    return 0;
}
