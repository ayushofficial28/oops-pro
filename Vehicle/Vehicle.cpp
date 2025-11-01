#include "Vehicle.h"

Vehicle::Vehicle(string plate) : licensePlate(plate) {}

string Vehicle::getLicensePlate() const {
    return licensePlate;
}