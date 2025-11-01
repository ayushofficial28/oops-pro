#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(string plate);
    string getType() const override;
};