#include "Taquin.hpp"

Taquin::~Taquin() {}

Taquin::Taquin(int k)
{
    {
        _k = k;
        generateCibleTaquin();
        std::cout << "Etat initial du Taquin: " << std::endl;
        AfficheCurrentState();

        generateInitialTaquin();
        std::cout << "Etat mélangé du Taquin: " << std::endl;
        AfficheCurrentState();
    }
}

void Taquin::swap(std::vector<std::vector<int>> &_gameState, int i_dex, int j_dex, int i_dex_sd, int j_dex_sd)
{
    int tmp = _gameState[i_dex][j_dex];
    _gameState[i_dex][j_dex] = _gameState[i_dex_sd][j_dex_sd];
    _gameState[i_dex_sd][j_dex_sd] = tmp;
}

void Taquin::generateInitialTaquin()
{
    srand((unsigned)time(nullptr));

    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
        {
            int i_dex_sd = i + rand() % (_k - i);
            int j_dex_sd = j + rand() % (_k - j);
            swap(_taquin, i, j, i_dex_sd, j_dex_sd);
        }
    }

    findZero();
}

void Taquin::generateCibleTaquin()
{
    int val = 1;
    for (int i = 0; i < _k; i++)
    {
        std::vector<int> tmp;
        for (int j = 0; j < _k; j++)
            tmp.push_back(val++);
        _taquin.push_back(tmp);
    }
    _taquin[_k - 1].pop_back();
    _taquin[_k - 1].push_back(0);
}

int Taquin::generateNextStates(std::vector<std::vector<int>> _gameState)
{
    // _statesTaquin.push_back(_gameState);

    int newState = 0;

    if (0 <= (_posZero[0] - 1))
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0], _posZero[1], _posZero[0] - 1, _posZero[1]);
        newState++;
    }

    if ((_posZero[0] + 1) < _k)
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0], _posZero[1], _posZero[0] + 1, _posZero[1]);
        newState++;
    }

    if (0 <= (_posZero[1] - 1))
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0], _posZero[1], _posZero[0], _posZero[1] - 1);
        newState++;
    }

    if ((_posZero[1] + 1) < _k)
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0], _posZero[1], _posZero[0], _posZero[1] + 1);
        newState++;
    }

    return newState;
}

void Taquin::findZero()
{
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
        {
            if (_taquin[i][j] == 0)
            {
                _posZero[0] = i;
                _posZero[1] = j;
                break;
            }
        }
    }
}

bool Taquin::isFinalState()
{
    int val = 1;
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
        {
            if (_taquin[i][j] == 0 && i == _k - 1 && j == _k - 1)
                return true;
            else if (_taquin[i][j] == val)
                val++;
            else
                return false;
        }
    }
    return true;
}

void Taquin::AfficheCurrentState()
{
    for (int i = 0; i < _k; i++)
    {
        std::cout << "\t";
        for (int j = 0; j < _k; j++)
        {
            std::cout << _taquin[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

bool Taquin::ResolutionHasard()
{
    std::cout << "************************" << std::endl;
    std::cout << "**Resolution au Hasard**" << std::endl;
    std::cout << "************************" << std::endl;
    std::cout << std::endl;

    int num_states = generateNextStates(_taquin);
    srand((unsigned)time(nullptr));

    while (!isFinalState())
    {
        _taquin = _statesTaquin[rand() % num_states - 1];
        _statesTaquin.clear();
        std::cout << "Etat courant en cours de résolution : " << std::endl;
        AfficheCurrentState();
        num_states = generateNextStates(_taquin);
    }

    return isFinalState();
}