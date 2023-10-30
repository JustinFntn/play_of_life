#include <iostream>
#include <string>
#include <unistd.h>
#include "Plateau.hpp"
#include "Cell.hpp"

int main(int argc, char const* argv[])
{
    // Création du plateau
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

    // Initialisation du plateau
    std::cout << "Vous allez maintenant initialiser le plateau en indiquant les cellules vivantes (saisir \"stop\" lorsque vous voulez finir l'initialisation)" << std::endl;
    std::string coordonnées;
    do {
        std::cout << "Coordonnées de la cellule à modifier ? (ex: 1 1)" << std::endl;
        std::cin >> coordonnées;
        if (coordonnées != "stop") {
            int x = std::stoi(coordonnées.substr(0, coordonnées.find(' ')));
            int y = std::stoi(coordonnées.substr(coordonnées.find(' ') + 1));
            std::cout << "Vous avez choisi la cellule " << x << " " << y << std::endl;
            p.setCellState(x, y, true);
        }
        std::cout << p << std::endl;
    } while (coordonnées != "stop");

    for (int i = 1; i < 11; i++) {
        sleep(3);
        std::cout << "Génération " << i + 1 << std::endl;
        p.updateBoard();
        std::cout << p << std::endl;
    }

    p.state();
}