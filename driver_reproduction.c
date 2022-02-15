#include <stdio.h>  // for debugging (printf)                             
//#include "ndice.h"
#include <time.h>   // for intitializing rng                             
#include <stdlib.h> // for atoi

int printb( int byte);
int reproduce(int *gen1, int *gen2);

int main(int argc, char *argv[])
{
   // safeguard
   if (argc != 3)
    {
        printf("usage: ./driver gene1 gene2\n");
	return 1;
    }
   int gen1 = atoi(argv[1]);
   int gen2 = atoi(argv[2]);

   printb(gen1);
   printf("\n");
   printb(gen2);
   printf("\n");
   
   int seed = time( NULL );
   srand(seed);
   
   reproduce(&gen1, &gen2);

   printb(gen2);
   printf("\n");
   printb(gen1);
   printf("\n");

   seed++;

}

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
  printf("\n");
}


int reproduce(int *gen1, int *gen2)
{
  // randomly select a point in the genes for splicing

  
  int cutoff = rand() % 8;
  int t = 255; // translator, tool to scan the genes; 1111 1111 in  binary
  printf("reproducing, cutoff = %d\n", cutoff); 

  for (int i=0; i < cutoff; i++)
    {
      t >>= 1;
    }

  printf("t = : ");
  printb(t);
  printf("\n");
  // store the value of the original genes before we mod them                 
  int a = *gen1;
  int b = *gen2;

  *gen1 = (a & t) | (b & ~t);
  *gen2 = (a & ~t) | (b & t);
  
return 0;
}


    
