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

using namespace std;

int main() {
	cout << "CCM - EKF frequency tracking" << endl;

	FrequencyTracker frequencyTracker;
	Meas meas;

	static const double _P0[] = {1.0*1.0, 0.0,       0.0,
								 0.0,         0.25*0.25, 0.0,
								 0.0,         0.0,       1.0*1.0};
	Matrix P0(3, 3, _P0);

	Vector x(3);
	x(0) = 0;
	x(1) = 0;
	x(2) = 0;


	frequencyTracker.init(x, P0);
	Matrix Measure(2, N);
	Vector z(2);
	Vector u(0);

	ofstream xfile;
	xfile.open("x.dat");
	for (int i = 2; i <= N; ++i)
	{
		z(1) = meas.In(i);
		z(2) = meas.Qp(i);

		frequencyTracker.step(u, z);
		xfile << frequencyTracker.getX()(3) << endl;
	}

	cout << "CCM - EKF frequency tracking end" << endl;


	return 0;
}
