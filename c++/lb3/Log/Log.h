#pragma once
//#include "Adapter/CreatureAdapter.h"
//#include "Adapter/MapAdapter.h"
#include "Adapter/CreatureAdapter.h"
#include "Adapter/MapAdapter.h"
#include <fstream>







class Log {
    Adapter* loggingClass;
    std::fstream fs;
    bool crtAdp;
public:
    Log(Adapter* lc, bool type);

    void follow(bool toConsole, bool toFile);

    ~Log();
};

