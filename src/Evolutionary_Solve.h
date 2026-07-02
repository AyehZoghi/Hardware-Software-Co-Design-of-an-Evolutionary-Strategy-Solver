#include "systemc.h"
#include <random>

#define POPULATION_SIZE 10
#define MUTATION_RATE  0.8
#define CROSSOVER_RATE  0.8
#define CHROMOSOME_LENGTH 9
#define ITERATION_COUNT 50
#define MAX_KNAPSACK_WEIGHT 10
#define ITEM_NOM 9

using namespace std;


SC_MODULE(Evolutionary_Solve) {

	//sc_in <sc_vector<sc_int<8>>> Value, Weight;
	sc_in <int> Value[9], Weight[9];

	sc_out <float> best_choromosome_gen1;
	sc_out <float> best_choromosome_gen2;
	sc_out <float> best_choromosome_gen3;
	sc_out <float> best_choromosome_gen4;
	sc_out <float> best_choromosome_gen5;
	sc_out <float> best_choromosome_gen6;
	sc_out <float> best_choromosome_gen7;
	sc_out <float> best_choromosome_gen8;
	sc_out <float> best_choromosome_gen9;
	
	sc_out <float> best_fitness;

	// double allFitnesses[POPULATION_SIZE];
	// double bestFitness = 0.0;

	void solve_knapsack();

	SC_CTOR(Evolutionary_Solve) {
		SC_METHOD(solve_knapsack);
		sensitive << Value[0] ;

	}
private:
	int iter = 0;
	double prev_value = 0.0;

	int total_iter = 0;

};