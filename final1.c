// final1
// or evolve solution
// ./final1 population epochs mutationFactor
//
//
/* 
   A program to maximize a function.
   Takes three arguments: "population" - how many chromosomes per
   generation. 
                        "epochs" - how many generations will
			           the program run for.

			"mutationFactor" - the probability that
			                 when reproducing, a chromosome
					 will mutate.
					 it goes as 8/factor.

  The program consists of three main functions:
  * mutate
  * reproduce
  * selectGene 

>>  Mutate <<<<<<<<<<<<<
   INPUT (int mutation factor, int* seed (pointer to an outer seed variable, int* pointer to a chromosome)
   uses the "seed" provided to randomly change
   the chromosome with a probability of 8/"mutfact".
   changes the seed after each use. 
   (*note*) the seed could be handled outside of the function
   but for time reasons I'm leaving it as it, for now.

>>  Reproduce <<<<<<<<<<<<<
    INPUT two genes as arguments. 
    OUTPUT none? / writes results of reproduction to a result
           vector. Does this as a side effect, though..
    in an external array, to avoid changing a population
    dynamically, rather than discreetly.

>> selectGene <<<<<<<<<<<<<
    INPUT a vector containing the fitnesses for each chromosome, the population size (why?? Because I haven't found out how to sizeof(array) without too much trouble)
    OUTPUT
          EITHER an index that points to the chromosome whose fitness won the genetic lottery.
          OR -1
	  when a gene failed to be selected
	  this is why we call the function UNTIL it selects
	  a gene.

    Randomly selects chromosomes for reproduction.
    As it stands now if a subject evaluates in the top 50%
    it will have a 75% chance of reproducing
    else it has a 25% chance.

    (note for further developement)
    This function could be much better by finding a function
    that outputs a number in a range inside [0-1] (a percentage)
    when fed another percentile.
    selectGene( fitnessVector //range: [10,100]) 
      would select a gene from the vector of genes with a probability 
      in the specified range (10, 100) that scales with fitness
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

//int printb(int byte);
int reproduce(int gen1, int gen2, int new[], int j);
int mutate(int mutfact, int *seed, int *chromo);
int ndice(int n, int *seed);
int selectGene(double fit[], int popN, int average, int *seed);
int printb( int byte);

long int f(int x) // function to be maximized
{
  //return(x-255);// for testing, the easiest function
    return (200000 - pow((x-34), 4) + 1000*pow((x-34),2) - 200*x); // actual homework
}

int main(int argc, char *argv[])
{
  /// argument sanity
  if (argc != 4)
    {
      printf("usage: final1 populationSize generationNumber mutationFactor\n");
      return(1);
    }
  // get args
  int popN = atoi(argv[1]);
  int genN = atoi(argv[2]);
  int mutfact = atoi(argv[3]);
  printf("got args\n");


  // initialize generation (epoch, Epch) counter to zero
  int curEpch = 0;
  // initialize random number generator for the first of many times
  int seed = time(NULL);
  srand(seed);

  // initialize chromosome of maximum fitness at zero
  int result = 0;
  
  // initialize population with random numbers
  int pop[popN];


  for (int i = 0; i < popN; i++)
    {
      pop[i] = rand() % 64;
      seed++;
      srand(seed);
      #ifdef DEBUG
      printf("pop[%d] = %d", i, pop[i]);
      #endif
      // DEBUG printf("seed: %d\n", seed);
    }

  
  // start the evaluation, reproduction, mutation loop
  printf("starting main loop\n");
  while (curEpch < genN)
  {
	printf("generation %d start\n", curEpch);

    double fit[popN]; // here we store the fitness of each chromosome
    long long int average = 0;

    // the next loop evaluates each chomosome while summing up their fitness
    // for later selection based on total fitness
    for (int i = 0; i < popN; i++)
      {
        fit[i] = f(pop[i]); // evaluate the chromosome
	average += fit[i];
	if (fit[i] > f(result))
	  {result = pop[i];}
      }
    average /= popN; // now we have the average
	printf("average at epoch %d: %lld\n", curEpch, average);
    // now we select random members of the population for reproduction
    int NewPop[popN]; // here we temporarily store the new population
    for (int i = 0; i < popN; i +=2) // we fill up NewPop by binary reproduction, so it grows in twos.
      {
	int index1 = -1;
	while(index1 == -1) // here we run select with different seeds until it spits out a winner
	{
	  //	  seed++;
//	  srand(seed);
	  index1 = selectGene(fit, popN, average, &seed);
	}
	int index2 = -1; // same as above, for the other parent
	while(index2 == -1)
	  {
	    //	    seed++;
	    //	    srand(seed);
	    index2 = selectGene(fit, popN, average, &seed);
	  }

	reproduce(pop[index1], pop[index2], NewPop, i); // reproduce gets fed the two chosen chromosomes, the result vector and an index, used to navigate the result vector.
	// this is ugly, but memory management in C makes me sleepy #notAnExcuse
	
      }
        printf("new generation: \n");
    for (int i = 0; i < popN; i++)
      {
	//	printf("pop[%d] old:%d, new: %d ", i, pop[i], NewPop[i]);
	printf(" ");
	printb(NewPop[i]);
	mutate(mutfact, &seed, &NewPop[i]);
	pop[i] = NewPop[i];
      }
    printf("\n");
    curEpch++; // epoch grows by one
  }
  printf("the fittest chromosome: %d, its fitness is: %li\n", result, f(result));
}


// end of MAIN program

// following are the function definitions
// in order to save the reader some time, we repeat their ins
// and outs here
// REPRODUCE: in two ints (genes), a result vector and its index
//   out: 0 if success, 1 if failure

// MUTATE: in mutfactor, pointer to seed, pointer to chromosome
//   out: 0, 2 if fail

// SELECTGENE : in fitness vector, population number
//   out: index of winner, -1 if no winner



//%%%%%%%%%%%%%////
//////////////REPRODUCE
//////////////////////

int reproduce(int gen1, int gen2, int new[], int j)
{
  // randomly select a point in the genes for splicing
  int cutoff = rand() % 8;                                              
  int t = 255; // translator, tool to scan the genes; 1111 1111 in  binar\
y                                                                        \
                                                                          
//  printf("reproducing, cutoff = %d\n", cutoff);

  for (int i=0; i < cutoff; i++)
    {
      t >>= 1;
    }

  //printf("t = : ");
  /*  printf("t: ");
  printb(t);
  printf(" ~t: \n");
  printb(~t);
  //printf("\n");
  // store the value of the original genes before we mod them            
  printf("\n");
  printf("gen1: ");
  printb(gen1);
  printf("\n");
  printf("gen2: ");
  printb(gen2);
  printf("\n");
  printf("gen1 & t: ");
  printb(gen1 & t);
  printf("\n");
  printf("gen2 & ~t: ");
  printb(gen2 & ~t);
  printf("\n");

  printf("gen1 & t | gen2 & ~t: ");
  */

  new[j]  = (gen1 & t) | (gen2 & ~t);
  //<  printb(new[j]);
  new[j+1]  = (gen1 & ~t) | (gen2 & t);

  //  printf("gen1: %d, gen2: %d, new1: %d, new2: %d\n", gen1, gen2, new[j], new[j+1]);
