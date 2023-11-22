# Taquin Game - M1 2IA

> **Author** : Hadrien Belleville *#Vraus*
>
> **Beginning date**: *nov 02, 2023*

## Table of Content

1. [Introduction](#solving-algorithms-project-applied-to-taquin-game-up)

1. [Definitons](#theoritical-approach-of-the-research-algorithms-up)
  
   1. [Informed Research Algorithms](#informed-research-algorithms)
  
   1. [Uninformed Research Algorithms](#uninformed-research-algorithms)

1. [How To Use](#how-to-use-up)

   1. [V-0.1.021123](#v-01021123)

1. [Code](#code-up)

   1. [main.cpp](#maincpp)

   1. [Taquin.cpp](#taquincpp)

   1. [AStarSolver.cpp](#astarsolvercpp)

   1. [BFS.cpp](#bfscpp)

   1. [DFS.cpp](#dfscpp)

## Solving Algorithms Project applied to Taquin Game ***([up](#taquin-game---m1-2ia))***

According to Wikipedia, the taquin is a solitaire game in the form of a checkerboard, created around 1870 in the United States. Its mathematical theory was published by the American Journal of Mathematics Pure and Applied in 1879. In 1891, its invention was claimed by Sam Loyd, at a time when the game was experiencing considerable popularity in both the United States and Europe. The taquin is composed of 15 numbered small squares that slide in a frame designed for 16. The objective is to rearrange the 15 squares from any initial configuration into the correct order.

The principle has been extended to various other games. Most of them use rectangular blocks instead of squares, but the goal is always to arrange the blocks in a specific way with the fewest possible moves. The Rubik's Cube is now considered one of the "descendants" of the taquin.

## Theoritical Approach of the research Algorithms ***([up](#taquin-game---m1-2ia))***

> To solve this problem, I will be implementing several research strategies, both informed and uninformed, to further explore the taquin game and its variations.

### Informed Research Algorithms

***Definition*:**

Informed research algorithms are search algorithms that utilize additional information or knowledge about the problem domain to guide the search process.

These algorithms make use of heuristics or domain-specific knowledge to make informed decisions about which paths to explore.

***Examples*:**

+ **A\* algorithm:** A popular informed search algorithm that uses a heuristic function to estimate the cost of reaching the goal from a particular state.

+ **Best-First Search:** This algorithm selects the most promising path based on a heuristic evaluation function.

+ **Greedy Search:** A search algorithm that always chooses the path that appears to be the best at the current moment, based on a heuristic evaluation.

### Uninformed Research Algorithms

***Definition*:**

Uninformed research algorithms, also known as blind search algorithms, are search algorithms that do not utilize any additional information or knowledge about the problem domain. These algorithms explore the search space systematically without any specific guidance.

***Examples*:**

+ **Breadth-First Search:** This algorithm explores all the neighboring nodes of the current node before moving to the next level of nodes.

+ **Depth-First Search:** This algorithm explores as far as possible along each branch before backtracking.

+ **Uniform Cost Search:** A search algorithm that explores the path with the lowest cumulative cost.

## How To Use ***([up](#taquin-game---m1-2ia))***

> How to read the versions name: `V-X.Y.Z`
>
> + `X`: This indicates the major version. It is incremented for significant changes that may introduce backward-incompatible features.
> + `Y`: This is the minor version. It is typically incremented for smaller, backward-compatible changes or feature additions.
> + `Z`: This represents the patch version. It is used for bug fixes or small improvements that are backward-compatible. In our case this will always be the date of the first commit of the patch version.

### V-0.1.021123

To run and test the code at this actual state, you just have to run the following command in a terminal while in the project working directory:

```bash
make && ./main
```

and then follow the instructions in the terminal.

## Code ***([up](#taquin-game---m1-2ia))***

### main.cpp

The main loop of the program. When running `make && ./main` in the terminal, the program will ask you to chose the size of the [Taquin](#taquincpp) game and then wait for you to choose a resolution method among [A*](#astarsolvercpp), [BFS](#bfscpp) and [DFS](#dfscpp) search algorithms.

### Taquin.cpp

```cpp
#include "Taquin.hpp"
class Taquin;
```

The Taquin class manages everything related to the resolution of a Taquin game. This class contains the board states, all associated child states (once generated).

Also includes values for an Informed Resolution such as Hamming and Manhattan distances, priority for the [A* Resolution](#astarsolvercpp) ans mooves to get to this state from the first one.

#### Improving Taquin

In this version, I use `std::vector<int>` to store board states. Doing this is heavy and slows the program when I need to use, compare and navigate through those vectors.

I'd like to improve this part by using `long long int` to store a board of taquin, and manipulate bits in this `long long int` to initialise the board, compare it and change the states.

A `n²-size` Taquin has `n` rows and columns of values from `0` to `n²-1`. Each values can be represented in `n bits`. Knowing this, I would manipulate `n-by-n bits` to store a `n²-size game`.

Doing this would also ease the process of comparing boards and marking them, I would only need to compare the `long long int` values and not iterate through a `std::vector<int>` nor in an array of int, etc...

### AStarSolver.cpp

```cpp
#include "AStarSolver.hpp"
class AStarSolver;
```

The `AStarSolver.cpp` file contains the implementation of the A* algorithm for solving the Taquin puzzle. The algorithm uses a Priority Queue (PQ) to explore states with lower heuristic values first, aiming to find the optimal solution.

The Solution function runs the A* algorithm until a time limit, printing the current state of the puzzle at each iteration. The program stops when it finds a solution or reaches the time limit.

The `isMarked` function checks whether a given state is marked (visited) to avoid revisiting the same state during the search.

#### Improving the A* solver

> The following are some ideas to improve this solving method. Making it simpler, lighter (faster) and easier to work with.

1. **Magic Numbers:** Replacing any magic numbers in the code with named constants to improve code readability and maintainability.

1. **Code Modularization:** Breaking down the `Solution` function into smaller, more modular functions to improve code organization and readability.

1. **Use of Global Variables:** Minimizing the use of global variables, if possible, and considering passing necessary variables as function parameters.

1. **Error Handling:** Implementing error handling to handle unexpected situations gracefully.

1. **Unit Testing:** Implementing unit tests to ensure the correctness of the A* algorithm and its components.

1. **Usage of hash:** Implementing hash to store marked state to lighten the comparison process.

### BFS.cpp

```cpp
#include "BFS.hpp"
class BFS;
```

The `BFS.cpp` is an implementation of the Breadth-First Search (BFS) algorithm for solving the Taquin puzzle. BFS explores the puzzle states level by level, starting from the initial state, until it finds the goal state. The code maintains a queue of states to be explored and marks visited states to avoid revisiting them.

The `Solution` function runs the BFS algorithm, printing the current state of the puzzle at each iteration. The algorithm stops when it finds a solution, reaches the goal state, or exhausts all possible states.

The `IsMarked` function checks whether a given state is marked (visited) to prevent revisiting the same state during the search.

#### Improving the BFS solver

> The following are some ideas to improve this solving method. Making it simpler, lighter (faster) and easier to work with.

1. **Efficient State Comparison:** Instead of using a loop for state comparison in `IsMarked`, using a more efficient data structure or algorithm for checking state membership such as hash set.

1. **Memory Optimization:** Optimization of the memory usage for the `_list` and `_marked` data structures.

1. **Algorithmic Efficiency:** Refining the BFS algorithm for more efficiency. Small tweaks to the algorithm itself, such as pruning unnecessary branches or optimizing the state generation process, thus leading to performance improvements.

### DFS.cpp

```cpp
#include "DFS.hpp"
class DFS;
```

The `DFS.cpp` is an implementation of the Depth-First Search (DFS) algorithm for solving the Taquin puzzle. The Taquin puzzle involves rearranging a set of numbered tiles into a specific order. The DFS algorithm explores the search space in a depthward motion, traversing as far as possible along one branch before backtracking.

#### Improving the DFS solver

> The DFS solver is BFS-based, making the optimisations for this solutions same as the BFS solution.
