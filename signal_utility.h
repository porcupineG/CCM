/*
 * SignalUtility.h
 *
 *  Created on: Jul 7, 2012
 *      Author: porcupine
 */

#ifndef SIGNALUTILITY_H_
#define SIGNALUTILITY_H_

#include <vector>
#include <math.h>
#include <complex.h>

using namespace std;

class SignalUtility {
public:
	SignalUtility();
	virtual ~SignalUtility();

	static double power(vector<complex double> s);
	static double MSE(vector<double> s, vector<double> a);


};

#endif /* SIGNALUTILITY_H_ */
