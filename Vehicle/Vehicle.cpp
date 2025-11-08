#include "Vehicle.h"

// Constructor initializes the vehicle with a license plate
Vehicle::Vehicle(string plate) : licensePlate(plate) {}

// Returns the license plate of the vehicle
string Vehicle::getLicensePlate() const {
    return licensePlate;
}