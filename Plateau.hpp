#ifndef PLATEAU_HPP
#define PLATEAU_HPP
#include "Cell.hpp"
#include <iostream>
#include <vector>

class Plateau
{
private:
    bool tore;
    std::vector<std::vector<Cell>  >board;

public:
    Plateau();
    Plateau(int m, int n, bool tore);
    ~Plateau();
    bool getTore() const;
    std::vector<std::vector<Cell> > getBoard() const;
};
#endif