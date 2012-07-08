/*
 * SignalUtility.cpp
 *
 *  Created on: Jul 7, 2012
 *      Author: porcupine
 */

#include "signal_utility.h"
#include "defines.h"

SignalUtility::SignalUtility() {
	// TODO Auto-generated constructor stub

}

SignalUtility::~SignalUtility() {
	// TODO Auto-generated destructor stub
}

double SignalUtility::power(vector<complex double> s) {
	double pow = 0;
	for (unsigned int i = 0; i < s.size(); i++) {
		pow = pow + cabs(s[i]) * cabs(s[i]);
	}
	pow = pow / (N);
	return 10 * log(pow);
}

double SignalUtility::MSE(vector<double> s, vector<double> a) {
	double mse = 0;
	for (unsigned int i = 1; i < s.size(); i++) {
		mse = mse + cabs(cabs(s[i]) - cabs(a[i])) * cabs(cabs(s[i]) - cabs(a[i]));
	}
	mse = mse / (N - 1);
	return mse;
}
