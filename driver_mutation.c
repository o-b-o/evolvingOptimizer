#include <stdio.h>  // for debugging (printf)                             
//#include "ndice.h"
#include <time.h>   // for intitializing rng                              
#include "mutate.h"
#include <stdlib.h> // for atoi

int printb( int byte);

int main(int argc, char *argv[])
{
   // safeguard
   if (argc != 3)
    {
        printf("usage: ./driver mutfact chromosome\n");
	return 1;
    }
   int mutfact = atoi(argv[1]);
   int chromo = atoi(argv[2]);
   int original = chromo;
   // printf("chromo1 = %d; ", chromo);
   printb(chromo);
   printf("\n");
   int seed = time( NULL );
   for (int i = 0; i<20; i++)
     {

       mutate( mutfact, &seed, &chromo);
     
   //   printf("\nchromo2 = %d ", chromo);
   printb(chromo);
   printf("\n");
   chromo = original;
     }
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
}

