#include "SemiTruck.h"

SemiTruck::SemiTruck(const std::string& n) : Vehicle(n) {}

void SemiTruck::slowDown()
{
    std::cout << "No need to risk it!" << std::endl;
    setSpeed(20);
}

void SemiTruck::pushToLimits()
{
    std::cout << "ACAB!" << std::endl;
    setSpeed(140);
}

void SemiTruck::setSpeed(int s)
{
    std::cout << "This track is so difficult to drive!" << std::endl;
    speed = s;
}