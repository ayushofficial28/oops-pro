#pragma once
#include <vector>
#include "ParkingSlot.h"
using namespace std;

// Manages a collection of parking slots and handles allocation/release logic
class ParkingLot {
private:
    vector<ParkingSlot> slots; // All parking slots in the lot

public:
    // Initializes the parking lot with predefined slots
    ParkingLot();

    // Allocates a suitable slot for the given vehicle
    ParkingSlot* allocateSlot(shared_ptr<Vehicle> v);

    // Releases a slot based on its ID
    void releaseSlot(int slotId);

    // Displays current status of all slots (occupied/available)
    void displayStatus() const;
};