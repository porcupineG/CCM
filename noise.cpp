/*
 * Noise.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "noise.h"

Noise::Noise() {
	value.resize(N);

	for (int n = 0; n < N; n++) {
		value[n] = 0.1 * gaussrand();
	}

	for (int n = 0; n < N; n++) {
		value[n] += gaussrand() * _Complex_I;
	}
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

	return X;
}
