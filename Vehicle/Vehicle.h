#pragma once
#include <string>
using namespace std;

// Abstract base class representing a generic vehicle
class Vehicle {
protected:
    string licensePlate; // Unique identifier for the vehicle

public:
    // Constructor initializes the vehicle with a license plate
    Vehicle(string plate);

    // Pure virtual method to return the vehicle type (e.g., Car, Bike, Truck)
    virtual string getType() const = 0;

    // Returns the license plate of the vehicle
    string getLicensePlate() const;

    // Virtual destructor to ensure proper cleanup in derived classes
    virtual ~Vehicle() {}
};