#include <iostream>
using namespace std;

template <typename T>
void printTwice(T val) {
    cout << val << endl;
    cout << val << endl;
}

int main() {
    printTwice(12);
    printTwice(9.20);
    printTwice("Hiii");
    return 0;
}
