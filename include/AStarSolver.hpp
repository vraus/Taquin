#ifndef ASTARSOLVER_HPP
#define ASTARSOLVER_HPP

#include "Taquin.hpp"

class AStarSolver
{
public:
    AStarSolver() {}

    void SettingSolver(Taquin zeroBoard)
    {
        _solution.push_back(zeroBoard);
        _iterations = 0;

        _solution[0].Print();

        Solution();
    }

    ~AStarSolver() {}

    bool isMarked(Taquin state);

    int Solution();

private:
    int _iterations;
    std::vector<Taquin> _solution;
    std::vector<std::vector<int>> _marked; // List of visited states
};

#endif