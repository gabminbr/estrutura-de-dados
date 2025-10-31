#include "pilhas.h"
#include <stdlib.h>
#include <stdio.h>

Pilha* cria_pilha(){
    Pilha *new = (Pilha*) malloc(sizeof(Pilha));
    new->tam = 0;
    new->topo = NULL;
    return new;
}

void libera_pilha(Pilha *p){
    if(p == NULL) {
        return;
    }

    if(p->tam > 0){
        Nodo *atual = p->topo;
        Nodo *temp = NULL;
        while(atual != NULL) {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }

    free(p);
}

void pop(Pilha *p, int *x) {
    if(p == NULL){
        return;
    }

    Nodo *tmp = NULL;
    if(p->tam > 0){
        tmp = p->topo;
        p->topo = p->topo->prox;
        *x = tmp->info;
        free(tmp);
        p->tam--;
    }

}

void push(Pilha *p, int x){
    Nodo *new = (Nodo*) malloc(sizeof(Nodo));
    new->info = x;
    new->prox = p->topo;
    p->topo = new;
    p->tam++;
}

void imprime_pilha(Pilha *p){
    if(p->tam > 0){
        Nodo *t = p->topo;

        while(t != NULL){
            printf("info: %d\n", t->info);
            t = t->prox;
        }
    }
}