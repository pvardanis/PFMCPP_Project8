#include "Highway.h"

#include <cassert>
#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    if (auto* car = dynamic_cast<Car*>(v))
    {
        car -> closeWindows();
    }
    else if (auto* motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        motorcycle -> lanesplitAndRace();
    }
    else if (auto* semiTruck = dynamic_cast<SemiTruck*>(v))
    {
        semiTruck -> pushToLimits();        
    }
    else std::cout << "Wrong type of vehicle!" << std::endl;
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    if (auto* car = dynamic_cast<Car*>(v))
    {
        car -> tryToEvade();
    }
    else if (auto* motorcycle = dynamic_cast<Motorcycle*>(v))
    {
        motorcycle -> tryToEvade();
    }
    else if (auto* semiTruck = dynamic_cast<SemiTruck*>(v))
    {
        semiTruck -> slowDown();
    }
    else std::cout << "Wrong type of vehicle!" << std::endl;
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
