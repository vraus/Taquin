#include "AStarSolver.hpp"
#include <bits/stdc++.h>

int AStarSolver::Solution()
{
    time_t start, end;
    std::vector<Taquin> pq;
    pq.push_back(_solution[0]);
    _iterations = 0;

    Taquin curr = pq[0];

    time(&start);
    std::ios_base::sync_with_stdio(false);
    time(&end);

    for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(curr.GetSize());
         std::chrono::system_clock::now() < runUntil;)
    {
        std::cout << "\e[1;1H\e[2J";
        int minPQ = pq[0].GetMpriority();
        int indexMinPQ = 0;
        // Search for min in the PQ
        for (size_t i = 0; i < pq.size(); i++)
        {
            if (pq[i].GetMpriority() <= minPQ)
            {
                minPQ = pq[i].GetMpriority();
                indexMinPQ = i;
            }
        }
        curr = pq[indexMinPQ];
        pq.erase(pq.begin() + indexMinPQ);
        _marked.push_back(curr.GetBoard());

        if (curr.IsFinalState())
        {
            curr.Print();
            std::cout << "Etat Resolu en " << curr.GetMooves() << " coups.\n";
            return _iterations;
        }

        curr.Print();

        // Creating all possible states
        curr.GenerateNextStates();

        // Add them to the Priority Queue
        for (size_t i = 0; i < curr.GetChildStatesSize(); i++)
        {
            // Check if we found a final state
            if (curr.GetChildStates(i).IsFinalState())
            {
                curr.GetChildStates(i).Print();
                std::cout << "Etat Resolu en " << curr.GetChildStates(i).GetMooves() << " coups.\n";
                return _iterations;
            }
            else if (!isMarked(curr.GetChildStates(i)))
            {
                _marked.push_back(curr.GetChildStates(i).GetBoard());
                pq.push_back(curr.GetChildStates(i));
            }
        }
        _iterations++;
    }

    return _iterations;
}

bool AStarSolver::isMarked(Taquin state)
{
    for (uint i = 0; i < _marked.size(); i++)
    {
        if (_marked[i] == state.GetBoard())
            return true;
    }

    return false;
}