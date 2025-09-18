#include <stdio.h>

int pares(int n, int* vet);

int main(void){
  int vetor[4] = {1, 2, 3, 9};
  printf("%d\n", pares(4, vetor));
  return 0;
}

int pares(int n, int* vet){
  int qtd_pares = 0;

  for(int i = 0; i < n; i++){
    if(*(vet + i) % 2 == 0){
      qtd_pares++;
    }
  }

  return qtd_pares;
}
