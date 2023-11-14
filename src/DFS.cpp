#include "DFS.hpp"

bool DFS::IsMarked(Taquin state)
{
    for (size_t i = 0; i < _marked.size(); i++)
    {
        if (state == _marked[i])
            return true;
    }
    return false;
}

int DFS::Solution(Taquin state)
{
    if (state.IsFinalState())
    {
        std::cout << "Solution trouvée: " << std::endl;
        state.Print();
        return 1;
    }
    else
    {
        if (!IsMarked(state))
        {
            std::cout << "Solution ? " << state.IsFinalState() << std::endl;
            std::cout << "Exploration d'un nouvel Etat: " << std::endl;
            state.Print();
            _marked.push_back(state);
            state.GenerateNextStates();
            for (size_t i = 0; i < state.GetNeighbourgsSize(); i++)
            {
                Solution(state.GetNeighbourgs(i));
                break;
            }
        }
    }
    return 0;
}