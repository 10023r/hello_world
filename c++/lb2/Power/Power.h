#pragma once
#include "../Cell/Cell.h"

class PowerInteface {
public:
    virtual sf::Vector2i& getPos() = 0;
    virtual cell_info getType() = 0;

};

class Power : private PowerInteface {
    sf::Vector2i pos;
    cell_info type;
public:

    Power(sf::Vector2i, cell_info);

    sf::Vector2i& getPos();

    cell_info getType();


};
