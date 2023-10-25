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

void Plateau::updateBoard() {
    std::vector<Cell>::iterator x;
    std::vector<std::vector<Cell>  >::iterator y;
    for (; y != this->board.end(); y++)
    {
        for (; x != y->end(); x++)
        {
            x->updateState();
        }
    }
}

std::ostream& operator<<(std::ostream& os, Plateau& p)
{
    for (int i = 0; i < p.board.size(); i++)
    {
        for (int j = 0; j < p.board[i].size(); j++)
        {
            os << p.board[i][j];
        }
        os << std::endl;
    }
    return os;
}