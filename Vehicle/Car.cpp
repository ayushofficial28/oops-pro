#include "Car.h"

Car::Car(string plate) : Vehicle(plate) {}

string Car::getType() const {
    return "Car";
}