// mutate
// takes a byte (genome or chromosome)
// iterates through the bits and rolls an ndice
// whose probabilities of returning true are 1/mutfact
// when we get a 1 then we flip the corresponding bit

// this function has a probability of changing a chromosome
// of 8/mutfact

#include <stdio.h>  // for debugging (printf)
#include "ndice.h"  
#include <time.h>   // for intitializing rng
#include "mutate.h"

//#include <stdlib.h> // for atoi



int mutate(int mutfact, int *seed, int *chromo)
{
  int iterator = 0b10000000; // this byte will be used to iterate
                             // through our chromosome

  for (int i = 0; i<8; ++i, iterator >>= 1)
    {
      if (ndice(mutfact, seed) == 1)
	{
	  *chromo ^= iterator;
	}
      // using Xor here guarantees that the bit will flip
    }
  return 0;
}

