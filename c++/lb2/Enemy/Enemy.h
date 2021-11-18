#pragma once
#include "../Creature/Creature.h"


class Enemy : public Creature {
public:
    Enemy(sf::Vector2f pos, char type);
};