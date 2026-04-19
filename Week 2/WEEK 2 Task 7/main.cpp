#include <iostream>
#include "Voter.h"

using namespace std;

int main)
{
    Voter v;

    cout << "Enter name: ";
    cin >> v.name;

    cout << "Enter age: ";
    cin >> v.age;

    if(v.isEligible())
        cout << "You are eligible to vote.";
    else
        cout << "You are not eligible to vote.";

    return 0;

