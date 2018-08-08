#include "primes.h"
#include <math.h>

inline int even(unsigned long long *x)
{
  // equivalent to: return (1 & *x) ? 0 : 1;
  return !(1 & *x);
}

// calculates a mod b more efficiently on some architectures
inline unsigned long long mod(unsigned long long *a, unsigned long long b)
{
  return *a - (b * (*a/b));
}

void find_primes(unsigned long long start_x, unsigned long long end_x, char verbose)
{
  // loop for finding primes from start_x to end_x
  for(unsigned long long i = start_x; i <= end_x; ++i)
  {
    if(is_prime(&i))
    {
      printf("%llu\n", i);
    }
    else
    {
      continue;
    }
  }
}

inline int is_prime(unsigned long long *z)
{
  // use for optimized variant (search up to square root of number)
  unsigned long long limit = (unsigned long long)sqrtl(*z);

  // ugly binary nesting for performance improvement
  // corner cases...
  if (*z <= 1)
  {
    return 0;
  }
  else
  {
    if (*z <= 3)
    {
      return 1;
    }
    // ... up to here
    else
    {
      // This is checked so that we can skip
      // middle five numbers in below loop
      //if (!(*z%2) || !(*z%3))
      //if ((even(z)) || !(*z%3))
      if ((even(z)) || !mod(z, 3))
      {
        return 0;
      }
      else
      {
        // use pseudo blocking (see above) to speed up calculation
        for (unsigned long i = 5; i <= limit; i += 6)
        {
          if (!mod(z, i) || !mod(z, i+2))
          {
            return 0;
          }
          else
          {
            continue;
          }
        }
      }
    }
  }

  // true if prime
  return 1;
}

