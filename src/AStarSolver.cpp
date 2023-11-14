#include "AStarSolver.hpp"
#include <bits/stdc++.h>

int AStarSolver::Solution()
{
    time_t start, end;
    std::vector<Taquin> pq;
    pq.push_back(_solution[0]);

    Taquin curr = pq[0];

    time(&start);
    std::ios_base::sync_with_stdio(false);
    time(&end);

    for (auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(curr.GetSize());
         std::chrono::system_clock::now() < runUntil;)
    {
        int minPQ = pq[0].GetMpriority();
        int indexMinPQ = 0;
        // Search for min in the PQ
        for (size_t i = 1; i < pq.size(); i++)
        {
            if (pq[i].GetMpriority() < minPQ)
            {
                minPQ = pq[i].GetMpriority();
                indexMinPQ = i;
            }
        }

        // Delete the minimum we are exploring
        curr = pq[indexMinPQ];
        pq.erase(pq.begin() + indexMinPQ);

        // Creating all possible states
        curr.GenerateNextStates();

        // Add them to the Priority Queue
        for (size_t i = 0; i < curr.GetNeighbourgsSize(); i++)
        {
            // Check if we found a final state
            if (curr.IsFinalState())
            {

                std::cout << "Etat Resolu! " << std::endl;
                break;
            }
            else // The non final state is added and the game continue
                pq.push_back(curr.GetNeighbourgs(i));
        }
        _mooves++;

        std::cout << "mooves: " << _mooves << std::endl;
    }

    std::cout << "End on state:" << std::endl;
    curr.Print();

    std::cout << "Started with: " << std::endl;
    _solution[0].Print();

    return _mooves;
}
