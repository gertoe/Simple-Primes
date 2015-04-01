#include "primetest.h"

void primes(unsigned long start_x, unsigned int n_nums) {
  // loop for finding n primes
  unsigned long x = start_x;
  for(unsigned int i=0; i < n_nums; ) {
    if(primetest(x) == 0) {
      x++;
    }
    else {
      printf("%lu\n", x);
      i++;
      x++;
    }
  }
}

int primetest(unsigned long z) {
	char c = 0;
	long a = 1;
	// Durchlaufe solange die Schleife, bis der Divisor a dem Dividenden *z gleich ist
	while(a <= z) {
    // Abbruch, wenn bereits mehr als zwei Teiler gefunden sind.
    if(c > 2)	{
			return 0;
		}
		// Bedingung fuer Primzahl:
		// I. Zahl, die nur zwei Teiler besitzt.
		// II. Zahl ist nur durch sich selbst und 1 teilbar.
		// => Nur Divisionen ohne Rest deuten auf Primzahl hin.
    else if(z % a == 0) {
			a++;
			c++;
		}
		else {
			a++;
		}
	}
  return (c == 2) ? 1 : 0;
}

