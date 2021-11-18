#pragma once
#include "Adapter.h"

class MapAdapter : public Adapter {
    Field prevCond;
    Field* curCond;
public:
    MapAdapter(Map* map);

    bool hasChanged();

    friend std::ostream& operator<<(std::ostream& os, MapAdapter* adp);
};