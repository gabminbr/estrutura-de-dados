#include <stdio.h>

void inverte (int n, int* vet);

int main(void){
  int vetor[5] = {0, 1, 2, 3, 4};
  inverte(5, vetor);
  for(int i = 0; i < 5; i++){
    printf("%d\n", vetor[i]);
  }

  return 0;
}

void inverte(int n, int* vet){
  if(n == 1){
    return;
  }

  for(int i= 0; i < n / 2; i++){

    int aux = *(vet +(n - i - 1)); 
    *(vet + (n - i - 1)) = *(vet + i);
    *(vet + i) = aux;
  }
}
