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
