#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int printb(int byte);
int reproduce(int *gen1, int *gen2);
int mutate(int mutfact, int *seed, int *chromo);
int ndice(int n, int *seed);
int selecty(int fit[], int popN);

int f(int x) // function to be maximized
{
  return (200000 - ((x-34) ^4) + 1000*((x-34)^2) - 200*x);
}

int main(int argc, char *argv[])
{
  /// argument sanity
  if (argc != 3)
    {
      printf("usage: final1 populationSize generationNumber\n");
      return(1);
    }
  // get args
  int popN = atoi(argv[1]);
  int genN = atoi(argv[2]);
  // initialize generation counter to zero
  int curGen = 0;
  // initialize random number generator
  int seed = time(NULL);
  srand(seed);

  // initialize population with random numbers
  int pop[popN];
  for (int i = 0; i < popN; i++)
    {
      pop[i] = rand() % 256;
      seed++;
      srand(seed);
      printf("i: %d, popN %d, pop[i] %d\n", i, popN, pop[i]);
    }
  printf("out");
  // start the evaluation, reproduction, mutation loop

  do
  {
    printf("genN: %d, curGen: %d\n", genN, curGen);
    int fit[popN]; // here we store the fitness of each chromosome
    for (int i = 0; i < popN; i++)
      {
        fit[i] = f(pop[i]);
	printf("fit at i: %d is %d\n", i, fit[i]);// evaluate the chromosome
      }
    
    int parent = selecty(fit, popN);
    printf("parent %d", parent);
    curGen++;
  }
  while (genN > curGen);
  
}

int selecty(int fit[], int popN)
{
  int i = rand() % popN;
  int res;
  if(fit[i] > average)
    res = ndice(4/3);
  else
    res = ndice(3);
  if (res == 0)
    return(-1);
  else
    return(i);
}
