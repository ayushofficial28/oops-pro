#pragma once
#include <string>
#include <memory>
#include "../Vehicle/Vehicle.h"
using namespace std;

class ParkingSlot {
private:
    int slotId;
    string allowedType;
    bool isOccupied;
    shared_ptr<Vehicle> parkedVehicle;
public:
    ParkingSlot(int id, string type);
    bool canPark(shared_ptr<Vehicle> v);
    void park(shared_ptr<Vehicle> v);
    void release();
    bool occupied() const;
    int getId() const;
    string getAllowedType() const;
};