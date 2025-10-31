#include "listas.h"
#include <stdio.h>
#include <stdlib.h>

Lista* cria_lista(){
  Lista *new = (Lista*) malloc(sizeof(Lista));
  new->tam = 0;
  new->head = NULL;
  return new;
}

Lista* insere_lista(Lista* l, int x){
  Nodo *new = (Nodo*) malloc(sizeof(Nodo));
  new->info = x;
  new->prox = l->head;
  l->tam++;
  l->head = new;
  return l;
}

Lista* remove_lista(Lista *l, int x){
  if(l->tam != 0){
    Nodo *ant = NULL;
    Nodo *p = l->head;

    while(p != NULL && p->info != x){
      ant = p;
      p = p->prox;
    }
    
    if(p == NULL){
      return l;
    }

    if(ant == NULL){
      l->head = l->head->prox;
    } else {
      ant->prox = p->prox;
    }

    free(p);
    l->tam--;
  }
  return l;
}

void libera_lista(Lista *l){
  if(l->tam > 0){
    Nodo *t = l->head;
    while(t != NULL){
      l->head = l->head->prox;
      free(t);
      t = l->head;
    }
  } 
}

void printar_lista(Lista *l){
  if(l->tam > 0){
    Nodo *p = l->head;
    while(p != NULL){
      printf("%d\n", p);
      p = p->prox;
    }
  }
}

// exercicio 1
int list_sum(Lista *l){
  int sum = 0;
  if(l->tam > 0){
    Nodo *p = l->head;
    while(p != NULL){
      sum += p->info;
      p = p->prox;
    }
  }

  return sum;
}

// exercicio 2
void reverse_list(Lista *l){
  if(l->tam > 0){
    Nodo *ant = NULL;
    Nodo *atual = l->head;
    Nodo *prox = NULL;
    
    while(atual != NULL){
      prox = atual->prox;
      atual->prox = ant;
      ant = atual;
      atual = prox;
    }
    
    l->head = ant;
  }
}

// exercicio 3
Lista* merge_sorted_lists(Lista *l1, Lista *l2){
  Lista *new = cria_lista();
  Nodo temp;
  temp.prox = NULL;
  
  Nodo *cauda = &temp;
  Nodo *p1 = l1->head;
  Nodo *p2 = l2->head;

  while(p1 != NULL || p2 != NULL){
    if(p1->info <= p2->info){
      cauda->prox = p1;
      p1 = p1->prox;
    } else {
      cauda->prox = p1;
      p1 = p1->prox;
    }

    cauda = cauda->prox;
  }

  if(p1 != NULL){
    cauda->prox = p1;
  }

  if(p2 != NULL){
    cauda->prox = p2;
  }

  new->head = temp.prox;
  new->tam = l1->tam + l2->tam;

  l1->head = NULL;
  l1->tam = 0;
  l2->head = NULL;
  l2->tam = 0;

  return new;
}

// exercicio 4
void remove_duplicates(Lista *l){
  if(l->tam > 1){
    Nodo *atual = l->head;

    while(atual != NULL){
      Nodo *aux = atual;

      while(aux->prox != NULL){
        if (aux->prox->info == atual->info){
          Nodo *t = aux->prox;
          aux->prox = t->prox;

          free(t);
          l->tam--;
        } else {
          aux = aux->prox;
        }
      }

      atual = atual->prox;
    }
  }
}

// exercicio 5
int is_palindrome(Lista *l){
  if(l == NULL || l->head == NULL || l->head->prox == NULL){
    return 1;
  } 
  
  Nodo *aux1 = l->head;
  Nodo *aux2 = l->head;

  while(aux2->prox != NULL && aux2->prox->prox != NULL){
    aux1 = aux1->prox;
    aux2 = aux2->prox->prox;
  }

  Nodo *head2 = aux1->prox;
  aux1->prox = NULL;

  Nodo *ant = NULL;
  Nodo *atual = head2;
  Nodo *prox_nodo = NULL;

  while(atual != NULL){
    prox_nodo = atual->prox;
    atual->prox = ant;
    ant = atual;
    atual = prox_nodo;
  }

  head2 = ant;
  Nodo *restaura = head2;

  Nodo *p1 = l->head;
  Nodo *p2 = head2;

  int resultado = 1;

  while (p2 != NULL) {
    if(p1->info != p2->info) {
      resultado = 0;
      break;
    }

    p1 = p1->prox;
    p2 = p2->prox;
  }

  ant = NULL;
  atual = restaura;
  prox_nodo = NULL;

  while(atual != NULL) {
    prox_nodo = atual->prox;
    atual->prox = ant;
    ant = atual;
    atual = prox_nodo;
  }

  aux1->prox = ant;

  return resultado;
}

// exercicio 6
void rotate_list(Lista *l, int k){

}
