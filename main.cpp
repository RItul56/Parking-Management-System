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

        cout << "\nEnter Owner Name: ";
        cin.ignore();
        getline(cin, ownerName);

        cout << "Enter License Plate: ";
        cin >> licensePlate;

        int typeChoice;

        cout << "\nSelect Vehicle Type\n";
        cout << "1. Two Wheeler (Rs.20/hr)\n";
        cout << "2. Auto Rickshaw (Rs.30/hr)\n";
        cout << "3. Car / LLMV (Rs.50/hr)\n";
        cout << "4. Passenger SUV / Pickup (Rs.100/hr)\n";
        cout << "5. Truck / Bus / Heavy Vehicle (Rs.200/hr)\n";
        cout << "Enter Choice: ";
        cin >> typeChoice;
        
        switch(typeChoice)
        {
        case 1:
            vehicleType = "Two Wheeler";
            break;
        
        case 2:
            vehicleType = "Auto Rickshaw";
            break;
        
        case 3:
            vehicleType = "Car";
            break;
        
        case 4:
            vehicleType = "SUV";
            break;
        
        case 5:
            vehicleType = "Heavy Vehicle";
            break;
        
        default:
            cout << "Invalid Choice!\n";
            return;
        }

        cout << "Enter Duration (hours): ";
        cin >> duration;

        double rent;

        if(vehicleType == "Two Wheeler")
            rent = duration * 20;
        
        else if(vehicleType == "Auto Rickshaw")
            rent = duration * 30;
        
        else if(vehicleType == "Car")
            rent = duration * 50;
        
        else if(vehicleType == "SUV")
            rent = duration * 100;
        
        else if(vehicleType == "Heavy Vehicle")
            rent = duration * 200;

        Vehicle newVehicle(
        ownerName,
            licensePlate,
            vehicleType,
            duration,
            rent
        );
        
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

    for (size_t i = 0; i < vehicles.size(); i++)
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

        for (size_t i = 0; i < vehicles.size(); i++)
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