#include "Log.h"










Log::Log(Adapter* lc, bool type) : loggingClass(lc), crtAdp(type) {
    fs.open("myLogs.txt", std::fstream::out | std::fstream::app);
}

void Log::follow(bool toConsole, bool toFile) {
    if (loggingClass->hasChanged()) {
        if (toConsole) {
            if (crtAdp)
                std::cout << (CreatureAdapter*)loggingClass;
            else
                std::cout << (MapAdapter*)loggingClass;
            
        }
        if (toFile) {
            if (crtAdp)
                fs << (CreatureAdapter*)loggingClass;
            else
                fs << (MapAdapter*)loggingClass;
            
            fs << loggingClass;
        }
    }
}

Log::~Log() {
    std::cout << "closed file\n";
    fs.close();
    delete loggingClass;
}