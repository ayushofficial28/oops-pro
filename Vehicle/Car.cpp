#include "Car.h"

// Constructor initializes Car with license plate, delegates to base Vehicle constructor
Car::Car(string plate) : Vehicle(plate) {}

// Returns the type of vehicle as a string
string Car::getType() const {
    return "Car";
}