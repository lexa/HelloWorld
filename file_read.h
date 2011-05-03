/*
 * file_read.h
 *
 *  Created on: 02.05.2011
 *      Author: lexa
 */

#ifndef FILE_READ_H_
#define FILE_READ_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "global.h"

FILE*
open_file(const char *filename, const char *mode)
{
	FILE *f;
	if (NULL == (f = fopen(filename, mode)))
	{
		fprintf(stderr, "can't open file %s", filename);
		ERREXIT;
	}
	return f;
}

int
close_file(FILE* f)
{
	if (0 != fclose(f))
	{
		fprintf(stderr, "error on closing file");
		ERREXIT ;
	}
	return 1;
}

int16_t *
read_file (FILE *f, size_t len)
{
	int16_t *data = NULL;
	if (NULL == (data = malloc(sizeof(int16_t) * len)))
	{
		fprintf(stderr, "can't allocate memory %lu bytes", sizeof(int16_t) * len );
		ERREXIT ;
	}
	if (len != fread (data, 2, len, f))
	{
		fprintf(stderr, "read to little data, maybe error");
	}

	return data; //незабудь освободить
}

/*
int16_t *
open_read_close (const char * filename, size_t len)
{
	FILE *f=NULL;
	int16_t *rez=NULL;
	if (NULL != (f = open_file(filename, "r")))
	{
		rez = read_file(f, len);
		close_file(f);
	}
	return rez;
}
*/


#endif /* FILE_READ_H_ */
