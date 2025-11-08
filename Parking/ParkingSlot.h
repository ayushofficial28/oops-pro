#pragma once
#include <string>
#include <memory>
#include "../Vehicle/Vehicle.h"
using namespace std;

// Represents a single parking slot with type restriction and billing logic
class ParkingSlot {
private:
    int slotId;                     // Unique identifier for the slot
    string allowedType;            // Vehicle type allowed (e.g., Car, Bike, Truck)
    bool isOccupied;               // Occupancy status
    shared_ptr<Vehicle> parkedVehicle; // Pointer to the parked vehicle (if any)
    int charge;                    // Parking fee for this slot

public:
    // Initializes slot with ID, allowed vehicle type, and charge
    ParkingSlot(int id, string type, int charge);

    // Checks if the slot can accept the given vehicle
    bool canPark(shared_ptr<Vehicle> v);

    // Parks the vehicle in the slot
    void park(shared_ptr<Vehicle> v);

    // Releases the slot and prompts for payment
    void release();

    // Returns whether the slot is currently occupied
    bool occupied() const;

    // Returns the slot ID
    int getId() const;

    // Returns the allowed vehicle type for this slot
    string getAllowedType() const;
};