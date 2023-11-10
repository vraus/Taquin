#ifndef TAQUIN_HPP
#define TAQUIN_HPP

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

class Taquin
{
public:
    /**
     * @brief Constructor called when it's the initial board of the game.
     * @param k The size of a k * k board
     */
    Taquin(int k); // TODO: modify shuffle

    /**
     * @brief Constructor called when creating another state of the game, during resolution
     * @param board The vector containing the new state
     * @param mooves The number of mooves to reach this new state ( = 1 + mooves of the source state)
     * @param k The size of a k * k board
     */
    Taquin(std::vector<int> board, int mooves, int k);

    ~Taquin() {} // Default Shreder

    /**
     * @brief This function calculate the Hamming Distance between this state and the goal board.
     * The Hamming Distance is the number of tiles in the wrong position.
     * @returns The Hamming distance
     */
    int Hamming(); // TODO: Hamming

    /**
     * @brief This function calculate the Manhattan Distance between this state and the goal board
     * The Manhattan Distance is
     * @returns The Manhattan distance
     */
    int Manhattan();

    void print();

private:
    int _k;                  // Size of the board is k²
    std::vector<int> _board; // Values of the Taquin
    int _mooves;             // Number of mooves for this state
    int _hamming;            // Hamming distance of this state
    int _manhattan;          // Manhattan distance of this state
    int _Hpriority;          // Hpriority = _mooves + _hamming;
    int _Mpriority;          // Mpriority = _mooves + _manhattan;
    Taquin **_neighbourgs;   // All neighbourgs states of this state
};

#endif