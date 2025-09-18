#include <stdio.h>

int negativos(int n, float* vet);

int main(void){
  float vetor[5] = {-1, -2, 0, 1};
  printf("%d\n", negativos(5, vetor));
  return 0;
}

int negativos(int n, float* vet){
  int qtd_negat = 0;
  for(int i = 0; i < n; i++){
    if(*(vet + i) < 0){
      qtd_negat++;
    }
  }
  return qtd_negat;
}
