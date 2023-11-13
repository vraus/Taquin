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

    while (double(end - start) <= (curr.GetSize()))
    {

        time(&end);
        int minPQ = pq[0].GetMpriority();
        int indexMinPQ = 0;
        // Recherche du min prio dans la PQ
        for (size_t i = 1; i < pq.size(); i++)
        {
            if (pq[i].GetMpriority() < minPQ)
            {
                minPQ = pq[i].GetMpriority();
                indexMinPQ = i;
            }
        }

        // Supprime de la PQ le board qu'on va explorer
        curr = pq[indexMinPQ];
        std::cout << "Etape " << _mooves << std::endl;

        pq.erase(pq.begin() + indexMinPQ);
        for (size_t i = 0; i < curr.GetNeighbourgsSize(); i++)
        {
            Taquin neigCurr = curr.GetNeighbourgs(i);
            std::cout << "here! " << start << " " << end << std::endl;
            std::vector<Taquin> newStates = neigCurr.GenerateNextStates();
            for (size_t i = 0; i < newStates.size(); i++)
                pq.push_back(newStates[i]);
        }

        _mooves++;
    }

    std::cout << "End on state:" << std::endl;
    curr.Print();

    std::cout << "Started with: " << std::endl;
    _solution[0].Print();

    return _mooves;
}
