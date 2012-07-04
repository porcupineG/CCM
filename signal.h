/*
 * Signal.h
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#ifndef Signal_H_
#define Signal_H_

#include "defines.h"

#include <complex.h>
#include <math.h>
#include <vector>
#include <iostream>

using namespace std;

class Signal {
private:
	double phase(int n);

public:
	Signal();
	virtual ~Signal();
	vector<complex double> value;
};

#endif /* Signal_H_ */
