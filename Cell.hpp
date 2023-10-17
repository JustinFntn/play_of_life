#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>
#include <ostream>

class Cell
{
private:
    bool state;
    int nb_neighbour;

public:
    Cell();
    ~Cell();
    bool getState() const;
    int getNbNeighbour() const;
    friend std::ostream &operator<<(std::ostream &os, Cell &c);
};

#endif
