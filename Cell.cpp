#include "Cell.hpp"

Cell::Cell()
{
    this->state = false;
    this->nb_neighbour = 0;
}

bool Cell::getState() const
{
    return this->state;
}

int Cell::getNbNeighbour() const
{
    return this->nb_neighbour;
}

Cell::~Cell()
{
}

std::ostream &operator<<(std::ostream &os, Cell &c)
{
    if (c.state)
        os << "1";
    else
        os << "0";
    return os;
}