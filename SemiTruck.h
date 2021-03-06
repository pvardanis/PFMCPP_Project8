#pragma once
#include "Vehicle.h"

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string& n);
    
    void slowDown();
    void pushToLimits();
    void setSpeed(int s) override;
};
