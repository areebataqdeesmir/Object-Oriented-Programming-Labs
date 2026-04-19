#ifndef VOTER_H
#define VOTER_H

#include <iostream>
using namespace std;

class Voter
{
public:
    string name;
    int age;

    bool isEligible();
};

#endif

