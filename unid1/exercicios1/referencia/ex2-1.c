#include <stdio.h>
#include <math.h>

int raizes(float a, float b, float c, float* x1, float* x2);

int main(void){
  float a, b, c;
  float *x1, *x2;

  a = 1;
  b = 2; 
  c = 0;

  if(raizes(a, b, c, x1, x2) == 1){
    printf("raiz dupla: %.2f\n", *x1);
  } else if(raizes(a, b, c, x1, x2) == 2){
    printf("Raizes: %.2f, %.2f\n", *x1, *x2);
  }

  return 0;
}

int raizes(float a, float b, float c, float* x1, float* x2){
  float delta = pow(b, 2) - 4 * a * c;

  if(delta < 0){
    return 0;
  } else if(delta == 0){
    *x1 = *x2 = -b / 2 * a;
    return 1;
  } else {
    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);
    return 2;
  }
}
