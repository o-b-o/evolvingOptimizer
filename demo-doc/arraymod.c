#include <stdio.h>
// test_ndice
// illustrates how to use ndice
// ndice uses time as a seed to its randomness, so calling it
// multiple times in a second would be problematic
// as such this is solved by creating a variable
// seed which is passed on to ndice, which then changes seed
// allowing us to call ndice several times a second and not get
// the same result

int fun(int poo[])
{
  poo[2] ++;
  return 0;
}

int main(int argc, char *argv[])
{

  int a[] = {1,2,3,4};
  printf("%d\n", a[2]);
  fun(a);
  printf("%d\n", a[2]);



  //printf("seed : %d\n", seed);
  
}

