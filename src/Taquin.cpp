#include "Taquin.hpp"

Taquin::Taquin(int k)
{
    _k = k;
    _size = _k * _k;
    int val = 1;
    std::cout << "\nCreation of the initial board..." << std::endl;
    for (int i = 0; i < _size; i++)
        _board.push_back(val++);

    _board.pop_back();
    _board.push_back(0);

    _finalState = _board;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::shuffle(_board.begin(), _board.end(), e);

    _mooves = 0;

    std::cout << "\nState of the board: " << std::endl;
    Print();

    _hamming = Hamming();
    _Hpriority = _hamming;
    _manhattan = Manhattan();
    _Mpriority = _manhattan;

    _sourceBoard = nullptr; // This is the initial board: it is it's own source

    std::cout << "final state" << std::endl;
    int index = 0;
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
            std::cout << _finalState[index++] << " ";
        std::cout << std::endl;
    }
}

Taquin::Taquin(std::vector<int> board, int mooves, int k, Taquin *source)
{
    _board = board;
    _mooves = mooves;
    _k = k;
    _size = _k * _k;
    _hamming = Hamming();
    _Hpriority = _hamming + _mooves;
    _manhattan = Manhattan();
    _Mpriority = _manhattan + mooves;
    _sourceBoard = source;
}

int Taquin::Hamming()
{
    int hamming = 0;
    int val = 1;

    for (int i = 0; i < _size; i++)
    {
        if (_board[i] != val % _size)
            hamming += 1;
        val++;
    }

    return hamming;
}

int Taquin::Manhattan()
{
    int manhattan = 0;
    int val = 1, currCol = 0, currRaw = 0;
    for (int i = 0; i < _size; i++)
    {
        currRaw = i / _k;
        currCol = i - (_k * currRaw);

        if (_board[i] != val % _size)
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

void Taquin::Print()
{
    int index = 0;
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
            std::cout << _board[index++] << " ";
        std::cout << std::endl;
    }

    // std::cout << "mooves: " << _mooves << std::endl;
}

std::vector<Taquin> Taquin::GenerateNextStates()
{

    int index_Zero;
    int mooves = _mooves + 1;

    for (int i = 0; i < _size; i++)
    {
        if (_board[i] == 0)
        {
            index_Zero = i;
            break;
        }
    }

    std::vector<Taquin> tmpHerited;
    std::vector<int> tmpBoard;

    if (index_Zero - _k >= 0)
    {
        tmpBoard = _board;
        tmpBoard[index_Zero] = tmpBoard[index_Zero - _k];
        tmpBoard[index_Zero - _k] = 0;
        if (this->_sourceBoard == NULL || tmpBoard != this->_sourceBoard->_board)
        {
            Taquin newState(tmpBoard, mooves, _k, this);
            tmpHerited.push_back(newState);
            this->AddNeighbourg(newState);
        }
    }
    if (index_Zero + _k <= _size - 1)
    {
        tmpBoard = _board;
        tmpBoard[index_Zero] = tmpBoard[index_Zero + _k];
        tmpBoard[index_Zero + _k] = 0;
        if (this->_sourceBoard == NULL || tmpBoard != this->_sourceBoard->_board)
        {
            Taquin newState(tmpBoard, mooves, _k, this);
            tmpHerited.push_back(newState);
            this->AddNeighbourg(newState);
        }
    }
    if ((index_Zero - 1 >= 0) && (index_Zero % _k != 0))
    {
        tmpBoard = _board;
        tmpBoard[index_Zero] = tmpBoard[index_Zero - 1];
        tmpBoard[index_Zero - 1] = 0;
        if (this->_sourceBoard == NULL || tmpBoard != this->_sourceBoard->_board)
        {
            Taquin newState(tmpBoard, mooves, _k, this);
            tmpHerited.push_back(newState);
            this->AddNeighbourg(newState);
        }
    }
    if (((index_Zero + 1 < _size) && ((index_Zero + 1) % _k != 0)) || index_Zero == 0)
    {
        tmpBoard = _board;
        tmpBoard[index_Zero] = tmpBoard[index_Zero + 1];
        tmpBoard[index_Zero + 1] = 0;
        if (this->_sourceBoard == NULL || tmpBoard != this->_sourceBoard->_board)
        {
            Taquin newState(tmpBoard, ++_mooves, _k, this);
            tmpHerited.push_back(newState);
            this->AddNeighbourg(newState);
        }
    }

    for (size_t i = 0; i < tmpHerited.size(); i++)
    {
        for (size_t j = 0; j < tmpHerited.size(); j++)
        {
            tmpHerited[i].AddNeighbourg(tmpHerited[j]);
        }
    }

    return tmpHerited;
}

int operator==(Taquin t1, Taquin t2)
{
    for (int i = 0; i < t1.GetSize(); i++)
    {
        if (t1._board[i] != t2._board[i])
        {
            std::cout << "FAUX" << std::endl;
            return false;
        }
    }
    return true;
}
