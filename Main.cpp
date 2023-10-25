#include <iostream>
#include <string>
#include "Plateau.hpp"
#include "Cell.hpp"

int main(int argc, char const* argv[])
{
    int column, line;
    do {
        std::cout << "Quelle taille de plateau souhaitez-vous ? (ex: 3 3)" << std::endl;
        std::cin >> column >> line;
        if (column <= 0 || line <= 0)
            std::cout << "La taille du plateau doit être supérieure à 0" << std::endl;
    } while (column <= 0 || line <= 0);
    std::cout << "Vous avez choisi un plateau de taille " << column << " x " << line << std::endl;

    std::cout << std::endl;

    std::string tore;
    do {
        std::cout << "Voulez-vous que le plateau soit un tore ? (y/n)" << std::endl;
        std::cin >> tore;
    } while (tore != "y" && tore != "n");

    bool t = (tore == "y");

    Plateau p(column, line, t);
    std::cout << p << std::endl;

    std::cout << "taille :" << p.getSize()[0] << " x " << p.getSize()[1] << std::endl;

    p.setNeighbour(0, 0);
    int nbvoisin = p.getBoard()[0][0].getNbNeighbour();
    std::cout << nbvoisin << std::endl;
}