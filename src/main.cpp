#include "AStarSolver.hpp"
#include "BFS.hpp"
#include "DFS.hpp"

#define handle_error(msg, status) \
    do                            \
    {                             \
        perror(msg);              \
        exit status;              \
    } while (0)

int main()
{
    int k = 0;

    std::cout << "Donnez la taille du tableau (k): " << std::endl;
    std::cin >> k;

    while (k == 0)
        std::cin >> k;

    Taquin *game = new Taquin(k);

    if (!game->IsSolvable())
    {
        std::cout << "15 puzzle not solvable.\n";
        return 0;
    }

    AStarSolver aStarSolver;
    BFS bfsSolver;
    DFS dfsSolver;

    int choice = 0;

    do
    {
        std::cout << "Choose you resolution method: " << std::endl;
        std::cout << " * (1) : A* Resolution." << std::endl;
        std::cout << " * (2) : BFS Resolution." << std::endl;
        std::cout << " * (3) : DFS Resolution." << std::endl;
        std::cout << " * (0) : Exit." << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            aStarSolver.SettingSolver(*game);
            break;
        case 2:
            bfsSolver.SettingSolver(*game);
            break;
        case 3:
            dfsSolver.SettingSolver(*game);
        case 0:
            break;
        default:
            std::cout << "Not a correct val." << std::endl;
            break;
        }
        break;
    } while (choice > 0);

    return 0;
}