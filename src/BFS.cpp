#include "BFS.hpp"

void BFS::Solution()
{
    time_t start, end;

    time(&start);
    std::ios_base::sync_with_stdio(false);
    time(&end);

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
            if (!IsMarked(curr.GetChildStates(i)))
            {
                _marked.push_back(curr.GetChildStates(i).GetBoard());
                _list.push_back(curr.GetChildStates(i));
            }
        }
    } while (!curr.IsFinalState() && !_list.empty());
    if (!_list.empty())
        std::cout
            << "Dragon Ball Z!\n";
    else
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