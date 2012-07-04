/*
 * Noise.h
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#ifndef Noise_H_
#define Noise_H_

#include "defines.h"
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Noise {
private:
	double gaussrand();

public:
	Noise();
	virtual ~Noise();
	vector<complex double>  value;
};

#endif /* Noise_H_ */
