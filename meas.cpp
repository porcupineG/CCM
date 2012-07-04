/*
 * meas.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "meas.h"

Meas::Meas() {
	Y = Vector(N);
	Qp = Vector(N);
	In = Vector(N);

	ofstream yfile;
	yfile.open("y.dat");
	for (int n = 0; n < N; n++) {
		Y(n) = cabs(signal.value[n] + An * noise.value[n]) * cos(carg(signal.value[n] + An * noise.value[n]));
		yfile << Y(n) << endl;
	}
	yfile.close();


	ofstream infile;
	infile.open("in.dat");
	for (int n = 0; n < N; n++) {
			In(n) = Y(n) * cos(carg(signal.value[n] + An * noise.value[n]));
			infile << In(n) << endl;
	}
	infile.close();

	ofstream qpfile;
	qpfile.open("qp.dat");
	for (int n = 0; n < N; n++) {
			Qp(n) = Y(n) * sin(carg(signal.value[n] + An * noise.value[n]));
			qpfile << Qp(n) << endl;
	}
	qpfile.close();

}

Meas::~Meas() {
	// TODO Auto-generated destructor stub
}

