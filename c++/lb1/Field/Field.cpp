#include "Field.h"

Field::Field(sf::Vector2u sz, cell_info** f) : size(sz) { //constructor
    field = new Cell* [size.y];
    for (int y = 0; y < size.y; y++) {
        field[y] = new Cell[size.x];
        for (int x = 0; x < size.x; x++) {
            if (f[y][x] == H) {
                heroPos = sf::Vector2i(x, y);
                f[y][x] = E;
            }
            else if (f[y][x] == F1 || f[y][x] == F2 || f[y][x] == F3) {
                enemyPos.push_back(sf::Vector3i(x, y, f[y][x]));
                f[y][x] = E;
            }
            else if (f[y][x] == P1 || f[y][x] == P2 || f[y][x] == P3) {
                powers.push_back(Power(sf::Vector2i(x, y), f[y][x]));
            }
            else if (f[y][x] == OUT) {
                exitPos = sf::Vector2i(x, y);
            }
            field[y][x] = Cell(sf::Vector2i(x, y), f[y][x]);
        }
    }
}

Field::~Field() {
    for (size_t y = 0; y < size.y; y++) {
        delete[] field[y];
    }
    delete[] field;
    //std::cout << "~Field";
}

void Field::clone(const Field& rhs) { //clone
    size = rhs.size;
    field = new Cell* [size.y];
    for (size_t y = 0; y < size.y; y++) {
        field[y] = new Cell[size.x];
        for (size_t x = 0; x < size.x; x++) {
            field[y][x] = (rhs.field)[y][x];
        }
    }
}

void Field::move_field(Field&& rhs) { //move_field
    std::swap(size, rhs.size);
    std::swap(field, rhs.field);
    rhs.size = sf::Vector2u(0, 0);
    rhs.field = nullptr;
}

Field::Field(const Field& rhs) {     //copy
    clone(rhs); //std::cout << "Field&";
}

Field::Field(Field&& rhs) noexcept {         //move
    move_field(std::move(rhs)); }//std::cout << "Field&&"; }

Field& Field::operator=(const Field& rhs) { //copy assignment
    if (this != &rhs) {
        this->Field::~Field();
        this->clone(rhs);
        //std::cout << "Fieldoperator&";
    }
    return *this;
}

Field& Field::operator=(Field&& rhs) noexcept { //move assignment
    if (this != &rhs) {
        this->Field::~Field();
        move_field(std::move(rhs));
        //std::cout << "Fieldoperator&&";
    }
    return *this;
}

bool Field::operator==(Field& rhs) {

    //bool cells = true;
    for (int i = 0; i < size.y; i++) {
        for (int j = 0; j < size.x; j++) {
            if (field[i][j].content() != rhs.field[i][j].content() || field[i][j].get_pos().x != rhs.field[i][j].get_pos().x || field[i][j].get_pos().y != rhs.field[i][j].get_pos().y)
                return false;
                //cells = false;
        }
    }
    return true;
    //if (cells && size.x == rhs.size.x && size.y == rhs.size.y)
    //    return true;
    //return false;
}

Cell& Field::operator[](sf::Vector2i i) {
    return field[i.y][i.x];
}


sf::Vector2i& Field::getHeroPos() {
    return heroPos;
}

std::vector<sf::Vector3i>& Field::getEnemyPos() {
    return enemyPos;
}

std::vector<Power>& Field::getPowersPos() {
    return powers;
}

sf::Vector2u Field::get_size() { return size; }

sf::Vector2i& Field::getExitPos() { return exitPos; }

Cell** Field::getCells() { return field; }