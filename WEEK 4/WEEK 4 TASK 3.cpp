#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    // Default constructor
    Rectangle() {
        length = 1.0;
        width = 1.0;
    }

    // Parameterized constructor (2 values)
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // Single parameter constructor (square)
    Rectangle(float side) {
        length = side;
        width = side;
    }

    float area() {
        return length * width;
    }

    void display() {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
    }
};

int main() {
    Rectangle r1;           // default
    Rectangle r2(5, 3);    // rectangle
    Rectangle r3(4);       // square

    cout << "\nDefault Rectangle:\n";
    r1.display();

    cout << "\nParameterized Rectangle:\n";
    r2.display();

    cout << "\nSquare:\n";
    r3.display();

    return 0;
}
