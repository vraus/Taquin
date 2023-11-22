#include "DFS.hpp"

void DFS::Solution()
{
    int step = 0;
    Taquin curr = _list[0];
    do
    {
        std::cout << "\e[1;1H\e[2J";
        int size = _list.size();
        curr = _list[size - 1];

        if (curr.IsFinalState())
        {
            std::cout << "Final state ! Found in " << curr.GetMooves() << "mooves.\n";
            curr.Print();
            return;
        }

        _list.pop_back();
        curr.Print();
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
        std::cout << ++step;
    } while (!_list.empty());

    std::cout << "No solution...\n";
}

bool DFS::IsMarked(Taquin state)
{
    for (uint i = 0; i < _marked.size(); i++)
    {
        if (_marked[i] == state.GetBoard())
            return true;
    }

    return false;
}