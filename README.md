# Taquin Game - M1 2IA

> **Author** : Hadrien Belleville *#Vraus*
>
> **Beginning date**: *nov 02, 2023*

## Table of Content

1. [Introduction](#solving-algorithms-project-applied-to-taquin-game-up)

2. [Definitons](#theoritical-approach-of-the-research-algorithms-up)

    1. [Informed Research Algorithms](#informed-research-algorithms)

    2. [Uninformed Research Algorithms](#uninformed-research-algorithms)

3. [How To Use](#how-to-use-up)

    1. [V-0.1.021123](#v-01021123)

4. [Code](#code-up)

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
