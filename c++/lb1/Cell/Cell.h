#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/*
0 - wall
  - empty
h - hero
e - enemy1
n - enemy2
m - enemy3
p - power1
o - power2
r - power3


*/
enum cell_info { E, H, F1, F2, F3, P1, P2, P3, W, IN, OUT };


/*static cell_info standard_map[LENGTH][WIDTH] = {
    {POWER, WALL , POWER, EMPTY, WALL , OUT  },
    {EMPTY, WALL , WALL , EMPTY, WALL , EMPTY},
    {EMPTY, EMPTY, ENEMY, EMPTY, WALL , EMPTY},
    {EMPTY, WALL , EMPTY, WALL , WALL , ENEMY},
    {HERO , WALL , EMPTY, WALL , WALL , EMPTY},
    {IN   , WALL , EMPTY, POWER, EMPTY, EMPTY}
};*/


class Cell_Interface {
public:
    virtual cell_info content() const = 0;
    virtual sf::Vector2i get_pos() const = 0;
};

class Cell : private Cell_Interface {
protected:
    sf::Vector2i position;
    cell_info inf;
public:
    Cell();

    Cell(sf::Vector2i, cell_info);//std::cout << "Constructor\n";}
    Cell(Cell&); //copy 
    Cell(Cell&&) noexcept; //move
    Cell& operator=(Cell&);
    Cell& operator=(Cell&&) noexcept;
    Cell& operator=(cell_info);

    cell_info content() const { return inf; };

    sf::Vector2i get_pos() const { return position; };
private:
    void clone(Cell&);
    void move(Cell&&);
};
