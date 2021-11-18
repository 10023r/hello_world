#pragma once
#include "../Creature/Creature.h"

class Hero : public Creature {
public:
    Hero(sf::Vector2f pos);

    sf::Sprite& update(float time, int& dir, Field* field);

    void pickUpPower(Field* fld, sf::FloatRect prevRect);

    /*void attack(Enemy* enemy) {
        if (enemy->getAttributes()->armor > 0) {
            enemy->getAttributes()->armor -= attr->dmg;
            if (enemy->getAttributes()->armor < 0) { enemy->getAttributes()->hp += enemy->getAttributes()->armor; }
        }
        else {
            enemy->getAttributes()->hp -= attr->dmg;
        }

    }*/
    bool isOnTheExitDoor(sf::Vector2i&);
};

