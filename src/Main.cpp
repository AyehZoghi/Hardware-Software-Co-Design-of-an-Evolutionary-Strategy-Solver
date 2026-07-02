#include "systemc.h"
#include "Evolutionary_Solve.h"
#include "driver.h"
#include "monitor.h"


int sc_main(int argc, char* argv[]) {

	sc_signal <int> Value[9], Weight[9];   

    sc_signal <float> best_choromosome_gen1;
	sc_signal <float> best_choromosome_gen2;
	sc_signal <float> best_choromosome_gen3;
	sc_signal <float> best_choromosome_gen4;
	sc_signal <float> best_choromosome_gen5;
	sc_signal <float> best_choromosome_gen6;
	sc_signal <float> best_choromosome_gen7;
	sc_signal <float> best_choromosome_gen8;
	sc_signal <float> best_choromosome_gen9;

    sc_signal <float> best_fitness;

    driver dr("driver");
    dr.Value[0](Value[0]);
    dr.Value[1](Value[1]);
    dr.Value[2](Value[2]);
    dr.Value[3](Value[3]);
    dr.Value[4](Value[4]);
    dr.Value[5](Value[5]);
    dr.Value[6](Value[6]);
    dr.Value[7](Value[7]);
    dr.Value[8](Value[8]);

    dr.Weight[0](Weight[0]);
    dr.Weight[1](Weight[1]);
    dr.Weight[2](Weight[2]);
    dr.Weight[3](Weight[3]);
    dr.Weight[4](Weight[4]);
    dr.Weight[5](Weight[5]);
    dr.Weight[6](Weight[6]);
    dr.Weight[7](Weight[7]);
    dr.Weight[8](Weight[8]);

    Evolutionary_Solve es("Evolutionary Solve");
    es.Value[0](Value[0]);
    es.Value[1](Value[1]);
    es.Value[2](Value[2]);
    es.Value[3](Value[3]);
    es.Value[4](Value[4]);
    es.Value[5](Value[5]);
    es.Value[6](Value[6]);
    es.Value[7](Value[7]);
    es.Value[8](Value[8]);

    es.Weight[0](Weight[0]);
    es.Weight[1](Weight[1]);
    es.Weight[2](Weight[2]);
    es.Weight[3](Weight[3]);
    es.Weight[4](Weight[4]);
    es.Weight[5](Weight[5]);
    es.Weight[6](Weight[6]);
    es.Weight[7](Weight[7]);
    es.Weight[8](Weight[8]);

   
    es.best_choromosome_gen1(best_choromosome_gen1);
    es.best_choromosome_gen2(best_choromosome_gen2);
    es.best_choromosome_gen3(best_choromosome_gen3);
    es.best_choromosome_gen4(best_choromosome_gen4);
    es.best_choromosome_gen5(best_choromosome_gen5);
    es.best_choromosome_gen6(best_choromosome_gen6);
    es.best_choromosome_gen7(best_choromosome_gen7);
    es.best_choromosome_gen8(best_choromosome_gen8);
    es.best_choromosome_gen9(best_choromosome_gen9);

    es.best_fitness(best_fitness);



    Monitor mr("monitor");

    mr.best_choromosome_gen1(best_choromosome_gen1);
    mr.best_choromosome_gen2(best_choromosome_gen2);
    mr.best_choromosome_gen3(best_choromosome_gen3);
    mr.best_choromosome_gen4(best_choromosome_gen4);
    mr.best_choromosome_gen5(best_choromosome_gen5);
    mr.best_choromosome_gen6(best_choromosome_gen6);
    mr.best_choromosome_gen7(best_choromosome_gen7);
    mr.best_choromosome_gen8(best_choromosome_gen8);
    mr.best_choromosome_gen9(best_choromosome_gen9);

    mr.best_fitness(best_fitness);

	sc_start();

	return(0);

}