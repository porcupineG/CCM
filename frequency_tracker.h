/*
 * frequencyTracker.h
 *
 *  Created on: Jul 2, 2012
 *      Author: porcupine
 */

#ifndef FREQUENCYTRACKER_H_
#define FREQUENCYTRACKER_H_

#include "kalman/ekfilter.hpp"
#include <math.h>

class FrequencyTracker: public Kalman::EKFilter<double, 0, false, false, true>{
protected:
        void makeBaseA();
        void makeBaseH();
        void makeBaseV();
        void makeBaseR();
        void makeBaseW();
        void makeBaseQ();

        void makeA();
        void makeH();
        void makeProcess();
        void makeMeasure();

        double e, r, q;

public:
	FrequencyTracker(double epsilon, double r, double q);
	virtual ~FrequencyTracker();
};

typedef FrequencyTracker::Vector Vector;
typedef FrequencyTracker::Matrix Matrix;

#endif /* FREQUENCYTRACKER_H_ */
