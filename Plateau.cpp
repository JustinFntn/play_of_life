#include "Plateau.hpp"

Plateau::Plateau()
{
    this->tore = false;
    this->board.resize(10, std::vector<Cell>(10));
}

Plateau::Plateau(int m, int n, bool tore = false)
{
    this->tore = tore;
    this->board.resize(m, std::vector<Cell>(n));
}

Plateau::~Plateau()
{
}

bool Plateau::getTore() const
{
    return this->tore;
}

std::vector<std::vector<Cell> > Plateau::getBoard() const
{
    return this->board;
}

// int main(int argc, char const* argv[])
// {
//     std::cout << "Quelle taille de plateau souhaitez-vous ?" << std::endl;
//     int c, l;
//     std::cin >> c >> l;
//     printf("Vous avez choisi un plateau de taille %d x %d\n", c, l);

//     Plateau p(10, 10);
// }