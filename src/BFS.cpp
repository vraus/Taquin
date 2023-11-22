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
            std::cout << "Final state ! Found in " << curr.GetMooves() << "mooves.\n";
            return;
        }

        _list.erase(_list.begin());
        _marked.push_back(curr.GetBoard());

        curr.GenerateNextStates();
        for (uint i = 0; i < curr.GetChildStatesSize(); i++)
        {
            if (curr.GetChildStates(i).IsFinalState())
            {
                std::cout << "Final state ! Found in " << curr.GetChildStates(i).GetMooves() << "mooves.\n";
                curr.GetChildStates(i).Print();
                return;
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
        if (state.VecCompare(state.GetBoard(), _marked[i]))
            return true;
    }

    return false;
}
