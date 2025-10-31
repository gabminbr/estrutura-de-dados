#include "filas.h"
#include <stdlib.h>
#include <stdio.h>

Fila* cria_fila(){
    Fila *new = (Fila*) malloc(sizeof(Fila));
    new->tam = 0;
    new->prim = NULL;
    new->ult = NULL; 
    return new;
}

void libera_fila(Fila *f){
    if (f == NULL) return; 

    Nodo *atual = f->prim;
    while(atual != NULL) {
        Nodo *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    
    free(f);
}

void insere_fila(Fila *f, int x){
    if (f == NULL) return;

    Nodo *new = (Nodo*) malloc(sizeof(Nodo));
    new->info = x;
    new->prox = NULL;

    if (f->prim == NULL) {
        f->prim = new;
        f->ult = new;
    } else {
        f->ult->prox = new;
        f->ult = new;
    }
    
    f->tam++;
}

void remove_fila(Fila *f, int *x) {
    if (f == NULL || x == NULL) return;

    if (f->tam == 0) {
        printf("Erro: Fila vazia!\n");
        *x = -1; 
        return;
    }

    Nodo *temp = f->prim;
    *x = temp->info; 

    f->prim = f->prim->prox; 
    f->tam--;

    if (f->prim == NULL) {
        f->ult = NULL;
    }

    free(temp);
}

void imprime_fila(Fila *f){
    if(f->tam > 0){
        Nodo *atual = f->prim;

        while(atual != NULL){
            printf("info: %d\n", atual->info);
            atual = atual->prox;
        }
    }
}