#include "ndice.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// test_ndice
// illustrates how to use ndice
// ndice uses time as a seed to its randomness, so calling it
// multiple times in a second would be problematic
// as such this is solved by creating a variable
// seed which is passed on to ndice, which then changes seed
// allowing us to call ndice several times a second and not get
// the same result


int main(int argc, char *argv[])
{
  int seed = time(NULL);
  for (int i=0; i < 20; i++)
    {
      int res = ndice(atoi(argv[1]), &seed);
      printf("%d", res);
    }
  //printf("seed : %d\n", seed);
  
}
