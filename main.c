#include <stdio.h>
#include <stdlib.h>

#include "primes.h"
#include "primebench.h"

#include "docopt.c"

int main(int argc, char *argv[])
{
  DocoptArgs args = docopt(argc, argv, /* help */ 1, /* version */ "VERSION ALPHA");

  unsigned int threads = 1,
               verbose = args.verbose;

  unsigned long long start_val,
                end_val;

  sscanf(args.startnum,"%llu",&start_val);
  sscanf(args.endnum,"%llu",&end_val);
  sscanf(args.threads,"%u",&threads);

  // VERBOSE INFORMATION OUTPUT
  if (verbose)
  {
    printf(
        "start_val %llu\nend_val %llu\nthreads %u\n", \
        start_val, \
        end_val, \
        threads \
        );
  }

  // start calculation
  primebench(start_val, end_val, 1, verbose);

  return 0;
}

