/*
 * LMS.c
 *
 *  Created on: 01.05.2011
 *      Author: lexa
 */

#include "LMS.h"

LMS*
create_LMS(const size_t len)
{
	LMS *l = NULL;
	if (NULL == (l = malloc(sizeof(LMS)))) {
		fprintf (stderr, "can't allocate memory for LMS");
		ERREXIT;
	}

	if (NULL == (l->signal = create_CircularBuffer(len))) {
		fprintf (stderr, "can't create CircularBuffer");
		free (l);
		ERREXIT;
	}

	if (NULL == (l->coeff = calloc(len, sizeof(float)))) {
		fprintf (stderr, "can't allocate memory");
		destroy_CircularBuffer (l->signal);
		free (l);
		ERREXIT;
	}

	l->len = len;
	setMu(l, 0.00000000001);

	return l;
}

void
setMu(LMS * const l, double mu)
{
	l->mu = mu;
	if (0 == mu)
	{
		fprintf(stderr, "0 == mu, LMS NOT WORK\n");
	}
}
void
destroy_LMS(LMS *l)
{
	free(l->coeff);
	destroy_CircularBuffer(l->signal);
	free(l);
	l=NULL;
}

float
make_LMS(LMS * l, int16_t far_, int16_t near_)
{
	push_elem(l->signal, far_);
	float y = convolution_CircularBuffer_and_vector(l->signal, l->coeff);
	float eps = near_ - y;

	size_t i = 0;
	for (i=0; i < l->len; ++i)
	{
		l->coeff[i] +=  l->mu * eps * get_elem(l->signal, i);
	}
	return eps;
}
