#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle
{
private:
    string OwnerName;
    string LicensePlate;
    string VehicleType;
    int Duration;
    double Rent;

public:
    Vehicle(string ownerName,
            string licensePlate,
            string vehicleType,
            int duration,
            double rent)
    {
        OwnerName = ownerName;
        LicensePlate = licensePlate;
        VehicleType = vehicleType;
        Duration = duration;
        Rent = rent;
    }

    void display()
    {
        cout << "\n+----------------------------------+\n";
        cout << "Owner Name   : " << OwnerName << endl;
        cout << "License Plate: " << LicensePlate << endl;
        cout << "Vehicle Type : " << VehicleType << endl;
        cout << "Duration     : " << Duration << " hours" << endl;
        cout << "Rent         : Rs. " << Rent << endl;
        cout << "+----------------------------------+\n";
    }

    string getVehicleNumber()
    {
        return LicensePlate;
    }
};

class ParkingLot
{
private:
    vector<Vehicle> vehicles;
    int capacity;

public:
    ParkingLot(int cap)
    {
        capacity = cap;
    }

    void parkVehicle()
    {
        if (vehicles.size() >= capacity)
        {
            cout << "\nParking lot is full.\n";
            return;
        }

        string ownerName, licensePlate, vehicleType;
        int duration;
        double rent;

        cout << "\nEnter Owner Name: ";
        cin >> ownerName;

        cout << "Enter License Plate: ";
        cin >> licensePlate;

        cout << "Enter Vehicle Type: ";
        cin >> vehicleType;

        cout << "Enter Duration (hours): ";
        cin >> duration;

        cout << "Enter Rent: ";
        cin >> rent;

        Vehicle newVehicle(
            ownerName,
            licensePlate,
            vehicleType,
            duration,
            rent);

        vehicles.push_back(newVehicle);

        cout << "\nVehicle parked successfully.\n";
        cout << "Current Vehicle Count: "
             << vehicles.size() << endl;
    }

    void displayVehicle()
{
    cout << "\nDEBUG: Function called\n";
    cout << "DEBUG: Vehicle Count = " << vehicles.size() << endl;

    if (vehicles.empty())
    {
        cout << "No vehicles parked." << endl;
        return;
    }

    for (int i = 0; i < vehicles.size(); i++)
    {
        cout << "Displaying Vehicle " << i + 1 << endl;
        vehicles[i].display();
    }
}

    void removeVehicle()
    {
        string vehicleNumber;

        cout << "\nEnter Vehicle Number: ";
        cin >> vehicleNumber;

        for (int i = 0; i < vehicles.size(); i++)
        {
            if (vehicles[i].getVehicleNumber() == vehicleNumber)
            {
                vehicles.erase(vehicles.begin() + i);

                cout << "\nVehicle Removed Successfully!\n";
                return;
            }
        }

        cout << "\nVehicle Not Found!\n";
    }
};

int main()
{
    ParkingLot parking(10);

    int choice;

    do
    {
        cout << "\n====== Parking Management System ======\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Display Vehicles\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: "<<endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            parking.parkVehicle();
            break;

        case 2:
            parking.displayVehicle();
            break;

        case 3:
            parking.removeVehicle();
            break;

        case 4:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}