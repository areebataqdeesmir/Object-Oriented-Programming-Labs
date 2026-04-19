#include <iostream>
using namespace std;

class Product {
private:
    string name;
    float price;

public:
    Product(string n, float p) {
        name = n;
        price = p;
        cout << "Product Constructor Called\n";
    }

    // Getter functions
    string getName() {
        return name;
    }

    float getPrice() {
        return price;
    }
};

class Electronics : public Product {
private:
    int warrantyYears;

public:
    Electronics(string n, float p, int w) : Product(n, p) {
        warrantyYears = w;
        cout << "Electronics Constructor Called\n";
    }

    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Price: " << getPrice() << endl;
        cout << "Warranty: " << warrantyYears << " years\n";
    }
};

int main() {
    Electronics e1("Laptop", 80000, 2);
    e1.display();
}
