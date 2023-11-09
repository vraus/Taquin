#include "Taquin.hpp"

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

    Taquin game(k);

    int choice = 1;

    do
    {
        std::cout << "Choose you resolution method: " << std::endl;
        std::cout << " * (1) : Random Resolve." << std::endl;
        std::cout << " * (0) : Exit." << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (game.ResolutionHasard())
                std::cout << "Taquin résolu!! " << std::endl;
            break;
        case 0:
            break;
        default:
            std::cout << "Not a correct val." << std::endl;
            break;
        }
    } while (choice > 0);

    return 0;
}