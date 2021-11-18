#include "Cell.h"


void Cell::clone(Cell& rhs) {
    position = rhs.position;
    inf = rhs.inf;
}
void Cell::move(Cell&& rhs) {
    if (this != &rhs) {
        std::swap(inf, rhs.inf);
        std::swap(position, rhs.position);
    }
}

Cell::Cell() = default;

Cell::Cell(sf::Vector2i pos, cell_info ci) : position(pos), inf(ci) {}//std::cout << "Constructor\n";}

Cell::Cell(Cell& rhs) { clone(rhs); }// std::cout << "Cell&"; } //copy 

Cell::Cell(Cell&& rhs) noexcept { move(std::move(rhs)); }//std::cout << "Cell&&";  } //move

Cell& Cell::operator=(Cell& rhs) { //copy assignment
    if (this != &rhs) {
        clone(rhs);
    }
    //std::cout << "Celloperator=&";
    return *this;
}

Cell& Cell::operator=(Cell&& rhs) noexcept { //move assignment
    move(std::move(rhs));
    //std::cout << "Celloperator=&&";
    return *this;
}

Cell& Cell::operator=(cell_info rhs) {
    this->inf = rhs;
    return *this;
}