#include <stdio.h>
#include "strings.h"

int main (int argc, char* argv[])
{

  char f[5000];
  getFile (f, 5000);

  printf ("Length: %d\n", length(f));
}
  
  /*
  int i;
  int len;
  
  printf ("\n\nCommand line arguments are:\n");
  for (i=0; i<argc; i++)
  {
    len = length(argv[i]);
    
    printf ("%d: %s; Length=%d\n", i, argv[i], len);
  }
  */  

