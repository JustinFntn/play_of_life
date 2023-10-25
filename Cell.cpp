#include "Cell.hpp"

Cell::Cell()
{
    this->state = false;
    this->nb_neighbour = 0;
}

Cell::~Cell()
{
}

bool Cell::getState() const
{
    return this->state;
}

int Cell::getNbNeighbour() const
{
    return this->nb_neighbour;
}

void Cell::setState(bool state)
{
    this->state = state;
}

void Cell::setNbNeighbour(int nb_neighbour)
{
    this->nb_neighbour = nb_neighbour;
}

void Cell::updateState()
{
    if (this->state) {
        if (this->nb_neighbour < 2 || this->nb_neighbour > 3)
            this->state = false;
    }
    else
    {
        if (this->nb_neighbour == 3)
            this->state = true;
    }
}

std::ostream& operator<<(std::ostream& os, Cell& c)
{
    if (c.state)
        os << "1";
    else
        os << "0";
    return os;
}