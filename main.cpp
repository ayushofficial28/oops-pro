#include <iostream>
#include <memory>
#include <limits>
#include "Vehicle/Car.h"
#include "Vehicle/Bike.h"
#include "Vehicle/Truck.h"
#include "Parking/ParkingLot.h"
using namespace std;

shared_ptr<Vehicle> createVehicle() {
    int type;
    string plate;
    cout << "Enter Vehicle Type:\n1. Car\n2. Bike\n3. Truck\nChoice: ";
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter License Plate: ";
    getline(cin, plate);

    switch (type) {
        case 1: return make_shared<Car>(plate);
        case 2: return make_shared<Bike>(plate);
        case 3: return make_shared<Truck>(plate);
        default: cout << "Invalid type.\n"; return nullptr;
    }
}

int main() {
    ParkingLot lot;
    int choice;

    while (true) {
        cout << "\n=== Smart Parking System ===\n";
        cout << "1. Park a Vehicle\n";
        cout << "2. Release a Slot\n";
        cout << "3. View Slot Status\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
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
                int slotId;
                cout << "Enter Slot ID to release: ";
                cin >> slotId;
                lot.releaseSlot(slotId);
                cout << "Slot " << slotId << " released.\n";
                break;
            }
            case 3:
                lot.displayStatus();
                break;
            case 4:
                cout << "Exiting Smart Parking System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}