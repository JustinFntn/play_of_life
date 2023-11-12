#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Cell.hpp"
#include <iostream>
#include <vector>
#include <ostream>

class Plateau
{
private:
    bool tore;
    std::vector<std::vector<Cell>  > board;

public:
    Plateau();
    Plateau(int m, int n, bool tore = false);
    ~Plateau();

    bool getTore() const;
    std::vector<std::vector<Cell> > getBoard() const;

    void setNeighbour(int i, int j);
    int* getSize() const;

    void setCellState(int i, int j);

    void updateBoard();

    void state();

    friend std::ostream& operator<<(std::ostream& os, Plateau& p);
};
#endif