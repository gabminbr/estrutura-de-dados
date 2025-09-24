#include <stdio.h>
#include <stdlib.h>

void mm(int* vetor, int* min, int* max){
  *min = vetor[0];
  *max = vetor[0];

  for(int i = 1; i < 5; i++){
    if(vetor[i] < *min){
      *min = vetor[i];
    }

    if(vetor[i] > *max){
      *max = vetor[i];
    }
  }
}

int main(void){
  int vetor[5] = {1, 2, 3, 4, 5};
  int* max = malloc(sizeof(int));
  int* min = malloc(sizeof(int));

  mm(vetor, min, max);

  printf("min = %d, max = %d\n", *min, *max);
  return 0;
}
