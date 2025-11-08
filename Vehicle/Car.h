#pragma once
#include "Vehicle.h"

// Represents a Car, derived from the base Vehicle class
class Car : public Vehicle {
public:
    // Constructor initializes the car with a license plate
    Car(string plate);

    // Returns the type of the vehicle as "Car"
    string getType() const override;
};