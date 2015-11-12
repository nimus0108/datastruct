#include <stdio.h>

int length (char str[])
{
  int i =0;
  while (str[i] != '\0')
    i++;

  return i;
}

int getFile (char s[], int lim)
{
  int c, pos;

  pos = 0;
  c = getchar();

  while ((c != EOF) && (pos < (lim-1)))
  {
    s[pos] = c;
    pos++;
    c = getchar();    
  }
  s[pos] = '\0';

  return pos;
}
