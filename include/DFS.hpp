#ifndef DFS_HPP
#define DFS_HPP

#include "Taquin.hpp"

class DFS
{
public:
    DFS() {}

    ~DFS() {}

    int Solution(Taquin state);

    int Explore(Taquin state);

    bool IsMarked(Taquin state);

private:
    std::vector<Taquin> _marked; // Every visited states
};

#endif