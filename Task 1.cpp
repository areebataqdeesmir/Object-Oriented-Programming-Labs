#include <iostream>
using namespace std;

struct Student
{
    string firstName;
    string lastName;
    int rollNumber;
    float marks;

    void displayStudentInfo()
    {
        cout << "Full Name: " << firstName << " " << lastName << endl;
        cout << "Marks: " << marks << endl;
    }
};

int main()
{
    Student s1;

    // Assign values
    s1.firstName = "Areeba";
    s1.lastName = "Taqdees";
    s1.rollNumber = 101;
    s1.marks = 90.5;

    // Display info
    s1.displayStudentInfo();
    return 0;
}
