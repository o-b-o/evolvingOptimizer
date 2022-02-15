#include <stdlib.h>
#include <stdio.h>
#include "ndice.h"
///  ndice
//   N sided dice
///  input is an integer, output is a 1 or 0 depending on the roll
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
