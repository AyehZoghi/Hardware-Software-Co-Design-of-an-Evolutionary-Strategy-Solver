import random
from typing import List
import numpy as np


def solve_knapsack():
    population = generate_initial_population()

    expand_population = []
    for chromosome in population:
        expand_population.append((fitness(chromosome), chromosome))

    population = list(expand_population)
    for _ in range(50):
        population = next_generation(population)

    population = sorted(population, key=lambda x: x[0], reverse=True)
    return population[0]


def selection(population: List) -> List:
    parents = []
    random.shuffle(population)
    sorrted1 = sorted(population, key=lambda x: x[0], reverse=True)
    parents.append(sorrted1[0])
    parents.append(sorrted1[1])

    return parents


def crossover(parents: List) -> List:
    s = random.randint(1, NUM_ITEMS)
    child1 = parents[0][1][:s] + parents[1][1][s:]
    child2 = parents[0][1][s:] + parents[1][1][:s]

    return [(fitness(child1), child1), (fitness(child2), child2)]


def mutate(population: List) -> List:
    bounded_number = 1 / (1 + np.exp(-np.random.normal(0, 1)))
    sigma = 1 / (1 + np.exp(-np.random.normal(0, 1)))

    for idx, ch in enumerate(population):
        mutated_ch = list(ch[1])
        for i in range(len(mutated_ch)):
            if random.random() < MUTATION_RATE:
                mutated_ch[i] = mutated_ch[i] + sigma * bounded_number
                temp = 1 / (1 + np.exp(-np.random.normal(0, 1)))
                sigma = sigma * np.exp(bounded_number - temp)
        population[idx] = (ch[0], tuple(mutated_ch))
    return population


def next_generation(population: List) -> List:
    next_gen = []
    children = []
    while len(next_gen) < 10:
        children.clear()

        parents = selection(population)
        if random.random() < CROSSOVER_RATE:
            new_population = [ch for ch in crossover(parents) if ch[0] != 0]
            children = new_population

        if random.random() < MUTATION_RATE:
            new_population = [ch for ch in mutate(parents) if ch[0] != 0]
            children = new_population
        next_gen.extend(children)
    return next_gen


def fitness(ch) -> float:
    total_value = 0
    for i in range(NUM_ITEMS):
        # ch[i] is a gene
        total_value += ch[i] * items[i][1]

    total_weight = 0
    for i in range(NUM_ITEMS):
        total_weight += ch[i] * items[i][0]

    return total_value if total_weight <= MAX_KNAPSACK_WEIGHT else 0


def generate_initial_population(count=10) -> List:
    population = set()

    while len(population) != count:
        gens = tuple([random.random() for _ in range(NUM_ITEMS)])
        if fitness(gens) != 0:
            population.add(gens)
    list(population)
    return list(population)


if __name__ == "__main__":
    MAX_KNAPSACK_WEIGHT = 10
    MUTATION_RATE = 0.1
    CROSSOVER_RATE = 0.8
    REPRODUCTION_RATE = 0.7
    items = [(2, 6), (3, 5), (6, 8), (7, 9), (5, 6), (9, 7), (3, 3), (4, 6), (5, 8)]
    NUM_ITEMS = 9

    print(solve_knapsack())
