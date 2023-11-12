#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include "Plateau.hpp"
#include "Cell.hpp"

int main(int argc, char const* argv[])
{
    // choix de la taille
    int column, line;
    do {
        std::cout << "Quelle taille de plateau souhaitez-vous ? (ex: 3 3)" << std::endl;
        std::cin >> column >> line;
        if (column <= 0 || line <= 0)
            std::cout << "La taille du plateau doit être supérieure à 0" << std::endl;
    } while (column <= 0 || line <= 0);
    std::cout << "Vous avez choisi un plateau de taille " << column << " x " << line << std::endl;

    std::cout << std::endl;

    // choix de faire un tore ou non
    std::string tore;
    do {
        std::cout << "Voulez-vous que le plateau soit un tore ? (y/n)" << std::endl;
        std::cin >> tore;
    } while (tore != "y" && tore != "n");

    bool t = (tore == "y");

    // Création du plateau
    Plateau p(column, line, t);
    std::cout << p << std::endl;

    // déclaration des variables pour l'initialisation
    std::string coordonnees;
    int x, y;
    std::istringstream iss;

    // déclaration des variables pour le calcul des itérations
    int n, i;

    int choice;
    do {
        std::cout << "============MENU============" << std::endl;
        std::cout << "1. initialisation des cellules" << std::endl;
        std::cout << "2. calculer n itérations" << std::endl;
        std::cout << "3. clear le plateau" << std::endl;
        std::cout << "4. statistique" << std::endl;
        std::cout << "5. quitter" << std::endl;
        std::cout << "============================" << std::endl;
        std::cout << "Votre choix ?" << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
        switch (choice) {
        case 1:
            // Initialisation du plateau
            std::cout << "Vous allez maintenant initialiser le plateau en indiquant les cellules vivantes (saisir \"stop\" lorsque vous voulez finir l'initialisation)" << std::endl;
            std::cin.ignore();
            do {
                std::cout << "Coordonnées de la cellule à modifier ? (ex: 1 1)" << std::endl;
                std::getline(std::cin, coordonnees);
                iss.str(coordonnees);
                // Extraction des deux premiers nombres
                if (iss >> x >> y) {
                    std::cout << "Vous avez choisi la cellule " << x << " " << y << std::endl;
                    p.setCellState(x, y);
                    std::cout << p << std::endl;
                    iss.clear();
                }
                else if (coordonnees == "stop")
                {
                    std::cout << "Vous avez fini l'initialisation\n" << std::endl;
                }
                else {
                    std::cout << "Format invalide. Veuillez entrer deux nombres séparés par un espace." << std::endl;
                    iss.clear();
                }
            } while (coordonnees != "stop");
            break;
        case 2:
            std::cout << "Combien d'itérations voulez-vous calculer ?" << std::endl;
            std::cin >> n;
            // Génération des cellules
            for (i = 0; i < n; i++) {
                std::cout << "Génération " << i + 1 << std::endl;
                p.updateBoard();
                std::cout << p << std::endl;
                sleep(3);
            }
            break;
        case 3:
            p = Plateau(column, line, t);
            std::cout << p << std::endl;
            break;
        case 4:
            p.state();
            break;
        case 5:
            std::cout << "Au revoir !" << std::endl;
            break;
        default:
            std::cout << "Choix invalide. Veuillez choisir un numéro de 1 à 5." << std::endl;
            break;
        }
    } while (choice != 5);
}