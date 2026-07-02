# Hardware-Software Co-Design of an Evolutionary Strategy Solver

This project implements a simple hardware-software co-design model for solving a knapsack-style optimization problem using an Evolutionary Strategy algorithm. The main implementation is written in C++ with SystemC, and a small Python version is also included as a reference implementation of the same optimization idea.

The project was developed for a hardware-software co-design course and demonstrates how an optimization algorithm can be modeled at the system level using modular SystemC components.

## Project Overview

Evolutionary Strategy is a population-based metaheuristic optimization algorithm inspired by natural selection. In this project, the algorithm is applied to a constrained knapsack problem, where each item has a value and a weight, and the goal is to find a chromosome that maximizes total value while keeping the total weight below a defined limit.

The SystemC implementation models the system using separate modules for input generation, evolutionary optimization, and result monitoring.

## Main Features

- SystemC-based hardware-software co-design structure
- Evolutionary Strategy implementation for a knapsack optimization problem
- Population initialization, fitness evaluation, crossover, mutation, and selection
- Gaussian mutation with adaptive sigma values
- Modular SystemC design using driver, solver, and monitor components
- Python reference implementation for comparison and easier understanding
- Example fixed item values and weights for testing

## Repository Structure

```text
Hardware-Software-Co-Design-of-an-Evolutionary-Strategy-Solver/
├── src/
│   ├── Main.cpp
│   ├── Evolutionary_algorithm.cpp
│   ├── Evolutionary_Solve.h
│   ├── driver.h
│   └── monitor.h
├── python/
│   └── ES.py
├── TestSystemC.sln
├── README.md
└── پروژه درس هم طراحی سخت افزار و نرم افزار.pdf
└── پروژه درس هم طراحی سخت افزار و نرم افزار.pdf
```

## SystemC Implementation

The main implementation is located in the `src/` directory.

### Main Modules

| File | Description |
|---|---|
| `Main.cpp` | Creates SystemC signals, connects modules, and starts the simulation. |
| `driver.h` | Provides the item values and weights as input signals. |
| `Evolutionary_Solve.h` | Defines the SystemC solver module and output ports. |
| `Evolutionary_algorithm.cpp` | Implements the Evolutionary Strategy operations and knapsack fitness function. |
| `monitor.h` | Prints the best chromosome and its fitness value during simulation. |

## Optimization Problem

The implemented example uses 9 items. Each item has a weight and a value.

```cpp
Value  = {6, 5, 8, 9, 6, 7, 3, 6, 8}
Weight = {2, 3, 6, 7, 5, 9, 3, 4, 5}
```

The maximum allowed knapsack weight is:

```cpp
MAX_KNAPSACK_WEIGHT = 10
```

The goal is to maximize the total selected value while satisfying the weight constraint.

## Evolutionary Strategy Parameters

The main constants are defined in `Evolutionary_Solve.h`.

```cpp
#define POPULATION_SIZE 10
#define MUTATION_RATE 0.8
#define CROSSOVER_RATE 0.8
#define CHROMOSOME_LENGTH 9
#define ITERATION_COUNT 50
#define MAX_KNAPSACK_WEIGHT 10
#define ITEM_NOM 9
```

## Algorithm Steps

The solver follows these main steps:

1. Generate an initial random population.
2. Evaluate each chromosome using the knapsack fitness function.
3. Select parents from the population.
4. Apply crossover to generate new children.
5. Apply mutation using Gaussian noise.
6. Keep gene values within the range `[0, 1]`.
7. Sort the population based on fitness.
8. Output the best chromosome and fitness value.

## Python Reference Implementation

The `python/ES.py` file contains a standalone Python implementation of the Evolutionary Strategy approach. It can be used to understand the algorithm logic without running the SystemC simulation.

To run the Python version:

```bash
cd python
python ES.py
```

The Python script prints the best solution found by the algorithm.

## Requirements

### For the SystemC/C++ Implementation

- C++ compiler
- SystemC library
- Visual Studio or another C++ development environment configured with SystemC

The included `TestSystemC.sln` file is a Visual Studio solution file. Depending on your local setup, you may need to update SystemC include paths and library paths before building.

### For the Python Implementation

- Python 3
- NumPy

Install NumPy if needed:

```bash
pip install numpy
```

## How to Run

### Option 1: Run the Python Reference Version

```bash
cd HSDesign/python
python ES.py
```

### Option 2: Run the SystemC Version

1. Install and configure SystemC.
2. Open the Visual Studio solution or create a new SystemC C++ project.
3. Add the source files from the `src/` folder.
4. Configure the SystemC include and library directories.
5. Build and run the simulation.

The simulation prints the best chromosome and its fitness value through the monitor module.

## Example Output

The SystemC monitor prints output in this format:

```text
----------------

Chromosome : g1 g2 g3 g4 g5 g6 g7 g8 g9
With value : best_fitness
```

Because the algorithm uses random initialization and mutation, the exact output may change between runs.

## Notes

- The SystemC version is intended as a system-level hardware-software co-design model.
- The Python script is included as a simpler reference implementation of the same optimization approach.
- The project uses continuous chromosome values between 0 and 1 rather than binary item-selection values.
- Since the algorithm uses random numbers, results may vary from one execution to another.