return 0;
}

/////////////////---     o*-_i_-*o
///MUTATE///////         i  . .  i   
///////////////---/ /    , , , , ,
int mutate(int mutfact, int *seed, int *chromo)
{
  int iterator = 0b10000000; // this byte will be used to iterate         
                             // through our chromosome                    

  for (int i = 0; i<6; ++i, iterator >>= 1)
    {
      if (ndice(mutfact, seed) == 1)
	{
          *chromo ^= iterator;
	}
      // using Xor here guarantees that the bit will flip                 
    }
  return 0;
}

///////SELECTGENE
/////  the way helps he who helps himself (sometimes)

int selectGene(double fit[], int popN, int average, int *seed)
{
  int i = rand() % popN;
  int res;
  if(fit[i] > average){
    res = 1 - ndice(4, seed);}
  else{
    res = ndice(4, seed);}
  if (res == 0){
    return(-1);}
  else{
    return(i);}
}


/// other functions

/// NDICE
// luck?

// INPUT: n, pointer to seed
// OUTPUT: 1 or 0, outs "1" only 1/n of the times it is run.. ideally.
//   of a mathematical n sided dice                                        

int ndice (int n, int *seed)
{
  *seed +=1;
  srand ( *seed );
  int dice = rand() % n;


  if( dice == 0) // I choose only one of n possibilities,                  
      	      	 // thus ndice has a 1/n possibility of returning 1        
    {
      return(1);
    }
  else
    {
      return(0);
    }

}

///////////
/// PRINTB
//
/// print a byte in binary form

int printb( int byte)
{
  for (int i = 0; i < 8; ++i, byte >>= 1)
    {
      if ( byte & 0x1 )
        printf("1");
      else
        printf("0");
    }
  return 0;
}

