/*
 * fequencyTracker.cpp
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#include "frequency_tracker.h"

#include <iostream>

using namespace std;

FrequencyTracker::FrequencyTracker(double e, double r, double q) {
	setDim(3, 0, 3, 1, 1);

	this->e = e;
	this->r = r;
	this->q = q;

}

FrequencyTracker::~FrequencyTracker() {

}

void FrequencyTracker::makeBaseA() {
	//A(1,1) = cos(x(3));
	//A(1,2) = -sin(x(3));
	//A(1,3) = -x(1) * sin(x(3)) - x(2) * cos(x(3));

	//A(2,1) = sin(x(3));
	//A(2,2) = cos(x(3));
	//A(2,3) = x(1) * cos(x(3)) - x(2) * sin(x(3));

	A(3,1) = 0.0;
	A(3,2) = 0.0;
	//A(3,3) = (1 - epsilon);
}

void FrequencyTracker::makeBaseH() {
	H(1,1) = 1.0;
	H(1,2) = 0.0;
	H(2,1) = 0.0;
	H(2,2) = 1.0;
}

void FrequencyTracker::makeBaseV() {
	V(1,1) = 1.0;
//	V(1,2) = 0.0;
//	V(2,1) = 0.0;
//	V(2,2) = 1.0;
}

void FrequencyTracker::makeBaseR() {
	R(1,1) = r * r;
	R(1,2) = 0.0;
	R(2,1) = 0.0;
	R(2,2) = r * r;
}

void FrequencyTracker::makeBaseW() {
	W(1,1) = 1.0;
	W(1,2) = 0.0;
	W(1,3) = 0.0;

	W(2,1) = 0.0;
	W(2,2) = 1.0;
	W(2,3) = 0.0;

	W(3,1) = 0.0;
	W(3,2) = 0.0;
	W(3,3) = 1.0;

}

void FrequencyTracker::makeBaseQ() {
	Q(1,1) = q * q;
	Q(1,2) = q * q;
	Q(1,3) = 0.0;

	Q(2,1) = q * q;
	Q(2,2) = q * q;
	Q(2,3) = 0.0;

	Q(3,1) = 0.0;
	Q(3,2) = 0.0;
	Q(3,3) = q * q;
}

void FrequencyTracker::makeA() {
	A(1,1) = cos(x(3));
	A(1,2) = -sin(x(3));
	A(1,3) = -x(1) * sin(x(3)) - x(2) * cos(x(3));

	A(2,1) = sin(x(3));
	A(2,2) = cos(x(3));
	A(2,3) = x(1) * cos(x(3)) - x(2) * sin(x(3));

	//A(3,1) = 0.0;
	//A(3,2) = 0.0;
	A(3,3) = (1 - e);
}

void FrequencyTracker::makeH() {
	//H(1,1) = 1.0;
	//H(1,2) = 0.0;
	//H(2,1) = 0.0;
	//H(2,2) = 1.0;
}

void FrequencyTracker::makeProcess() {
	static Vector x_(x.size());
	x_(1) = x(1) * cos(x(3)) - x(2) * sin(x(3));
	x_(2) = x(1) * sin(x(3)) + x(2) * cos(x(3));
	x_(3) = x(3) * (1 - e);
	x.swap(x_);
}

void FrequencyTracker::makeMeasure() {
	z(1)= x(1);
//	z(2)= x(2);
}
