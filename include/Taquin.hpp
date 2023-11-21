#ifndef TAQUIN_HPP
#define TAQUIN_HPP

#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>

class Taquin
{
public:
    /**
     * @brief Constructor called when it's the initial board of the game.
     * @param k The size of a k * k board
     */
    Taquin(int k);

    /**
     * @brief Constructor called when creating another state of the game, during resolution
     * @param board The vector containing the new state
     * @param mooves The number of mooves to reach this new state ( = 1 + mooves of the source state)
     * @param k The size of a k * k board
     */
    Taquin(std::vector<int> board, int mooves, int k, Taquin *source);

    ~Taquin() {} // Default Shreder

    /**
     * @brief This function calculate the Hamming Distance between this state and the goal board.
     * The Hamming Distance is the number of tiles in the wrong position.
     * @returns The Hamming distance
     */
    int Hamming();

    /**
     * @brief This function calculate the Manhattan Distance between this state and the goal board
     * The Manhattan Distance is
     * @returns The Manhattan distance
     */
    int Manhattan();

    void Print();

    void GenerateNextStates();

    int GetHpriority() { return _Hpriority; }

    /** @returns the Manhattan priority of this state */
    int GetMpriority() { return _Mpriority; }

    int GetK() { return _k; }

    /** @returns The size of the board (_k * _k) */
    int GetSize() { return _size; }

    size_t GetChildStatesSize() { return _childStates.size(); }

    std::vector<int> GetBoard() { return _board; }

    Taquin GetChildStates(int index) { return _childStates[index]; }

    void AddChildStates(Taquin child) { _childStates.push_back(child); }

    friend int operator==(Taquin t1, Taquin t2);

    friend int operator==(std::vector<int> t1, std::vector<int> t2);

    /** @returns A pointer to the source of the current state. */
    Taquin GetSource()
    {
        return *_sourceBoard;
    }

    /** @returns True if the current state is the source state. */
    bool IsSource() { return _sourceBoard == nullptr; }

    int GetMooves() { return _mooves; }

    /** @returns True if the current state is the final board */
    bool IsFinalState()
    {
        for (uint i = 0; i < _board.size() - 1; i++)
        {
            if (_board[i] != (int)i + 1)
                return false;
        }
        return _board.back() == 0;
    }

private:
    int _k;                           // Size of the board is k²
    int _size;                        // Size of the board; thus avoiding to calculate it in methods
    std::vector<int> _board;          // Values of the Taquin
    std::vector<int> _finalState;     // Final ordered state of a Taquin game :> useless
    int _mooves;                      // Number of mooves for this state
    int _hamming;                     // Hamming distance of this state
    int _manhattan;                   // Manhattan distance of this state
    int _Hpriority;                   // Hpriority = _mooves + _hamming;
    int _Mpriority;                   // Mpriority = _mooves + _manhattan;
    std::vector<Taquin> _childStates; // All neighbourgs states of this state
    Taquin *_sourceBoard;             // Source board of this state
};

#endif