#include "primebench.h"
#include "primes.h"


void primebench(unsigned long long start_x, unsigned int n_nums, char verbose) {
  clock_t start_clk = clock();
  find_primes(start_x, n_nums, verbose);
  clock_t end_clk = clock();
  printf("%Lf sec.", t_used(start_clk, end_clk));
}

long double t_used(clock_t start_clk, clock_t end_clk) {
  return ((long double) (end_clk - start_clk)) / CLOCKS_PER_SEC;
}

