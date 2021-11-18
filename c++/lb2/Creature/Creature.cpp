#include "Creature.h"

Creature::Creature(sf::Vector2f pos, bool isHero, char type) {
    if (isHero) {
        attr = new Attribute(100, 25, 20, pos, new Picture("./images/yoda.png", 32, 48));
        attr->speed = 100.0f;
    }
    else {
        switch (type) {
        case'1':
            attr = new Attribute(40, 10, 10, pos, new Picture("./images/stormtrooper.png", 32, 48));
            attr->speed = 70.0f;
            break;
        case '2':
            attr = new Attribute(50, 20, 15, pos, new Picture("./images/darthmaul.png", 32, 48));
            attr->speed = 75.0f;
            break;
        case '3':
            attr = new Attribute(60, 25, 20, pos, new Picture("./images/darthvader.png", 32, 48));
            attr->speed = 80.0f;
        }

    }
    attr->pic->getSprite().setTextureRect(sf::IntRect(0, 0, 32, 48));
    attr->pic->getSprite().setPosition(pos);
}


bool Creature::alive() {
    return !(attr->dead);
}

sf::Sprite& Creature::update(float time, int& dir, Field* field) {
    float dx = 0.0f, dy = 0.0f;
    sf::FloatRect prevRect = attr->pic->getSprite().getGlobalBounds();
    switch (dir)
    {
    case 3:
        dx = 0; dy = -attr->speed;
        attr->curFrame += 9.0f * time / 1000;
        break;
    case 2:
        dx = attr->speed; dy = 0;
        attr->curFrame += 9.0f * time / 1000;
        break;
    case 0:
        dx = 0; dy = attr->speed;
        attr->curFrame += 9.0f * time / 1000;
        break;
    case 1:
        dx = -attr->speed; dy = 0;
        attr->curFrame += 9.0f * time / 1000;
        break;
    }
    if (attr->curFrame >= 4) attr->curFrame -= 4;

    attr->pos.x += dx * time / 1000;
    attr->pos.y += dy * time / 1000;
    attr->pic->getSprite().setPosition(attr->pos);
    attr->pic->getSprite().setTextureRect(sf::IntRect(32 * int(attr->curFrame), dir * 48, 32, 48));

    switch (intersectionWithMap(field, prevRect)) {
    case 0:
        attr->pos.y -= dy * time / 1000;
        attr->pic->getSprite().setPosition(attr->pos);
        dir = rand() % 4;
        break;
    case 1:
        attr->pos.x -= dx * time / 1000;
        attr->pic->getSprite().setPosition(attr->pos);
        dir = rand() % 4;
        break;
    case 2:
        attr->pos.x -= dx * time / 1000;
        attr->pic->getSprite().setPosition(attr->pos);
        dir = rand() % 4;
        break;
    case 3:
        attr->pos.y -= dy * time / 1000;
        attr->pic->getSprite().setPosition(attr->pos);
        dir = rand() % 4;
    }
    attr->dir = dir;
    return attr->pic->getSprite();
}


int Creature::intersectionWithMap(Field* field, sf::FloatRect prevRect) {
    for (Iterator it = field; !it.end(); ++it) {
        cell_info cur_content = it.get().content();
        if (cur_content == W) {
            sf::FloatRect tileRect = sf::FloatRect(it.get().get_pos().x * 50.0f, it.get().get_pos().y * 50.0f, 50.0f, 50.0f);
            sf::FloatRect nowRect = attr->pic->getSprite().getGlobalBounds();
            if (tileRect.intersects(nowRect)) {
                if (nowRect.top + nowRect.height > tileRect.top && prevRect.top + prevRect.height <= tileRect.top && tileRect.left + tileRect.width < nowRect.left + 7.0f) {
                    return 0;
                }
                else if (nowRect.left < tileRect.left + tileRect.width && prevRect.left >= tileRect.left + tileRect.width && nowRect.top + 7.0f < tileRect.top + tileRect.height) {
                    return 1;
                }
                else if (nowRect.left + nowRect.width > tileRect.left && prevRect.left + prevRect.width <= tileRect.left && nowRect.top + 7.0f < tileRect.top + tileRect.height) {
                    return 2;
                }
                else if (nowRect.top + 7.0f < tileRect.top + tileRect.height && prevRect.top <= tileRect.top + tileRect.height) {
                    return 3;
                }
            }
        }
    }
    return -1;
}

Attribute* Creature::getAttribute() {
    return attr;
}


Creature::~Creature() {
    delete attr;
    attr = nullptr;
}