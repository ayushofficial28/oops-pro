#include "ParkingSlot.h"
#include<iostream>

ParkingSlot::ParkingSlot(int id, string type, int cost) : slotId(id), allowedType(type), isOccupied(false), charge(cost) {}

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
    if(isOccupied){
        cout<<"Please Pay Rs. "<< charge<<endl;
        parkedVehicle = nullptr;
        isOccupied = false;
        cout << "Slot " << slotId << " released.\n";
    }
    else cout<<"Slot Empty"<<endl;
}

bool ParkingSlot::occupied() const { return isOccupied; }
int ParkingSlot::getId() const { return slotId; }
string ParkingSlot::getAllowedType() const { return allowedType; }