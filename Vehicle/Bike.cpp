#include "Bike.h"

Bike::Bike(string plate) : Vehicle(plate) {}

string Bike::getType() const {
    return "Bike";
}