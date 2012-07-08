/*
 * meas.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "meas.h"
#include "signal_utility.h"

Meas::Meas() {
	Y = Vector(N);
	Qp = Vector(N);
	In = Vector(N);

	ofstream yfile;
	yfile.open("y.dat");
	for (int n = 0; n < N; n++) {
		Y(n) = cabs(signal.value[n] + noise.value[n]) * cos(carg(signal.value[n] + noise.value[n]));
		//Y(n) = cabs(signal.value[n] + 0 * noise.value[n]) * cos(carg(signal.value[n] + An * noise.value[n]));
		yfile << Y(n) << " " << (n * Ts) << endl;
	}
	yfile.close();


	ofstream infile;
	infile.open("in.dat");
	for (int n = 0; n < N; n++) {
			In(n) = Y(n) * cos(carg(signal.value[n] + noise.value[n]));
			infile << In(n) << " " << (n * Ts) <<  endl;
	}
	infile.close();

	ofstream qpfile;
	qpfile.open("qp.dat");
	for (int n = 0; n < N; n++) {
			Qp(n) = Y(n) * sin(carg(signal.value[n] + noise.value[n]));
			qpfile << Qp(n) << endl;
	}
	qpfile.close();

	ofstream fqnfile;
	fqnfile.open("fqn.dat");
	for (int n = 1; n < N; n++) {
			double p1 = carg(signal.value[n - 1] + noise.value[n - 1]);
			double p2 = carg(signal.value[n] + noise.value[n]);

			fqnfile << (p2 - p1) / (Ts * 2 * M_PI) << endl;
	}
	fqnfile.close();


	cout << "signal: " << SignalUtility::power(signal.value) << endl;
	cout << "noise: " << SignalUtility::power(noise.value) << endl;
	cout << "SNR: " << SignalUtility::power(signal.value) - SignalUtility::power(noise.value) << endl;



}

Meas::~Meas() {
	// TODO Auto-generated destructor stub
}

