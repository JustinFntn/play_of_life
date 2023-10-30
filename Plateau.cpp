#include "Plateau.hpp"

Plateau::Plateau()
{
    this->tore = false;
    this->board.resize(10, std::vector<Cell>(10));
}

Plateau::Plateau(int m, int n, bool tore)
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

/**
 * Sets the number of neighbors for a given cell on the board.
 *
 * @param i The row index of the cell.
 * @param j The column index of the cell.
 */
void Plateau::setNeighbour(int i, int j)
{
    int nb_neighbour = 0;
    int* size = this->getSize();
    int size_x = size[0], size_y = size[1];
    delete[] size;
    if (this->tore) {
        nb_neighbour += this->board[(i - 1) % size_x][(j - 1) % size_y].getState() ? 1 : 0;
        nb_neighbour += this->board[(i - 1) % size_x][j].getState() ? 1 : 0;
        nb_neighbour += this->board[(i - 1) % size_x][(j + 1) % size_y].getState() ? 1 : 0;
        nb_neighbour += this->board[i][(j - 1) % size_y].getState() ? 1 : 0;
        nb_neighbour += this->board[i][(j + 1) % size_y].getState() ? 1 : 0;
        nb_neighbour += this->board[(i + 1) % size_x][(j - 1) % size_y].getState() ? 1 : 0;
        nb_neighbour += this->board[(i + 1) % size_x][j].getState() ? 1 : 0;
        nb_neighbour += this->board[(i + 1) % size_x][(j + 1) % size_y].getState() ? 1 : 0;
    }
    else
    {
        if (i - 1 >= 0 && j - 1 >= 0) nb_neighbour += this->board[i - 1][j - 1].getState() ? 1 : 0;
        if (i - 1 >= 0) nb_neighbour += this->board[i - 1][j].getState() ? 1 : 0;
        if (i - 1 >= 0 && j + 1 < size_y) nb_neighbour += this->board[i - 1][j + 1].getState() ? 1 : 0;
        if (j - 1 >= 0) nb_neighbour += this->board[i][j - 1].getState() ? 1 : 0;
        if (j + 1 < size_y) nb_neighbour += this->board[i][j + 1].getState() ? 1 : 0;
        if (i + 1 < size_x && j - 1 >= 0) nb_neighbour += this->board[i + 1][j - 1].getState() ? 1 : 0;
        if (i + 1 < size_x) nb_neighbour += this->board[i + 1][j].getState() ? 1 : 0;
        if (i + 1 < size_x && j + 1 < size_y) nb_neighbour += this->board[i + 1][j + 1].getState() ? 1 : 0;
    }
    this->board[i][j].setNbNeighbour(nb_neighbour);
}

int* Plateau::getSize() const
{
    int* size = new int[2];
    size[0] = this->board[0].size();
    size[1] = this->board.size();
    return size;
}

void Plateau::setCellState(int i, int j, bool state)
{
    this->board[i][j].setState(state);
}

void Plateau::updateBoard() {
    int* size = this->getSize();
    int size_x = size[0], size_y = size[1];
    delete[] size;
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            this->setNeighbour(i, j);
        }
    }
    for (int i = 0; i < size_x; i++)
    {
        for (int j = 0; j < size_y; j++)
        {
            this->board[i][j].updateState();
        }
    }
}

void Plateau::state() {
    int life = 0, death = 0, total = 0;
    std::vector<std::vector<Cell> >::iterator it = this->board.begin();
    std::vector<Cell>::iterator it2;
    for (; it != this->board.end(); it++)
    {
        for (it2 = it->begin(); it2 != it->end(); it2++)
        {
            if (it2->getState())
                life++;
            else
                death++;
            total++;
        }
    }
    std::cout << "Nombre de cellules vivantes : " << life << std::endl;
    std::cout << "Nombre de cellules mortes : " << death << std::endl;
    std::cout << "Soit " << life / (float)total * 100 << "% de cellules vivantes" << std::endl;
}

std::ostream& operator<<(std::ostream& os, Plateau& p)
{
    std::cout << std::endl;
    for (int i = 0; i < p.board.size(); i++)
    {
        for (int j = 0; j < p.board[i].size(); j++)
        {
            os << p.board[i][j];
        }
        os << std::endl;
    }
    std::cout << std::endl;
    return os;
}