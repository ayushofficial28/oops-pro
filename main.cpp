#include <iostream>
#include <memory>
#include <limits>
#include "Vehicle/Car.h"
#include "Vehicle/Bike.h"
#include "Vehicle/Truck.h"
#include "Parking/ParkingLot.h"
using namespace std;

// Factory function to create a Vehicle object based on user input
shared_ptr<Vehicle> createVehicle() {
    int type;
    string plate;

    // Prompt for vehicle type
    cout << "Enter Vehicle Type:\n1. Car\n2. Bike\n3. Truck\nChoice: ";
    cin >> type;

    // Flush leftover newline to prepare for getline
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Prompt for license plate
    cout << "Enter License Plate: ";
    getline(cin, plate);

    // Instantiate appropriate vehicle type
    switch (type) {
        case 1: return make_shared<Car>(plate);
        case 2: return make_shared<Bike>(plate);
        case 3: return make_shared<Truck>(plate);
        default:
            cout << "Invalid type.\n";
            return nullptr;
    }
}

int main() {
    ParkingLot lot; // Parking lot manager
    int choice;

    // Main CLI loop
    while (true) {
        // Display menu
        cout << "\n=== Smart Parking System ===\n";
        cout << "1. Park a Vehicle\n";
        cout << "2. Release a Slot\n";
        cout << "3. View Slot Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create vehicle and attempt to allocate a slot
                auto vehicle = createVehicle();
                if (vehicle) {
                    ParkingSlot* slot = lot.allocateSlot(vehicle);
                    if (slot)
                        cout << "Vehicle parked in slot " << slot->getId() << ".\n";
                    else
                        cout << "No available slot for this vehicle type.\n";
                }
                break;
            }
            case 2: {
                // Release a slot based on user input
                int slotId;
                cout << "Enter Slot ID to release: ";
                cin >> slotId;
                lot.releaseSlot(slotId);
                break;
            }
            case 3:
                // Display current slot occupancy
                lot.displayStatus();
                break;
            case 4:
                // Exit the system
                cout << "Exiting Smart Parking System. Goodbye!\n";
                return 0;
            default:
                // Handle invalid menu input
                cout << "Invalid choice. Try again.\n";
        }
    }
}