#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "primetest.h"
#include "primebench.h"

/* #include "primeusage.h" //TODO: usage output, optionally outsourced*/

char isNumber(char *input) {
    for (int i = 0; input[i] != '\0'; i++)
        if (isalpha(input[i]))
            return 0;
    return 1;
}

int main(int argc, char *argv[]) {

  unsigned long x = 0;  // default start
  unsigned int  n = -1; // default nums: "infinite" (with buffer overflow)

  // OPTIONS TODO: fix faulty inputs, return usage
  int c;
  char *svalue = NULL;
  char *nvalue = NULL;
  int bflag = 0;

  opterr = 0;
  while ((c = getopt (argc, argv, "s:n:b")) != -1)
    switch (c)
    {
      case 's':
        if (isNumber(optarg)==1) {
          svalue = optarg;
          sscanf(svalue, "%ld", &x);
          break;
        }
        else 
         EXIT_FAILURE;
      case 'n':
        if (isNumber(optarg)==1) {
        nvalue = optarg;
        sscanf(nvalue, "%d", &n);
        break;
        }
        else
         EXIT_FAILURE;
      case 'b':
        bflag = 1;
        break;
      case '?':
        if (optopt == 's' || optopt == 'n')
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option '-%c'.\n", optopt);
        else
          fprintf (stderr, "Unknown option character '\\x%x'.\n", optopt);
        return 1;
      default:
        abort ();
    }

  if(bflag==1) {
    primebench(x,n);
  }
  else {
    primes(x,n);
  }

  printf("\n");

  return 0;
}

