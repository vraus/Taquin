#include "BFS.hpp"

void BFS::Solution()
{
    Taquin curr = _list[0];
    do
    {
        std::cout << "\e[1;1H\e[2J";
        curr = _list[0];
        curr.Print();

        if (curr.IsFinalState())
        {
            std::cout << "Final state found!\n";
            return;
        }

        _list.erase(_list.begin());
        _marked.push_back(curr.GetBoard());

        curr.GenerateNextStates();
        for (uint i = 0; i < curr.GetChildStatesSize(); i++)
        {
            Taquin child = curr.GetChildStates(i);
            if (child.IsFinalState())
            {
                std::cout << "Final state !\n";
                child.Print();
                return;
            }

            if (!IsMarked(child))
            {
                _list.push_back(child);
            }
        }
    } while (!_list.empty());

    if (_list.empty())
        std::cout << "No solution...\n";
}

bool BFS::IsMarked(Taquin state)
{
    for (uint i = 0; i < _marked.size(); i++)
    {
        if (_marked[i] == state.GetBoard())
            return true;
    }

    return false;
}
