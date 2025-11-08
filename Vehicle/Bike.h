#pragma once
#include "Vehicle.h"

// Represents a Bike, derived from the base Vehicle class
class Bike : public Vehicle {
public:
    // Constructor initializes the bike with a license plate
    Bike(string plate);

    // Returns the type of the vehicle as "Bike"
    string getType() const override;
};