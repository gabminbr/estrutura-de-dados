#include <stdio.h>
#include <stdlib.h>

void hm(int mnts, int* h, int* m){
  *h = mnts / 60;
  mnts -= *h * 60;
  *m = mnts;
}

int main(void){
  int min;
  int* h = (int*) malloc(sizeof(int));
  int* m = (int*) malloc(sizeof(int));

  printf("minutos: ");
  scanf("%d", &min);

  hm(min, h, m);

  printf("minutos: %d, horas e min: %d %d\n", min, *h, *m);
  return 0;
}
