#include "systemc.h"
#include <string>

using namespace std;

SC_MODULE(Monitor) {
	sc_in <float> best_choromosome_gen1;
	sc_in <float> best_choromosome_gen2;
	sc_in <float> best_choromosome_gen3;
	sc_in <float> best_choromosome_gen4;
	sc_in <float> best_choromosome_gen5;
	sc_in <float> best_choromosome_gen6;
	sc_in <float> best_choromosome_gen7;
	sc_in <float> best_choromosome_gen8;
	sc_in <float> best_choromosome_gen9;


	sc_in <float> best_fitness;

	void prc_monitor() {
        while (true)
        {
            wait();
			cout << "\n----------------\n\nChromosome : ";

            cout << best_choromosome_gen1 << " ";
            cout << best_choromosome_gen2 << " ";
            cout << best_choromosome_gen3 << " ";
            cout << best_choromosome_gen4 << " ";
            cout << best_choromosome_gen5 << " ";
            cout << best_choromosome_gen6 << " ";
            cout << best_choromosome_gen7 << " ";
            cout << best_choromosome_gen8 << " ";
            cout << best_choromosome_gen9 << " ";

			cout << "\nWith value : ";
            
            cout << best_fitness << "\n";

        }
        		
	}

	SC_CTOR(Monitor) {
		SC_THREAD(prc_monitor);
		sensitive << best_fitness;
	}
};