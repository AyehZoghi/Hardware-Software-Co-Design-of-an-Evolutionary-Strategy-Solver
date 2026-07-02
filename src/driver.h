#include "systemc.h"

SC_MODULE(driver) {
	sc_out <int> Value[9], Weight[9];


	void prc_driver() {

		Value[0].write(6);
		Value[1].write(5);
		Value[2].write(8);
		Value[3].write(9);
		Value[4].write(6);
		Value[5].write(7);
		Value[6].write(3);
		Value[7].write(6);
		Value[8].write(8);

		Weight[0].write(2);
		Weight[1].write(3);
		Weight[2].write(6);
		Weight[3].write(7);
		Weight[4].write(5);
		Weight[5].write(9);
		Weight[6].write(3);
		Weight[7].write(4);
		Weight[8].write(5);

	}

	SC_CTOR(driver) {
		SC_METHOD(prc_driver);
		sensitive << Value[0];
	}
};