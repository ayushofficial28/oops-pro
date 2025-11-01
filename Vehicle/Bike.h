#pragma once
#include "Vehicle.h"

class Bike : public Vehicle {
public:
    Bike(string plate);
    string getType() const override;
};