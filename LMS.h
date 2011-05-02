/*
 * LMS.h
 *
 *  Created on: 01.05.2011
 *      Author: lexa
 */

#ifndef LMS_H_
#define LMS_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "CircularBuffer.h"
#include "global.h"

typedef struct {
	size_t len;
	float * coeff;
	CircularBuffer * signal;
	double mu;
} LMS;


float make_LMS(LMS *l, int16_t, int16_t);
LMS* create_LMS(const size_t len);
void destroy_LMS(LMS *l);
void setMu(LMS * const l, double mu);


#endif /* LMS_H_ */
