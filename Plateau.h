#ifndef PLATEAU_H
#define PLATEAU_H
#include <iostream>
#include <vector>
#include <ostream>
#include "Cell.hpp"

/**
 * @file Plateau.hpp
 * @brief Déclaration de la classe Plateau
 *
 * Ce fichier contient la déclaration de la classe Plateau, qui représente un plateau de jeu de la vie.
 * Il définit un plateau de jeu de la vie par un vecteur de Cellules et un booléen pour le tore.
 *
 * @author Justin Fontaine
 * @date 20 novembre 2023
 */
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
    void setTore(bool tore);
    std::vector<std::vector<Cell> > getBoard() const;

    void setNeighbour(int i, int j);
    int* getSize() const;

    void setCellState(int i, int j);

    void updateBoard();

    void state();

    friend std::ostream& operator<<(std::ostream& os, Plateau& p);
};
#endif