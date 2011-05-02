/*
 * CircularBuffer.h
 *
 *  Created on: 02.05.2011
 *      Author: lexa
 */

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "global.h"

typedef struct {
	size_t len;
	int16_t *data;
	size_t begin;//begin of ring
} CircularBuffer;


void destroy_CircularBuffer(CircularBuffer* buf);
CircularBuffer* create_CircularBuffer(size_t len);

size_t calc_pos(const CircularBuffer * const buf, size_t pos);
float convolution_CircularBuffer_and_vector(const CircularBuffer * const buf, const float * const vec);
void push_elem(CircularBuffer * const buf, int16_t elem);
int16_t get_elem(const CircularBuffer * const buf, size_t pos);


#endif /* CIRCULARBUFFER_H_ */
