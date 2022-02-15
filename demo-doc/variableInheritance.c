#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int getRand(void);

int main(void)
{
  int seed = time(NULL);
  srand(seed);
  
  // var = 1;
  //foo();
  getRand();

}
/*
int foo(void)
{
  getRand(); 
}
*/
int getRand(void)
{
  printf("$d\n", seed);
}
