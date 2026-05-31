#include <iostream>
using namespace std;

class Distance
{
private:
    int feet;
    int inches;

public:
    // Constructor
    Distance(int f, int i)
    {
        feet = f;
        inches = i;
    }

    // Friend function
    friend void addDistance(Distance d1, Distance d2);
};

// Friend function definition
void addDistance(Distance d1, Distance d2)
{
    int totalFeet = d1.feet + d2.feet;
    int totalInches = d1.inches + d2.inches;

    cout << "Total Distance = ";
    cout << totalFeet << " feet ";
    cout << totalInches << " inches";
}

int main()
{
    Distance d1(5, 8);
    Distance d2(3, 7);

    addDistance(d1, d2);

    return 0;
}
