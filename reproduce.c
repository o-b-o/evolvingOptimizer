
int reproduce(int gen1, int gen2, int new[], j)
{
  // randomly select a point in the genes for splicing                       int cutoff = rand() % 8;
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
  new[j]  = (gen1 & t) | (gen2 & ~t);
  new[j+1]  = (gen1 & ~t) | (gen2 & t);

return 0;
}

