/*
 * global.h
 *
 *  Created on: 02.05.2011
 *      Author: lexa
 */

#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdlib.h>
#include "config.h"

#ifdef EXIT_ON_ERROR
#define ERREXIT exit(1)
#else
#define ERREXIT return(0)
#endif

#endif /* GLOBAL_H_ */
