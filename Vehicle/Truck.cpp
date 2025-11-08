#include "Truck.h"

// Constructor initializes Truck with license plate, delegates to base Vehicle constructor
Truck::Truck(string plate) : Vehicle(plate) {}

// Returns the type of vehicle as a string
string Truck::getType() const {
    return "Truck";
}