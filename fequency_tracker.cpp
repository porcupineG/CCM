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
	A(2,0) = 0.0;
	A(2,1) = 0.0;
}

void FrequencyTracker::makeBaseH() {
	H(0,0) = 1.0;
	H(0,1) = 0.0;
	H(1,0) = 0.0;
	H(1,1) = 1.0;
}

void FrequencyTracker::makeBaseV() {
	V(0,0) = 1.0;
}

void FrequencyTracker::makeBaseR() {
	R(0,0) = r * r;
	R(0,1) = 0.0;
	R(1,0) = 0.0;
	R(1,1) = r * r;
}

void FrequencyTracker::makeBaseW() {
	W(0,0) = 1.0;
	W(0,1) = 0.0;
	W(0,2) = 0.0;

	W(1,0) = 0.0;
	W(1,1) = 1.0;
	W(1,2) = 0.0;

	W(2,0) = 0.0;
	W(2,1) = 0.0;
	W(2,2) = 1.0;

}

void FrequencyTracker::makeBaseQ() {
	Q(0,0) = q * q;
	Q(0,1) = q * q;
	Q(0,2) = 0.0;

	Q(1,0) = q * q;
	Q(1,1) = q * q;
	Q(1,2) = 0.0;

	Q(2,0) = 0.0;
	Q(2,1) = 0.0;
	Q(2,2) = q * q;
}

void FrequencyTracker::makeA() {
	A(0,0) = cos(x(3));
	A(0,1) = -sin(x(3));
	A(0,2) = -x(1) * sin(x(3)) - x(2) * cos(x(3));

	A(1,0) = sin(x(3));
	A(1,1) = cos(x(3));
	A(1,2) = x(1) * cos(x(3)) - x(2) * sin(x(3));

	A(2,2) = (1 - e);
}

void FrequencyTracker::makeH() {
	H(0,0) = 1.0;
	H(0,1) = 0.0;
	H(1,0) = 0.0;
	H(1,1) = 1.0;
}

void FrequencyTracker::makeProcess() {
	static Vector x_(x.size());
	x_(0) = x(0) * cos(x(2)) - x(1) * sin(x(2));
	x_(1) = x(0) * sin(x(2)) + x(1) * cos(x(2));
	x_(2) = x(2) * (1 - e);
	x.swap(x_);
}

void FrequencyTracker::makeMeasure() {
	z(1)= x(1);
//	z(2)= x(2);
}
