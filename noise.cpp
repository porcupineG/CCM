/*
 * Noise.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "noise.h"

#include <iostream>
#include <fstream>
#include <math.h>
#include <complex.h>

using namespace std;

Noise::Noise() {
	value.resize(N);

	for (int n = 0; n < N; n++) {
		value[n] = An * gaussrand();
	}

	for (int n = 0; n < N; n++) {
		value[n] += An * gaussrand() * _Complex_I;
	}

	ofstream infile;
	infile.open("n.dat");
	for (int n = 0; n < N; n++) {
			infile << cabs(value[n]) * cos(carg(value[n])) << " " << (n * Ts) << endl;
	}
	infile.close();
}

Noise::~Noise() {
	// TODO Auto-generated destructor stub
}

double Noise::gaussrand() {
	static double V1, V2, S;
	static int phase = 0;
	double X;

	if(phase == 0) {
		do {
			double U1 = (double) rand() / RAND_MAX;
			double U2 = (double) rand() / RAND_MAX;

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;

			} while(S >= 1 || S == 0);

		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);

	phase = 1 - phase;

	//cout << X << endl;
	return X;
}
