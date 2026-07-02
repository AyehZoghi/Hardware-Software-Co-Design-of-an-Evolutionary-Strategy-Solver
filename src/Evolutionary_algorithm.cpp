#include "Evolutionary_Solve.h"

static int value[CHROMOSOME_LENGTH], weight[CHROMOSOME_LENGTH];

static bool firstTime = true;

double sigma_table[POPULATION_SIZE][CHROMOSOME_LENGTH];
std::random_device m_RandomDevice;
std::mt19937 m_Eng;
std::normal_distribution<double> n_dist;
std::uniform_real_distribution<double> u_dist;

void bubbleSortSelection(double population[POPULATION_SIZE][CHROMOSOME_LENGTH], double sortedPopulation[POPULATION_SIZE][CHROMOSOME_LENGTH]);

void initialRandomPopulation(double population[POPULATION_SIZE][CHROMOSOME_LENGTH]) {
    for (int i = 0; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < CHROMOSOME_LENGTH; j++)
        {
            double random = u_dist(m_Eng); 
            population[i][j] = random;
        }
    }
}

double fitness(double ch[], int value[], int weight[]) {
    double total_value = 0;
    double total_weight = 0;

    for (int i = 0; i < CHROMOSOME_LENGTH; ++i) {
        total_value += ch[i] * value[i];
        total_weight += ch[i] * weight[i];
    }

    return (total_weight <= MAX_KNAPSACK_WEIGHT) ? total_value : 0;
}

void selecetion(double parents[2][CHROMOSOME_LENGTH], double population[POPULATION_SIZE][CHROMOSOME_LENGTH]){
    int randomIndex1 = (rand() % POPULATION_SIZE) + 1 ;
    int randomIndex2 = (rand() % POPULATION_SIZE) + 1 ;
    for(int i=0 ; i<CHROMOSOME_LENGTH; i++){
        parents[0][i] = population[randomIndex1][i];
        parents[1][i] = population[randomIndex2][i];
    }
}

void cross_over(double parents[2][CHROMOSOME_LENGTH], double children[2][CHROMOSOME_LENGTH]){
    int randomIndex = (rand() % (CHROMOSOME_LENGTH - 1)) + 1;
    for (int i = 0; i < randomIndex ; i++) {
        children[0][i] = parents[0][i];
        children[1][i] = parents[1][i];
    }
    for (int i = randomIndex; i < CHROMOSOME_LENGTH; i++) {
        children[0][i] = parents[1][i];
        children[1][i] = parents[0][i];
    }
}

double generate_normal_random(double mean, double stddev)
{
    return n_dist(m_Eng);
}

void mutation(double chromosomes[POPULATION_SIZE][CHROMOSOME_LENGTH]){
       
    double sigma_exp = generate_normal_random(0, 1);

    for (int j =0 ; j< POPULATION_SIZE; j++){

		if ((u_dist(m_Eng)) < MUTATION_RATE) {
				for (int i = 0; i < CHROMOSOME_LENGTH; i++) {

					double N_0_1 = generate_normal_random(0, 1);
					chromosomes[j][i] = chromosomes[j][i] + sigma_table[j][i] * N_0_1;
			        sigma_table[j][i] *= exp(sigma_exp - generate_normal_random(0, 1));

				}
		}
    }
}

void next_generation(double population[POPULATION_SIZE][CHROMOSOME_LENGTH],double next_gen[POPULATION_SIZE][CHROMOSOME_LENGTH]){

    for (int i = 0; i < POPULATION_SIZE; i++) {
		for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
			next_gen[i][j] = population[i][j];
		}
    }
    

    if((u_dist(m_Eng)) < CROSSOVER_RATE){

		double parents[2][CHROMOSOME_LENGTH];

	    selecetion(parents, population);


		double children[2][CHROMOSOME_LENGTH];
		cross_over(parents, children);

		for (int k = 0; k < 2; k++) {

			for (int z = 0; z < CHROMOSOME_LENGTH; z++) {
				next_gen[POPULATION_SIZE - k - 1][z] = children[k][z];
			}

		}
		
    }

    mutation(next_gen);

	for (int i = 0; i < POPULATION_SIZE; i++) {
		for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
            if (next_gen[i][j] < 0.0) {
                next_gen[i][j] = 0.0;
            }
			if (next_gen[i][j] > 1.0) {
				next_gen[i][j] = 1.0;
			}
		}
	}

}

