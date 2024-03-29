/*
 * Main.cpp
 *
 *  Created on: Jun 25, 2012
 *      Author: porcupine
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>

#include "kalman/ekfilter.hpp"
#include "frequency_tracker.h"
#include "meas.h"
#include "signal_utility.h"
#include "signal.h"

using namespace std;

int main(int argc, char* argv[]) {
	double e, r, q;

	cout << "--- CCM - EKF frequency tracking" << endl;
	if (argc != 4) {
		return 0;
	}

	e = atof(argv[1]);
	r = atof(argv[2]);
	q = atof(argv[3]);

	cout << "Params: " << e << r << q << endl;

	FrequencyTracker frequencyTracker(e, r, q);
	Meas meas;


	static const double _P0[] = { 1.0, 0.0, 0.0,
								  0.0, 1.0, 0.0,
								  0.0, 0.0, 1.0
								};
	Matrix P0(3, 3, _P0);

	Vector x(3);
	x(0) = 0.1;
	x(1) = 0.1;
	x(2) = 0.1;

	frequencyTracker.init(x, P0);
	Vector z(1);
	Vector u(3);

	vector<double> xx;

	ofstream xfile;
	xfile.open("x.dat");
	for (int i = 0; i < N; ++i) {
		z(0) = meas.Y(i);

		frequencyTracker.step(u, z);
		xfile << abs(frequencyTracker.getX()(2)) / (2 * M_PI * Ts) << " " << (i * Ts) << endl;
		xx.push_back(abs(frequencyTracker.getX()(2)) / (2 * M_PI * Ts));
	}
	xfile.close();

	Signal ss;
	cout << "MSE: " << SignalUtility::MSE(xx, ss.frequency) << endl;

	cout << "CCM - EKF frequency tracking end" << endl;

	system("./plot.py");

	frequencyTracker.~FrequencyTracker();

	return 0;
}
