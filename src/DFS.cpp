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

int DFS::Explore(Taquin state)
{
    _marked.push_back(state);
    state.Print();
    for (size_t i = 0; i < state.GetChildStatesSize(); i++)
    {
        if (!IsMarked(state.GetChildStates(i)))
        {
            Explore(state.GetChildStates(i));
            state.GenerateNextStates();
        }
    }

    return state.IsFinalState();
}

// BUG: On this Version, DFS doesn't work.
//  To generate Next States I have to store them !!!
int DFS::Solution(Taquin state)
{
    _marked.push_back(state);
    state.GenerateNextStates();
    for (size_t i = 0; i < state.GetChildStatesSize(); i++)
    {
        if (!IsMarked(state.GetChildStates(i)))
            return Explore(state.GetChildStates(i));
    }

    return 0;
}