void Evolutionary_Solve::solve_knapsack(){
    if (firstTime) {
	    m_Eng = std::mt19937(m_RandomDevice());
	    n_dist = std::normal_distribution<double>(0.0, 1.0);
	    u_dist = std::uniform_real_distribution<double>(0.0, 1.0);

	    for (int i = 0; i < POPULATION_SIZE; i++) {
		    for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
			    sigma_table[i][j] = 1.0;
		    }
	    }
        firstTime = false;
        return;
    }


    srand(time(0));

	for (int i = 0; i < ITEM_NOM; i++) {
		//CHECK LATER
		value[i] = (Value[i].read());
		weight[i] = (Weight[i].read());
	}


	double population[POPULATION_SIZE][CHROMOSOME_LENGTH];
	initialRandomPopulation(population);

    double sorted_population[POPULATION_SIZE][CHROMOSOME_LENGTH];


    while(iter < 5 || total_iter < 5){

		double temp_population[POPULATION_SIZE][CHROMOSOME_LENGTH];
		next_generation(population, temp_population);

		for (int i = 0; i < POPULATION_SIZE; i++) {
			for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
				population[i][j] = temp_population[i][j];
			}
		}

        bubbleSortSelection(population,sorted_population);

		for (int i = 0; i < POPULATION_SIZE; i++) {
			for (int j = 0; j < CHROMOSOME_LENGTH; j++) {
				population[i][j] = sorted_population[i][j];
			}
		}

		double f = fitness(sorted_population[0], value, weight);
        if (abs(f - prev_value) < 0.01 && f != 0) {
            prev_value = f;
            iter++;
        }
        else {
            prev_value = f;
            iter = 0;
        }

        std::cout << "value in current iteration: " << (f) << "\n";
        total_iter++;
    }

	best_choromosome_gen1.write(sorted_population[0][0]);
	best_choromosome_gen2.write(sorted_population[0][1]);
	best_choromosome_gen3.write(sorted_population[0][2]);
	best_choromosome_gen4.write(sorted_population[0][3]);
	best_choromosome_gen5.write(sorted_population[0][4]);
	best_choromosome_gen6.write(sorted_population[0][5]);
	best_choromosome_gen7.write(sorted_population[0][6]);
	best_choromosome_gen8.write(sorted_population[0][7]);
	best_choromosome_gen9.write(sorted_population[0][8]);

    double best = fitness(sorted_population[0], value, weight);
	best_fitness.write(best);

}

void bubbleSortSelection(double population[POPULATION_SIZE][CHROMOSOME_LENGTH],double sortedPopulation[POPULATION_SIZE][CHROMOSOME_LENGTH]){

    for (int i = 0; i < POPULATION_SIZE; i++){
        for (int j = 0; j < CHROMOSOME_LENGTH; j++){
            sortedPopulation[i][j] = population[i][j];
        }
    }   

    for (int i = 0; i < POPULATION_SIZE; ++i){
        for (int j = 0; j < POPULATION_SIZE - i; ++j){
            if((fitness(sortedPopulation[j], value, weight))<
            (fitness(sortedPopulation[j+1], value,weight) )){

             double temp;
                for(int l =0 ;l< CHROMOSOME_LENGTH ; l++){
                    temp = sortedPopulation[j][l];
                    sortedPopulation[j][l] = sortedPopulation[j+1][l];
                    sortedPopulation[j+1][l] = temp;
                }                   
                              
            }
        }

    }


}
