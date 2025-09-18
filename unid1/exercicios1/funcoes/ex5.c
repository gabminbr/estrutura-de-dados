#include <stdio.h>
#include <math.h>

double pi (int n);

int main(void){
  printf("%.2f\n", pi(1000));
  return 0;
}

double pi (int n){
  double p = 4;
  double soma = 0;
  for(int i = 0; i < n; i++){
    soma += pow(-1, i) / ((2 * i) + 1); 
  }

  p *= soma;
  return p;
}
