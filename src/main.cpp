#include "AStarSolver.hpp"
#include "DFS.hpp"

#define handle_error(msg, status) \
    do                            \
    {                             \
        perror(msg);              \
        exit status;              \
    } while (0)

// TODO: Refactor Taquin::_board usage (std::vector<int> change to a char[].)
// TODO: Add a closed list to the A* solver (hashmap)
// FIXME: The creation of new state in a Taquin is bugged
int main()
{
    int k = 0;

    std::cout << "Donnez la taille du tableau (k): " << std::endl;
    std::cin >> k;

    while (k == 0)
        std::cin >> k;

    Taquin *game = new Taquin(k);

    AStarSolver aStarSolver;
    DFS dfsSolver;

    int choice = 0;

    do
    {
        std::cout << "Choose you resolution method: " << std::endl;
        std::cout << " * (1) : A* Resolution." << std::endl;
        std::cout << " * (2) : DFS Resolution." << std::endl;
        std::cout << " * (0) : Exit." << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            aStarSolver.SettingSolver(*game);
            break;
        case 2:
            dfsSolver.Solution(*game);
            break;
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