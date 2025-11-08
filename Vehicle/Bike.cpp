#include "Bike.h"

// Constructor initializes Bike with license plate, delegates to base Vehicle constructor
Bike::Bike(string plate) : Vehicle(plate) {}

// Returns the type of vehicle as a string
string Bike::getType() const {
    return "Bike";
}