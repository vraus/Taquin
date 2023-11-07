#ifndef TAQUIN_HPP
#define TAQUIN_HPP

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

class Taquin
{
public:
    /** @brief `constructor` No default constructor, construct the Taquin when you know its size.
     * @param k `int` The size of an k*k Taquin.
     */
    Taquin(int k)
    {
        _k = k;
        generateCibleTaquin();
        std::cout << "Etat initial du Taquin: " << std::endl;
        AfficheCurrentState();

        generateInitialTaquin();
        std::cout << "Etat mélangé du Taquin: " << std::endl;
        AfficheCurrentState();

        std::cout << "Generation des etats suivants." << std::endl;
        generateNextStates();
    }

    ~Taquin();

    /** @brief `void` Displays the current game state. */
    void AfficheCurrentState();

private:
    int _k;
    int _posZero[2];
    std::vector<std::vector<int>> _taquin;
    std::vector<std::vector<std::vector<int>>> _statesTaquin;

    /** @brief `void` Generates the shuffled Taquin game. State 1 of the game.*/
    void generateInitialTaquin();

    /** @brief `void` Swaps two values in the vector _taquin.
     * @param _gameState current game state
     * @param i_dex Index i of the first value
     * @param j_dex Index j of the first value
     * @param i_dex_sd Index i of the second value
     * @param j_dex_sd Index j of the seconde value
     */
    void swap(std::vector<std::vector<int>> &_gameState, int i_dex, int j_dex, int i_dex_sd, int j_dex_sd);

    /** @brief `void` Generates the ordered Taquin */
    void generateCibleTaquin();

    /** @brief `void` Function to generates all next states to a current given state */
    void generateNextStates();

    void find_zero();
};

#endif