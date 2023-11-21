#include "BFS.hpp"

void BFS::Solution()
{
    Taquin curr = _list[0];
    do
    {
        std::cout << "\e[1;1H\e[2J";
        curr = _list[0];

        if (curr.IsFinalState())
        {
            std::cout << "Final state !\n";
            curr.Print();
            break;
        }

        _list.erase(_list.begin());
        curr.Print();
        _marked.push_back(curr.GetBoard());
        curr.GenerateNextStates();
        for (uint i = 0; i < curr.GetChildStatesSize(); i++)
        {
            if (curr.GetChildStates(i).IsFinalState())
            {
                std::cout << "Final state !\n";
                curr.GetChildStates(i).Print();
                break;
            }
            if (!IsMarked(curr.GetChildStates(i)))
            {
                _list.push_back(curr.GetChildStates(i));
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