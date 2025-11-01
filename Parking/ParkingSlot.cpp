#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(int id, string type) : slotId(id), allowedType(type), isOccupied(false) {}

bool ParkingSlot::canPark(shared_ptr<Vehicle> v) {
    return !isOccupied && v->getType() == allowedType;
}

void ParkingSlot::park(shared_ptr<Vehicle> v) {
    if (canPark(v)) {
        parkedVehicle = v;
        isOccupied = true;
    }
}

void ParkingSlot::release() {
    parkedVehicle = nullptr;
    isOccupied = false;
}

bool ParkingSlot::occupied() const { return isOccupied; }
int ParkingSlot::getId() const { return slotId; }
string ParkingSlot::getAllowedType() const { return allowedType; }