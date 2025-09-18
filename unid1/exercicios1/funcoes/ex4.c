#include <stdio.h>

int soma_impares (int n);

int main(void){
  printf("A soma dos 2: %d\n", soma_impares(2));
  printf("A soma dos 3: %d\n", soma_impares(3));
  return 0;
}

int soma_impares (int n){
  int soma = 0;
  int i = 1;

  while(n > 0){
    soma += i;
    i += 2;
    n--;
  }

  return soma;
}
