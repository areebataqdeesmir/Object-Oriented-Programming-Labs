#include <iostream>
using namespace std;

class Employee
{
private:
    int employeeID;
    string employeeName;

    // Static variable
    static string companyName;

public:
    // Constructor
    Employee(int id, string name)
    {
        employeeID = id;
        employeeName = name;
    }

    // Function to display employee details
    void display()
    {
        cout << "Employee ID: " << employeeID << endl;
        cout << "Employee Name: " << employeeName << endl;
        cout << "Company Name: " << companyName << endl;
    }

    // Static member function
    static void displayCompanyInfo()
    {
        cout << "Company Name: " << companyName << endl;
    }
};

// Static variable definition
string Employee::companyName = "Tech Solutions";

int main()
{
    Employee e1(101, "Areeba");
    Employee e2(102, "Ali");

    e1.display();
    cout << endl;

    e2.display();
    cout << endl;

    // Access static function using class name
    Employee::displayCompanyInfo();

    return 0;
}
