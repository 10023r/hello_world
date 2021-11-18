#pragma once
#include "Adapter.h"

class CreatureAdapter : public Adapter {
    Attribute prevCondition;
    Attribute* curCondition;
public:
    CreatureAdapter(Creature* crt);

    bool hasChanged();

    friend std::ostream& operator<<(std::ostream& os, CreatureAdapter* adp);
};