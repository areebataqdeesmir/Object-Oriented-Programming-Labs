#include <iostream>
using namespace std;

class Product
{
private:
    string name;
    double price;
    int quantity;

public:
    void setName(string n)
    {
        if(n != "")
            name = n;
        else 
        cout<<"Name should not be empty"<<endl;
    }

    void setPrice(double p)
    {
        if(p > 0)
            price = p;
        else
        cout<<"Price should not be negative"<<endl;
    }

    void setQuantity(int q)
    {
    	
        if(q >= 0)
            quantity = q;
        else
        cout<<"Quantity should not be negative";
    }

    string getName()
    {
        return name;
    }

    double getPrice()
    {
        return price;
    }

    int getQuantity()
    {
        return quantity;
    }
};

int main()
{
    Product p;

    string n;
    double pr;
    int q;

    cout << "Enter product name: ";
    cin >> n;
    p.setName(n);

    cout << "Enter price: ";
    cin >> pr;
    p.setPrice(pr);

    cout << "Enter quantity: ";
    cin >> q;
    p.setQuantity(q);

    cout << "\nProduct Details\n";
    cout << "Name: " << p.getName() << endl;
    cout << "Price: " << p.getPrice() << endl;
    cout << "Quantity: " << p.getQuantity() << endl;

    return 0;
}
