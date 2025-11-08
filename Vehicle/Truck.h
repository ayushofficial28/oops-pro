#pragma once
#include "Vehicle.h"

// Represents a Truck, derived from the base Vehicle class
class Truck : public Vehicle {
public:
    // Constructor initializes the truck with a license plate
    Truck(string plate);

    // Returns the type of the vehicle as "Truck"
    string getType() const override;
};