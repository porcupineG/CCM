/*
 * Signal.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "signal.h"

Signal::Signal() {
	value.resize(N);
	int n;
	for (n = 0; n < N; n++) {
		value[n] =  A0 * cos(phase(n)) + A0 * sin(phase(n)) * _Complex_I;
	}
}

Signal::~Signal() {

}

double Signal::phase(int n) {

	double p;

	double t = n * Ts;

	if ((t >= 0) && (t < T)) {
		p = -(ALFA * t * t) + F0 * t;
	}

	if ((t >= T) && (t <= 2 * T)) {
		p = (ALFA * t * t) + (F0 * t) - (4 * ALFA * T * t);
	}

	return (p * 2 * M_PI);
}


