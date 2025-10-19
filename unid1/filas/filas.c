#include "filas.h"
#include <stdlib.h>

Fila* cria_fila(){
  Fila* fila = (Fila*) malloc(sizeof(Fila));
  return fila;
}

void destroi_fila(Fila* fila){
  free(fila);
}

int esta_vazia(Fila* fila){
  if(fila->tam == 0){
    return 1;
  }
  return 0;
}

int esta_cheia(Fila* fila){
  if(!(fila->tam == MAX)){
    return 1;
  }

  return 0;
}

int incrementa(Fila *fila, int elemento){
  if(!esta_cheia(fila)){
    fila->vet[fila->fim] = elemento;
    fila->fim++;
    if(fila->fim == MAX){
      fila->fim = 0;
    }
    fila->tam++;
    return 1;
  }
  return 0;
}

int decrementa(Fila* fila, int* elemento){
  if(!esta_vazia(fila)){
    *elemento = fila->vet[fila->ini];
    fila->ini++;
    if(fila->ini == MAX){
      fila->ini = 0;
    }
    fila->tam--;
    return 1;
  }
  return 0;
}
