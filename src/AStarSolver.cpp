#include "AStarSolver.hpp"
#include <bits/stdc++.h>

int AStarSolver::Solution()
{
    time_t start, end;
    std::vector<Taquin> pq;
    pq.push_back(_solution[0]);

    Taquin curr = pq[0];

    int resolved = 0;

    time(&start);
    std::ios_base::sync_with_stdio(false);
    time(&end);

    while (resolved == 0)
    {
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

        pq.erase(pq.begin() + indexMinPQ);
        curr.Print();
        if (curr.GetNeighbourgsSize())
        {
            for (size_t i = 0; i < curr.GetNeighbourgsSize(); i++)
            {
                Taquin neigCurr = curr.GetNeighbourgs(i);
                std::vector<Taquin> newStates = neigCurr.GenerateNextStates();
                for (size_t i = 0; i < newStates.size(); i++)
                    pq.push_back(newStates[i]);
            }
        }
        else
        {
            curr.GenerateNextStates();
            std::cout << "Now neighbourgs nb: " << curr.GetNeighbourgsSize() << std::endl;
        }

        _mooves++;
        resolved++;
    }

    /*std::cout << "End on state:" << std::endl;
    curr.Print();

    std::cout << "Started with: " << std::endl;
    _solution[0].Print();*/

    return _mooves;
}
