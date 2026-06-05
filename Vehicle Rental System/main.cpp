#include <iostream>
#include "RentalSystem.h"

using namespace std;
int main()
{
    RentalSystem system;
    int choice;

    do
    {
        cout << "\n=================================";
        cout << "\n     VEHICLE RENTAL SYSTEM";
        cout << "\n=================================";
        cout << "\n1. Add Vehicle";
        cout << "\n2. Register Customer";
        cout << "\n3. Rent Vehicle";
        cout << "\n4. Return Vehicle";
        cout << "\n5. Display Vehicles";
        cout << "\n6. Display Customers";
        cout << "\n7. Display Rentals";
        cout << "\n8. Print Summary";
        cout << "\n9. Run Demo Scenario";
        cout << "\n10. Exit";
        cout << "\n=================================";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                system.addVehicle();
                break;

            case 2:
                system.registerCustomer();
                break;

            case 3:
                system.rentVehicle();
                break;

            case 4:
                system.returnVehicle();
                break;

            case 5:
                system.displayVehicles();
                break;

            case 6:
                system.displayCustomers();
                break;

            case 7:
                system.displayRentals();
                break;

            case 8:
                system.printSummary();
                break;

            case 9:

    cout << "\n===== DEMO SCENARIO =====\n";

    // 3 Vehicles
    system.addVehicleDirect(
        new Car("V101","Toyota Corolla",5000,5));

    system.addVehicleDirect(
        new Motorbike("V102","Honda 125",1000,125));

    system.addVehicleDirect(
        new Truck("V103","Mazda Truck",8000,10));

    // 2 Customers
    system.addCustomerDirect(
        Customer("C001","Ali"));

    system.addCustomerDirect(
        Customer("C002","Ahad"));

    // 2 Rentals
    system.rentVehicleDirect("C001","V101",5);
    system.rentVehicleDirect("C002","V103",3);

    // Return 1 Vehicle
    system.returnVehicleDirect("V101");

    cout << "\n\n===== VEHICLES ADDED =====\n";
    system.displayVehicles();

    cout << "\n\n===== CUSTOMERS REGISTERED =====\n";
    system.displayCustomers();

    cout << "\n\n===== RENTALS PROCESSED =====\n";
    system.displayRentals();

    cout << "\n\n===== FINAL SUMMARY =====\n";
    system.printSummary();

    break;

        default:
            cout << "Invalid Choice";
    }

}while(choice != 9);

return 0;
}
