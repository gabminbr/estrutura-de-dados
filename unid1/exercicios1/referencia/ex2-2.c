#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void calc_esfera (float r, float* area, float* volume);

int main(void){
  float* area = malloc(sizeof(float));
  float* volume = malloc(sizeof(float));

  float r = 2;
  calc_esfera(r, area, volume);
  printf("area: %.2f, volume: %.2f\n", *area, *volume);
  return 0;
}

void calc_esfera (float r, float* area, float* volume){
  *area = 4 * pow(r, 2);
  *volume = (4 * pow(r, 3)) / 3;
}
