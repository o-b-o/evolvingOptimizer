// select returns an index that points to a chromosome
// the probability of a chromosome being returned is 25 % if it is below
// average and 75% if it is above average

int select(int fit[], popN)
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
