#define MAX 127
#include <stdio.h>

int main(){
  int count[15];
  int ch;
  int i;

  for (i=0; i<15; i++){
    count[i] = 0;
    ch = getchar();
}
  while (ch != EOF){
    printf("%c", ch);

    count[ch]++;
    ch = getchar();
}

  for (ch = 'A'; ch = 'Z'; ch++){
    if (count[ch]>0){
      printf("%c %d\n", ch, count[ch]);
    }
}
}
