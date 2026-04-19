#include "Temperature.h"

float Temperature::convert() {
    return (celsius * 9/5) + 32;   // Celsius ? Fahrenheit
}

void Temperature::display() {
    cout << "Temperature in Fahrenheit: " << convert() << endl;
}
#include <iostream>
#include "Temperature.h"

using namespace std;

int main() {

    Temperature t;

    cout << "Enter temperature in Celsius: ";
    cin >> t.celsius;

    t.display();

    return 0;
}
