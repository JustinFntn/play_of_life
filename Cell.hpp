#ifndef CELL_HPP
#define CELL_HPP
#include <iostream>
#include <ostream>

/**
 * @file Cell.hpp
 * @brief Déclaration de la classe Cell
 *
 * Ce fichier contient la déclaration de la classe Cell, qui représente une cellule du jeu de la vie.
 * Il définit une cellule par un booléen pour son état et un entier pour le nombre de voisins.
 *
 * @author Justin Fontaine
 * @date 20 novembre 2023
 */
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
