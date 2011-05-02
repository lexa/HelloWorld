/*
 * CircularBuffer.h
 *
 *  Created on: 02.05.2011
 *      Author: lexa
 */


#include "CircularBuffer.h"

size_t
calc_pos(const CircularBuffer * const buf, size_t pos)
{
	return (buf->begin + pos + buf->len)%(buf->len);
}

float
convolution_CircularBuffer_and_vector(const CircularBuffer * const buf, const float * const vec)
{
	size_t i;
	float rez=0.0f;
	for (i=0; i < buf->len; ++i)
	{
		rez += get_elem(buf, i) * vec[i];
	}
	return rez;
}

void
destroy_CircularBuffer(CircularBuffer* buf)
{
	free(buf->data);
	free(buf);
	buf=NULL;
}

CircularBuffer*
create_CircularBuffer(size_t len)
{
	CircularBuffer* buf=NULL;
	if (NULL == (buf = malloc(sizeof(CircularBuffer)))) {
		fprintf (stderr, "can't allocate memory");
		ERREXIT;
	}

	if (NULL == (buf->data = calloc(len, sizeof(int16_t)))) {
		fprintf (stderr, "can't allocate memory");
		free(buf);
		ERREXIT;
	}
	buf->len = len;
	buf->begin = 0;
	return buf;
}

void
push_elem(CircularBuffer * const buf, int16_t elem)
{
	buf->data[buf->begin] = elem;
	buf->begin = calc_pos(buf, 1);
}

int16_t
get_elem(const CircularBuffer * const buf, size_t pos)
{
	return buf->data[calc_pos(buf, pos)];
}


