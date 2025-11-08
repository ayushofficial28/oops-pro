#include "ParkingLot.h"
#include <iostream>
using namespace std;

// Constructor initializes slots by type and cost
ParkingLot::ParkingLot() {
    // Create 5 Car slots with cost 40
    for (int i = 0; i < 5; ++i)
        slots.emplace_back(i, "Car", 40);

    // Create 3 Bike slots with cost 20
    for (int i = 5; i < 8; ++i)
        slots.emplace_back(i, "Bike", 20);

    // Create 2 Truck slots with cost 80
    for (int i = 8; i < 10; ++i)
        slots.emplace_back(i, "Truck", 80);
}

// Attempts to allocate a slot for the given vehicle
ParkingSlot* ParkingLot::allocateSlot(shared_ptr<Vehicle> v) {
    for (auto& slot : slots) {
        // Check if slot can accommodate the vehicle
        if (slot.canPark(v)) {
            slot.park(v); // Park the vehicle
            return &slot; // Return pointer to allocated slot
        }
    }
    return nullptr; // No suitable slot found
}

// Releases a slot based on slot ID
void ParkingLot::releaseSlot(int slotId) {
    if (slotId >= 0 && slotId < 10) {
        ParkingSlot* slot = &slots[slotId];
        slot->release(); // Mark slot as available
    } else {
        cout << "Invalid slotId" << endl;
    }
}

// Displays current status of all slots
void ParkingLot::displayStatus() const {
    for (const auto& slot : slots) {
        cout << "Slot " << slot.getId() << " (" << slot.getAllowedType() << ") - "
             << (slot.occupied() ? "Occupied" : "Available") << endl;
    }
}