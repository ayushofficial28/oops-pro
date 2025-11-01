#include "ParkingLot.h"
#include <iostream>
using namespace std;

ParkingLot::ParkingLot() {
    for (int i = 0; i < 5; ++i) slots.emplace_back(i, "Car");
    for (int i = 5; i < 8; ++i) slots.emplace_back(i, "Bike");
    for (int i = 8; i < 10; ++i) slots.emplace_back(i, "Truck");
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
    for (auto& slot : slots) {
        if (slot.getId() == slotId) {
            slot.release();
            break;
        }
    }
}

void ParkingLot::displayStatus() const {
    for (const auto& slot : slots) {
        cout << "Slot " << slot.getId() << " (" << slot.getAllowedType() << ") - "
             << (slot.occupied() ? "Occupied" : "Available") << endl;
    }
}