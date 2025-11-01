#include "Truck.h"

Truck::Truck(string plate) : Vehicle(plate) {}

string Truck::getType() const {
    return "Truck";
}