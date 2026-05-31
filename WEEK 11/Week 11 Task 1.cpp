#include <iostream>
using namespace std;

class Box
{
private:
    int length;

public:
    // Constructor
    Box(int l)
    {
        length = l;
    }

    // Friend function
    friend void displayLength(Box b);
};

// Friend function definition
void displayLength(Box b)
{
    cout << "Length = " << b.length << endl;
}

int main()
{
    Box obj(10);

    // Calling friend function
    displayLength(obj);

    return 0;
}
