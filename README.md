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
   git clone https://github.com/your-username/kakuro-solver.git
   ```

2. Navigate to the project directory:

   ```bash
   cd kakuro-solver
   ```

3. Build the project using CMake:

    ```bash
    ./cmake-build-debug --target kakuro -j 10
    clear
    ./cmake-build-debug/kakuro
    echo "\n"
    ```

### Usage

1. Run the executable:

   ```bash
   ./kakuro_solver
   ```

2. Enter the Kakuro puzzle using the provided interface.

3. The solver will output the solution or inform if no solution is found.

### Example

```cpp
// Sample code or command for running the solver
./kakuro_solver < sample_puzzle.txt
```

## Documentation

- Detailed documentation on the implementation, algorithms, and classes can be found in the [docs](./docs) directory.

## Contributing

Contributions are welcome! Please follow the [contribution guidelines](CONTRIBUTING.md) for details on how to contribute to this project.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Mention any libraries, tutorials, or resources you used or were inspired by during development.

## Contact

For any questions or concerns, please contact [Your Name](mailto:your.email@example.com).

