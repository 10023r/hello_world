#pragma once
#include "../Cell/Cell.h"
#include <vector>
#include "../Power/Power.h"


class Field {
protected:
    Cell** field;
    sf::Vector2u size;
    sf::Vector2i heroPos;
    std::vector<sf::Vector3i> enemyPos;
    std::vector<Power> powers;
    sf::Vector2i exitPos;

public:
    Field(sf::Vector2u, cell_info**);

    Field(const Field&);

    Field(Field&&) noexcept;

    Field& operator=(const Field&);

    Field& operator=(Field&&) noexcept;

    Cell& operator[](sf::Vector2i);

    bool operator==(Field& rhs);

    ~Field();

    sf::Vector2i& getHeroPos();

    std::vector<sf::Vector3i>& getEnemyPos();

    std::vector<Power>& getPowersPos();

    sf::Vector2i& getExitPos();

    sf::Vector2u get_size();

    Cell** getCells();

private:
    void clone(const Field&);
    void move_field(Field&&);
};

