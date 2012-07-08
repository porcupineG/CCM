/*
 * Signal.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "signal.h"
#include "signal_utility.h"
#include <fstream>
#include <math.h>
#include <complex.h>

Signal::Signal() {
	value.resize(N);
	int n;
	for (n = 0; n < N; n++) {
		value[n] =  A0 * cos(phase(n)) + A0 * sin(phase(n)) * _Complex_I;
	}

	ofstream infile;
	infile.open("fq.dat");
	for (int n = 1; n < N; n++) {
			infile << (phase(n) - phase(n - 1)) / (Ts * 2 * M_PI) << " " << (n * Ts) << endl;
			frequency.push_back((phase(n) - phase(n - 1)) / (Ts * 2 * M_PI));
	}
	infile.close();

	infile.open("s.dat");
	for (int n = 0; n < N; n++) {
			infile << cabs(value[n]) * cos(carg(value[n])) << " " << (n * Ts) << endl;
	}
	infile.close();
}

Signal::~Signal() {

}

double Signal::phase(int n) {

	double p;

	double t = n * Ts;

	if ((t >= 0) && (t <= T)) {
		p = -ALFA * t * t + F0 * t;
//		p = -2 * ALFA * t + F0;
	}

	if ((t > T) && (t <= 2 * T)) {
		p = ALFA * t * (t - 4 * T) + F0 * t + 2 * ALFA * T * T;
//		p = 2 * ALFA * (t - 2 * T) + F0;
	}

	return (p * 2 * M_PI);
}


