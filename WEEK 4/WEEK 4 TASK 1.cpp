#include <iostream>
using namespace std;

class Employee {
private:
    int id;
    string name;
    float salary;

public:
    // Default Constructor
    Employee() {
        id = 0;
        name = "Not Assigned";
        salary = 0.0;
    }

    void displayDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Employee e1;  // Default constructor called
    e1.displayDetails();

    return 0;
}
