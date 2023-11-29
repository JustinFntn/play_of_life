# Jeu de la vie

## Introduction

Il s'agit d'un jeu de simulation de cellules. Il a été inventé par John Horton Conway en 1970. Il est le premier exemple d'un automate cellulaire. Il est très populaire dans la communauté scientifique et dans la communauté des hackers.

## le nécessaire

-   [ ] de quoi compiler du C++ (g++ ou clang++)
-   [ ] de quoi faire du CMake (cmake)
-   [ ] installer qt6
-   [ ] modifier le fichier CMakeLists.txt pour que les variables `QT6_DIR` et `CMAKE_PREFIX_PATH` correspondent a votre installation de qt6
-   [ ] creer un dossier build
-   [ ] executer la commande `cmake ..` dans le dossier build

## fonctionnement de l'interface

vous pouvez cliquer sur les cellules pour changer leur état. et ensuite les boutons sur la droite vous permettent de lancer la simulation.

-   play : lance la simulation et itere a l'infini toutes les 0.5 secondes
-   pause : met la simulation en pause
-   reset : remet la grille a l'etat initial
-   itération suivante : itere une fois la simulation
