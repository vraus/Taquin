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

    game.ResolutionHasard();

    return 0;
}