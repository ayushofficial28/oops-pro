#include "ParkingSlot.h"
#include <iostream>
using namespace std;

// Constructor initializes slot with ID, allowed vehicle type, and parking charge
ParkingSlot::ParkingSlot(int id, string type, int cost)
    : slotId(id), allowedType(type), isOccupied(false), charge(cost) {}

// Checks if the slot can accept the given vehicle
bool ParkingSlot::canPark(shared_ptr<Vehicle> v) {
    return !isOccupied && v->getType() == allowedType;
}

// Parks the vehicle if the slot is available and type matches
void ParkingSlot::park(shared_ptr<Vehicle> v) {
    if (canPark(v)) {
        parkedVehicle = v;
        isOccupied = true;
    }
}

// Releases the slot and prompts for payment if occupied
void ParkingSlot::release() {
    if (isOccupied) {
        cout << "Please Pay Rs. " << charge << endl;
        parkedVehicle = nullptr; // Clear vehicle reference
        isOccupied = false;
        cout << "Slot " << slotId << " released.\n";
    } else {
        cout << "Slot Empty" << endl;
    }
}

// Returns whether the slot is currently occupied
bool ParkingSlot::occupied() const {
    return isOccupied;
}

// Returns the slot ID
int ParkingSlot::getId() const {
    return slotId;
}

// Returns the allowed vehicle type for this slot
string ParkingSlot::getAllowedType() const {
    return allowedType;
}