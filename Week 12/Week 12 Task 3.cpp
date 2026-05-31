#include <iostream>
using namespace std;

// Abstract class
class HospitalStaff
{
protected:
    string staffName;

public:
    // Constructor
    HospitalStaff(string name)
    {
        staffName = name;
    }

    // Pure virtual function
    virtual void performDuty() = 0;
};

// Derived class Doctor
class Doctor : public HospitalStaff
{
public:
    Doctor(string name) : HospitalStaff(name)
    {
    }

    void performDuty()
    {
        cout << staffName << " checks patients." << endl;
    }
};

// Derived class Nurse
class Nurse : public HospitalStaff
{
public:
    Nurse(string name) : HospitalStaff(name)
    {
    }

    void performDuty()
    {
        cout << staffName << " gives medicines." << endl;
    }
};

// Derived class Receptionist
class Receptionist : public HospitalStaff
{
public:
    Receptionist(string name) : HospitalStaff(name)
    {
    }

    void performDuty()
    {
        cout << staffName << " manages appointments." << endl;
    }
};

int main()
{
    Doctor d("Dr. Ali");
    Nurse n("Sara");
    Receptionist r("Areeba");

    d.performDuty();
    n.performDuty();
    r.performDuty();

    return 0;
}
