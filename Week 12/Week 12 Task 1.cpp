#include <iostream>
using namespace std;

class BankAccount
{
private:
    string accountHolderName;
    float balance;

    // Static variable
    static int totalAccounts;

public:
    // Constructor
    BankAccount(string name, float b)
    {
        accountHolderName = name;
        balance = b;

        totalAccounts++;
    }

    // Function to display account details
    void display()
    {
        cout << "Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    // Static function to display total accounts
    static void showTotalAccounts()
    {
        cout << "Total Accounts Created: " << totalAccounts << endl;
    }
};

// Static variable definition
int BankAccount::totalAccounts = 0;

int main()
{
    BankAccount b1("Areeba", 5000);
    BankAccount b2("Ali", 7000);
    BankAccount b3("Sara", 9000);

    b1.display();
    cout << endl;

    b2.display();
    cout << endl;

    b3.display();
    cout << endl;

    // Display total accounts
    BankAccount::showTotalAccounts();

    return 0;
}
