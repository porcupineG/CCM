/*
 * SignalUtility.h
 *
 *  Created on: Jul 7, 2012
 *      Author: porcupine
 */

#ifndef SIGNALUTILITY_H_
#define SIGNALUTILITY_H_

#include <vector>

using namespace std;

class SignalUtility {
public:
	SignalUtility();
	virtual ~SignalUtility();

	double power(vector<double> s);
	double var(vector<double> s);
	double E(vector<double> s);
	double SNR(vector<double> s, vector<double> n);
	double MSE(vector<double> s, vector<double> a);


};

#endif /* SIGNALUTILITY_H_ */
