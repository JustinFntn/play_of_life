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

    void setState(bool state);
    void setNbNeighbour(int nb_neighbour);

    void updateState();

    friend std::ostream& operator<<(std::ostream& os, Cell& c);
};

#endif
