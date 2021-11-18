#include "Iterator.h"


Iterator::Iterator(Field* fld) : field(fld) {
    pos = sf::Vector2i(0, 0);
    cur_cell = (*field)[pos];
    finish = false;
}



Cell& Iterator::get() {
    return cur_cell;
}

void Iterator::operator++() {
    if (pos.x < field->get_size().x - 1) pos.x++;
    else {
        pos.y++;
        pos.x = 0;
        if (pos.y == field->get_size().y) finish = true;
    }
    if (!finish) cur_cell = (*field)[pos];
}


bool Iterator::end() {
    return finish;
}