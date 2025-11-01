#pragma once
#include <string>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
public:
    Vehicle(string plate);
    virtual string getType() const = 0;
    string getLicensePlate() const;
    virtual ~Vehicle() {}
};