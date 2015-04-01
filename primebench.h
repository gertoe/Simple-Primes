#ifndef PRIMEBENCH_H
#define PRIMEBENCH_H

#include <stdio.h>
#include <time.h>

long double  t_used(clock_t start, clock_t end);
void primebench(unsigned long start_x, unsigned int n_nums);

#endif

