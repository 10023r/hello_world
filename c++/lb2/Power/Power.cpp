#include "Power.h"


Power::Power(sf::Vector2i pos, cell_info type) : pos(pos), type(type) {}

sf::Vector2i& Power::getPos() { return pos; }

cell_info Power::getType() { return type; }

