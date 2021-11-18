#pragma once
#include "../Field/Field.h"

class Iterator {
    Field* field;

    Cell cur_cell;

    sf::Vector2i pos;

    bool finish;
public:
    Iterator(Field*);

    Cell& get();

    void operator++();

    bool end();
};

