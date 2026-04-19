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

class Student : public Person {
private:
    int studentID;

public:
    // Constructor (calling Person constructor)
    Student(string n, int a, int id) : Person(n, a) {
        studentID = id;
    }

    void displayStudent() {
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    string name;
    int age, id;

    // Input
    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter Student ID: ";
    cin >> id;

    // Object (constructor call)
    Student s(name, age, id);

    // Display
    cout << "\n--- Student Information ---\n";
    s.displayPerson();
    s.displayStudent();

    return 0;
}
