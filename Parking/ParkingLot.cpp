#include "ParkingLot.h"
#include <iostream>
using namespace std;

ParkingLot::ParkingLot() {
    for (int i = 0; i < 5; ++i) slots.emplace_back(i, "Car", 40);
    for (int i = 5; i < 8; ++i) slots.emplace_back(i, "Bike", 20);
    for (int i = 8; i < 10; ++i) slots.emplace_back(i, "Truck", 80);
}

ParkingSlot* ParkingLot::allocateSlot(shared_ptr<Vehicle> v) {
    for (auto& slot : slots) {
        if (slot.canPark(v)) {
            slot.park(v);
            return &slot;
        }
    }
    return nullptr;
}

void ParkingLot::releaseSlot(int slotId) {
    if(slotId>=0 && slotId<10){
        ParkingSlot *slot=&slots[slotId];
        slot->release();
    }
    else cout<<"Invalid slotId"<<endl;
}

void ParkingLot::displayStatus() const {
    for (const auto& slot : slots) {
        cout << "Slot " << slot.getId() << " (" << slot.getAllowedType() << ") - "
             << (slot.occupied() ? "Occupied" : "Available") << endl;
    }
}