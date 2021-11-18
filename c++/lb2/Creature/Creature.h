#pragma once
#include <SFML/Graphics.hpp>
#include "../Map/Map.h"
#include "../Attribute/Attribute.h"

class CreatureInterface {
    virtual sf::Sprite& update(float time, int& dir, Field* field) = 0;
    virtual bool alive() = 0;
};

class Creature : private CreatureInterface {
protected:
    Attribute* attr;
public:
    Creature(sf::Vector2f pos, bool isHero, char type = '0');

    bool alive();

    virtual sf::Sprite& update(float time, int& dir, Field* field);

    int intersectionWithMap(Field* field, sf::FloatRect prevRect);

    Attribute* getAttribute();

    ~Creature();
};

