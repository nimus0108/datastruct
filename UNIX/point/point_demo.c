#include <stdio.h>
#include <stdlib.h>
#include "point.h"

int main()
{
  Point *p1;
  Point *p2;
  char temp1[15];


  p1 = createPoint (10, 12);
  p2 = createPoint (-5, 12);

  movePoint (p1, 10, 3);

  dilatePoint (p2, 2);

  printf ("Point 1: %s\n", pointToString (p1, temp1));
  printf ("Point 2: %s\n", pointToString (p2, temp1));
  
  free (p1);
  free (p2);
}

  
