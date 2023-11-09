#include "Taquin.hpp"

// Constructors and Shreders

Taquin::Taquin(int k)
{
    {
        _k = k;
        generateCibleTaquin();
        generateInitialTaquin();
        std::cout << "Etat inital du Taquin: " << std::endl;
        AfficheCurrentState();
    }
}

Taquin::~Taquin() {}

// Private Methods

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

int Taquin::generateNextStates(std::vector<std::vector<int>> _gameState)
{
    // _statesTaquin.push_back(_gameState);

    int newState = 0;

    findZero();

    if (0 <= (_posZero[0] - 1))
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[newState++], _posZero[0], _posZero[1], _posZero[0] - 1, _posZero[1]);
    }

    if ((_posZero[0] + 1) < _k)
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[newState++], _posZero[0], _posZero[1], _posZero[0] + 1, _posZero[1]);
    }

    if (0 <= (_posZero[1] - 1))
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[newState++], _posZero[0], _posZero[1], _posZero[0], _posZero[1] - 1);
    }

    if ((_posZero[1] + 1) < _k)
    {
        _statesTaquin.push_back(_gameState);
        swap(_statesTaquin[newState++], _posZero[0], _posZero[1], _posZero[0], _posZero[1] + 1);
    }

    return newState;
}

bool Taquin::isFinalState(std::vector<std::vector<int>> &_gameState)
{
    int val = 1;
    for (int i = 0; i < _k; i++)
    {
        for (int j = 0; j < _k; j++)
        {
            if (_gameState[i][j] == 0 && i == _k - 1 && j == _k - 1)
                return true;
            else if (_gameState[i][j] == val)
                val++;
            else
                return false;
        }
    }
    return true;
}

// Public Methods

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

    std::vector<std::vector<int>> taquin_src = _taquin;

    int num_states;
    srand((unsigned)time(nullptr));

    while (!isFinalState(_taquin))
    {
        num_states = generateNextStates(_taquin);

        // std::cout << "Etat courant: " << std::endl;
        // AfficheCurrentState();

        int index = rand() % num_states;
        while (taquin_src == _statesTaquin[index])
            index = rand() % num_states;

        for (int i = 0; i < num_states; i++)
        {
            if (isFinalState(_statesTaquin[i]))
            {
                _taquin = _statesTaquin[i];
                std::cout << "Resolved: " << std::endl;
                AfficheCurrentState();
                return isFinalState(_taquin);
            }
        }

        taquin_src = _taquin;

        _taquin = _statesTaquin[index];

        // std::cout << "\t Etat trouvé !" << std::endl;
        // AfficheCurrentState();

        _statesTaquin.clear();
    }

    return true;
}

int operator==(std::vector<std::vector<int>> _taquin1, std::vector<std::vector<int>> _taquin2)
{
    for (size_t i = 0; i < _taquin1.size(); i++)
    {
        for (size_t j = 0; j < _taquin1.size(); j++)
        {
            if (_taquin1[i][j] != _taquin2[i][j])
                return 0;
        }
    }
    return 1;
}
