#include <stdio.h>
#include <time.h>
#include "ndice.h"

int main(void)
{
  int mutfact = 4;
  int x = 0b11111111;
  int seed = time(NULL);
  int somebyte = 0b10000000;
  printf("\n%d\n", somebyte);
    for (int i = 0; i < 8; ++i, somebyte >>= 1) {
      if (ndice(mutfact, &seed) == 1) {
      x ^= somebyte;
      printf("mutated x at %d\n", i);
    }

}
    printf("\n%d\n", x);
}
