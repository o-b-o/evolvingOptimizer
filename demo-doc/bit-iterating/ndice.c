#include <stdlib.h>
#include <stdio.h>
///  ndice
//   N sided dice
///  input is an integer, output is a 1 or 0 depending on the roll
//   of a mathematical n sided dice

int ndice (int n, int *seed)
{
  srand ( *seed );
  int dice = rand() % n;
  *seed +=1;

  if( dice < 1)
    {
      return(1);
    }
  else
    {
      return(0);
    }

}
