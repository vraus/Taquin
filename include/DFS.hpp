#ifndef DFS_HPP
#define DFS_HPP

#include "Taquin.hpp"

class DFS
{
public:
    DFS() {}

    ~DFS() {}

    void SettingSolver(Taquin zeroBoard)
    {
        _list.push_back(zeroBoard);
        _list[0].Print();
        Solution();
    }

    bool IsMarked(Taquin state);

    void Solution();

private:
    std::vector<Taquin> _list;
    int _iterations;
    std::vector<std::vector<int>> _marked;
};

#endif