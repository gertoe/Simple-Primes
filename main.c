#include <stdio.h>
#include <stdlib.h>
#include "primes.h"
#include "primebench.h"
#include "docopt.c"

typedef struct {
  unsigned long long start,
                     end;
} numbers;

int main(int argc, char *argv[]) {

  DocoptArgs args = docopt(argc, argv, /* help */ 1, /* version */ "0.1 ALPHA");

  unsigned int threads = 1,
               verbose = args.verbose;

  unsigned long long start_val,
                     end_val,
                     step;


  sscanf(args.startnum,"%llu",&start_val);
  sscanf(args.endnum,"%llu",&end_val);
  sscanf(args.threads,"%u",&threads);

  step = (unsigned long long) ((end_val - start_val) / ((unsigned long long) threads));

  printf("start_val %llu\nend_val %llu\nthreads %u\n", start_val, end_val, threads);

  n_primes(start_val, start_val + step, verbose);



  return 0;
}

