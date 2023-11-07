#include "Taquin.hpp"

Taquin::~Taquin() {}

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

    find_zero();
}

void Taquin::swap(std::vector<std::vector<int>> &_gameState, int i_dex, int j_dex, int i_dex_sd, int j_dex_sd)
{
    int tmp = _gameState[i_dex][j_dex];
    _gameState[i_dex][j_dex] = _gameState[i_dex_sd][j_dex_sd];
    _gameState[i_dex_sd][j_dex_sd] = tmp;
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

void Taquin::generateNextStates()
{
    _statesTaquin.push_back(_taquin);

    _statesTaquin.push_back(_taquin);
    swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0] % _k, _posZero[1] % _k, (_posZero[0] + 1) % _k, _posZero[0] % _k);
    _statesTaquin.push_back(_taquin);
    swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0] % _k, _posZero[1] % _k, (_posZero[0] - 1) % _k, _posZero[0] % _k);
    _statesTaquin.push_back(_taquin);
    swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0] % _k, _posZero[1] % _k, _posZero[0] % _k, (_posZero[0] + 1) % _k);
    _statesTaquin.push_back(_taquin);
    swap(_statesTaquin[_statesTaquin.size() - 1], _posZero[0] % _k, _posZero[1] % _k, _posZero[0] % _k, (_posZero[0] - 1) % _k);

    for (int i = 0; i < 4; i++)
    {
        _taquin = _statesTaquin[i];
        std::cout << "Verification de tous les états: " << std::endl;
        AfficheCurrentState();
    }
}

void Taquin::find_zero()
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

void Taquin::AfficheCurrentState()
{
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
        {
            std::cout << _taquin[i][j] << " | ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
