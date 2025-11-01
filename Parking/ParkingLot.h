#pragma once
#include <vector>
#include "ParkingSlot.h"
using namespace std;

class ParkingLot {
private:
    vector<ParkingSlot> slots;
public:
    ParkingLot();
    ParkingSlot* allocateSlot(shared_ptr<Vehicle> v);
    void releaseSlot(int slotId);
    void displayStatus() const;
};