#include <iostream>
using namespace std;

class Voter {
public:
    string name;
    int age;

    bool isEligible();
};

bool Voter::isEligible() {
    if (age > 18)
        return true;
    else
        return false;
}

int main() {
    Voter v1;

    cout << "Enter name: ";
    cin >> v1.name;

    cout << "Enter age: ";
    cin >> v1.age;

    if (v1.isEligible())
        cout << "You are eligible to vote." << endl;
    else
        cout << "You are NOT eligible to vote." << endl;

    return 0;
}
