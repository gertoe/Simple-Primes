#include "primes.h"
#include "math.h"

void n_primes(unsigned long long start_x, unsigned long long n, char verbose)
{
  // loop for finding n primes from start_x
  unsigned long long x = start_x;
  for(unsigned long long i = start_x; i < n; )
  {
    if(!check_num(x))
    {
      ++x;
    }
    else
    {
      // Verbose output
      if(!verbose)
      {
        printf("%llu\n", x);
      }
      ++i;
      ++x;
    }
  }
}

void find_primes(unsigned long long start_x, unsigned long long end_x, char verbose)
{
  // loop for finding primes from start_x to end_x
  for(unsigned long long i = start_x; i <= end_x; )
  {
    if(check_num(i))
    {
      // Verbose output
      if(verbose != 0)
      {
        printf("%llu\n", i);
      }
    }
    i++;
  }
}

inline int check_num(unsigned long long z)
{
  unsigned long long sz = (unsigned long long)sqrtl(z);

  char c = 0;
  unsigned long long a = 1;
  // Durchlaufe solange die Schleife, bis der Divisor a dem Dividenden *z gleich ist
  while(a <= sz)
  {
    // Abbruch, wenn bereits mehr als zwei Teiler gefunden sind.
    if(c > 1 || z == 1)
    {
      return 0;
    }
    // Bedingung fuer Primzahl:
    // I. Zahl, die genau zwei Teiler besitzt.
    // II. Zahl ist nur durch sich selbst und 1 teilbar.
    // => Nur Divisionen ohne Rest deuten auf Primzahl hin.
    else if(z % a == 0)
    {
      ++a;
      ++c;
    }
    else
    {
      ++a;
    }
  }
  return (c == 1) ? 1 : 0;
}

