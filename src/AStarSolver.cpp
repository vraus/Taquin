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

    // for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(curr.GetSize());
    //      std::chrono::system_clock::now() < runUntil;)
    for (;;)
    {
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

            std::cout << "Etat Resolu! " << std::endl;
            break;
        }

        curr.Print();

        // Creating all possible states
        curr.GenerateNextStates();

        // Add them to the Priority Queue
        for (size_t i = 0; i < curr.GetChildStatesSize(); i++)
        {
            // Check if we found a final state
            if (curr.IsFinalState())
            {

                std::cout << "Etat Resolu! " << std::endl;
                break;
            }
            else if (!isMarked(curr.GetChildStates(i)))
            {
                _marked.push_back(curr.GetChildStates(i).GetBoard());
                pq.push_back(curr.GetChildStates(i));
            }
        }
        _iterations++;
    }

    std::cout << "End on state:" << std::endl;
    curr.Print();

    std::cout
        << "Started with: " << std::endl;
    _solution[0].Print();

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