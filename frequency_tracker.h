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

class FrequencyTracker: public Kalman::EKFilter<double,1,false,true,false>{
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

        double alpha, epsilon;

public:
	FrequencyTracker();
	virtual ~FrequencyTracker();
};

typedef FrequencyTracker::Vector Vector;
typedef FrequencyTracker::Matrix Matrix;

#endif /* FREQUENCYTRACKER_H_ */
