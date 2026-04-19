#include <iostream>
using namespace std;

// Base Class
class Employee {
private:
    string name;
    double salary;

public:
    // Parameterized Constructor
    Employee(string n, double s) {
        name = n;
        salary = s;
    }

    // Display function
    void displayEmployee() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived Class: Developer
class Developer : public Employee {
private:
    string programmingLanguage;

public:
    // Parameterized Constructor
    Developer(string n, double s, string pl)
        : Employee(n, s) {
        programmingLanguage = pl;
    }

    void displayDeveloper() {
        cout << "\n--- Developer Information ---" << endl;
        displayEmployee();
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};

// Derived Class: Designer
class Designer : public Employee {
private:
    string designTool;

public:
    // Parameterized Constructor
    Designer(string n, double s, string dt)
        : Employee(n, s) {
        designTool = dt;
    }

    void displayDesigner() {
        cout << "\n--- Designer Information ---" << endl;
        displayEmployee();
        cout << "Design Tool: " << designTool << endl;
    }
};

int main() {
    string name, lang, tool;
    double salary;

    // Input for Developer
    cout << "Enter Developer Name: ";
    cin >> name;
    cout << "Enter Developer Salary: ";
    cin >> salary;
    cout << "Enter Programming Language: ";
    cin >> lang;

    Developer dev(name, salary, lang);

    // Input for Designer
    cout << "\nEnter Designer Name: ";
    cin >> name;
    cout << "Enter Designer Salary: ";
    cin >> salary;
    cout << "Enter Design Tool: ";
    cin >> tool;

    Designer des(name, salary, tool);

    // Display
    cout << "\n===== Displaying Information =====\n";
    dev.displayDeveloper();
    des.displayDesigner();

    return 0;
}
