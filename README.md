# Table of Contents
- [Table of Contents](#table-of-contents)
  - [Run Project](#run-project)
- [Kakuro Game Solver](#kakuro-game-solver)
  - [Overview](#overview)
  - [Features](#features)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building](#building)
    - [Usage](#usage)
  - [Table Example](#table-example)
  - [Documentation](#documentation)
  - [Contact](#contact)

## Run Project
```bash
./cmake-build-debug --target kakuro -j 10
clear
./cmake-build-debug/kakuro
echo "\n"
```

# Kakuro Game Solver

## Overview

This C++ project is a Kakuro game solver that utilizes Artificial Intelligence (AI) techniques, specifically Constraint Satisfaction Problems (CSP) and Backtracking, to efficiently solve Kakuro puzzles.

## Features

- AI-based Kakuro solver using CSP and Backtracking.
- User-friendly interface for entering Kakuro puzzles.
- Detailed logging of solving steps and backtracking decisions.
- Flexible design for easy integration into other projects.

## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)
- CMake (for building the project)

### Building

1. Clone the repository:

   ```bash
   git clone https://github.com/SyHoMadara/kakuro
   ```

2. Navigate to the project directory:

   ```bash
   cd kakuro
   ```

3. Build the project using CMake:

    ```bash
    ./cmake-build-debug --target kakuro -j 10
    ```

### Usage

1. Run the executable:

   ```bash
   ./cmake-build-debug/kakuro
   ```

2. Enter the Kakuro puzzle using the provided interface.

3. The solver will output the solution or inform if no solution is found.

## Table Example
<p align="center"> <img src="https://sudoku-puzzles.net/wp-content/puzzles/kakuro-5x5/easy/1.png" width=360><figcaption>kakuro example</figcaption> </p>

If you want to input a table, use the following rules:

  * Walls -> "$x$/$y$" where $x$ and $y$ represent column sum and row sum respectively (If not exist, must be zero).
  * For empty cells, use "0".

For the above example:

```cpp
std::string s = "0/0 11/0 16/0 17/0 0/0\n"
                "0/15 0 0 3 0/0\n"
                "0/8 0 1 0 13/0\n"
                "0/0 0/15 0 2 0\n"
                "0/0 0/19 2 0 0";
```

## Documentation

- Detailed documentation on the implementation, algorithms, and classes can be found in the [docs](./docs) directory.

## Contact

For any questions or concerns, please contact [S.Hosein Sarafrazi](mailto:sh.sarafrazi80@gmail.com).
