#ifndef BFS_HPP
#define BFS_HPP

#include "Taquin.hpp"

class BFS
{
public:
    BFS() {}

    ~BFS() {}

    void SettingSolver(Taquin zeroBoard)
    {
        _solution.push_back(zeroBoard);
        _iterations = 0;

        _solution[0].Print();

        Solution();
    }

    void Solution() {}

private:
    std::vector<Taquin> _solution;
    int _iterations;
    std::vector<std::vector<int>> _marked;
};

#endif