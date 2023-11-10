#include "Taquin.hpp"

Taquin::Taquin(int k)
{
    _k = k;
    int val = 1;
    std::cout << "\nCreation of the initial board." << std::endl;
    for (int i = 0; i < _k * _k; i++)
        _board.push_back(val++);

    _board.pop_back();
    _board.push_back(0);

    std::random_shuffle(_board.begin(), _board.end());

    _mooves = 0;

    std::cout << "\nState of the board: " << std::endl;
    print();
}

Taquin::Taquin(std::vector<int> board, int mooves, int k)
{
    _board = board;
    _mooves = mooves;
    _k = k;
}

int Taquin::Hamming()
{
    return 0;
}

int Taquin::Manhattan()
{
    int manhattan = 0;
    int val = 1, currCol = 0, currRaw = 0;
    for (int i = 0; i < _k * _k; i++)
    {
        currRaw = i / _k;
        currCol = i - (_k * currRaw);

        if (_board[i] != val % (_k * _k))
        {
            if (_board[i] != 0)
            {
                int goalRaw = (_board[i] - 1) / _k;
                int goalCol = (_board[i] - 1) - _k * goalRaw;

                manhattan += abs(goalCol - currCol) + abs(goalRaw - currRaw);
            }
            else
            {
                int goalRaw = 2;
                int goalCol = 2;

                manhattan += abs(goalCol - currCol) + abs(goalRaw - currRaw);
            }
        }

        val++;
    }
    return manhattan;
}

void Taquin::print()
{
    int index = 0;
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
            std::cout << _board[index++] << " ";
        std::cout << std::endl;
    }
}
