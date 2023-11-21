#include "BFS.hpp"

void BFS::Solution()
{
    while (!_list.empty())
    {

        Taquin curr = _list[0];
        do
        {
            // std::cout << "\e[1;1H\e[2J";
            curr.Print();
            if (!_list.empty())
                _list.erase(_list.begin());
            _marked.push_back(curr.GetBoard());
            curr.GenerateNextStates();
            std::cout << "GetChildStatesSize: " << curr.GetChildStatesSize() << "\n";
            for (uint i = 0; i < curr.GetChildStatesSize(); i++)
            {
                if (!IsMarked(curr.GetChildStates(i)))
                {
                    _marked.push_back(curr.GetChildStates(i).GetBoard());
                    _list.push_back(curr.GetChildStates(i));
                }
            }
            curr = _list[0];
        } while (!curr.IsFinalState());
        std::cout << "Dragon Ball Z!\n";
    }
    std::cout << "No solution...\n";
}

bool BFS::IsMarked(Taquin state)
{
    for (uint i = 0; i < _marked.size(); i++)
    {
        if (_marked[i] != state.GetBoard())
            return true;
    }

    return false;
}