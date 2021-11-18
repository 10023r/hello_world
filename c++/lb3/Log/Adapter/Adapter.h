#pragma once
#include "../../Creature/Creature.h"
#include "../../Map/Map.h"

class Adapter {
public:
    virtual bool hasChanged() = 0;
    virtual ~Adapter() {};
};

