#include <stdio.h>
#define FREEZING 32
#define BOILING 212

float f_to_c(int f){
  float d = ((f-32) * 5) *1.0;
  d = d/9;
  return d;
}

main(){
  int i;
  printf("%13s    %13s\n","Fahrenheit", "Celcius");

  for (i=FREEZING; i<(BOILING+1); i+=10){
    printf("%13d    %13.1f\n",i, f_to_c(i));
    }
}
