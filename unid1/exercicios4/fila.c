#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila* cria_fila(){
    Fila* new = (Fila*) malloc(sizeof(Fila));
    if(new != NULL){
        new->comeco = 0;
        new->fim = 0;
        new->tam = 0;
    }
    return new;
}

int add(int x, Fila *fila){
    if(!esta_cheia(fila)){

        fila->vetor[fila->fim] = x;

        // verifica se o fim da fila está no máximo, se sim, ele volta ao index 0
        if(fila->fim == MAX - 1){
            fila->fim = 0;
        } else{
            fila->fim++;
        }

        fila->tam++;

        return 1;
    }
    printf("A fila esta cheia!\n");
    return 0;
}

int pop(int *x, Fila *fila){
    if(!esta_vazia(fila)){

        *x = fila->vetor[fila->comeco];

        // verifica se o comeco da fila nao esta no maximo permitido
        if(fila->comeco == MAX - 1){
            fila->comeco = 0;
        } else {
            fila->comeco++;
        }

        fila->tam--;

        return 1;
    }
    printf("A fila esta vazia!\n");
    return 0;
}

int esta_cheia(Fila *fila){
    return fila->tam == MAX;
}

int esta_vazia(Fila *fila){
    return fila->tam == 0;
}

void libera_fila(Fila *fila){
    free(fila);
}