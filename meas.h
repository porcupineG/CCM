/*
 * meas.h
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#ifndef MEAS_H_
#define MEAS_H_

#include <fstream>


#include "frequency_tracker.h"
#include "defines.h"
#include "noise.h"
#include "signal.h"

class Meas {
private:
	Noise noise;
	Signal signal;

public:
	Meas();
	virtual ~Meas();
	Vector In;
	Vector Qp;
	Vector Y;
};

#endif /* MEAS_H_ */
