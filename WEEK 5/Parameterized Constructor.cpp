 #include <iostream>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    // Constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
private:
    int employeeID;

public:
    // Constructor (calling Person constructor)
    Employee(string n, int a, int id) : Person(n, a) {
        employeeID = id;
    }

    void displayEmployee() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee {
private:
    string department;

public:
    // Constructor (calling Employee constructor)
    Manager(string n, int a, int id, string dep)
        : Employee(n, a, id) {
        department = dep;
    }

    void displayManager() {
        cout << "Department: " << department << endl;
    }
};

int main() {
    string name, dept;
    int age, id;

    // Input
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Employee ID: ";
    cin >> id;

    cout << "Enter Department: ";
    cin >> dept;

    // Object (constructor call)
    Manager m(name, age, id, dept);

    // Display (ALL functions)
    cout << "\n--- Complete Information ---\n";
    m.displayPerson();
    m.displayEmployee();
    m.displayManager();

    return 0;
}
