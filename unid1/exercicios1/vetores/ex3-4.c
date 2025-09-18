#include <stdio.h>
#include <math.h>

double avalia(double* poli, int grau, double x);

int main(void){
  double vetor[3] = {12, 2, 3};

  printf("%.2f\n", avalia(vetor, 2, 1));
  return 0;
}

double avalia(double* poli, int grau, double x){
  double resultado = 0;
  for(int i = 0; i <= grau; i++){
    resultado += *(poli + i) * pow(x, i);
  }
  return resultado;
}
