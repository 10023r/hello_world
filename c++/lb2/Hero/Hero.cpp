#include "Hero.h"

Hero::Hero(sf::Vector2f pos) : Creature(pos, true) {}

sf::Sprite& Hero::update(float time, int& dir, Field* field) {
    if (dir != -1) {
        this->attr->dir = dir;
        int tmpDir = dir;
        sf::FloatRect prevRect = attr->pic->getSprite().getGlobalBounds();
        sf::Sprite& res = Creature::update(time, tmpDir, field);
        pickUpPower(field, prevRect);
        return res;
    }
    return attr->pic->getSprite();
}

void Hero::pickUpPower(Field* fld, sf::FloatRect prevRect) {
    std::vector<Power> powers = fld->getPowersPos();
    for (int i = 0; i < powers.size(); i++) {
        sf::FloatRect curRect = attr->pic->getSprite().getGlobalBounds();
        //left = 12, top = 26, width = 10, height = 10
        curRect.left += 12; curRect.top += 26; curRect.width = 10; curRect.height = 10;
        if (curRect.intersects(sf::FloatRect(powers[i].getPos().x * 50.0f + 4.0f, powers[i].getPos().y * 50.0f + 8.0f, 36.0f, 24.0f))) {
            switch (powers[i].getType())
            {
            case P1:
                attr->dmg += 20;
                break;
            case P2:
                attr->armor += 25;
                break;
            case P3:
                attr->hp += 40;
            }
            (*fld)[powers[i].getPos()] = E;
            fld->getPowersPos().erase(fld->getPowersPos().begin() + i);
            return;
        }
    }
}

bool Hero::isOnTheExitDoor(sf::Vector2i& exitPos) {
    sf::FloatRect curRect = attr->pic->getSprite().getGlobalBounds();
    curRect.left += 12; curRect.top += 26; curRect.width = 10; curRect.height = 10;
    if (curRect.intersects(sf::FloatRect(exitPos.x * 50.0f, exitPos.y * 50.0f, 50.0f, 50.0f))) {
        return true;
    }
    return false;
}