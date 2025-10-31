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
      printf("%d\n", p->info);
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
  if(l == NULL || l->head == NULL || l->tam <= 1){
    return;
  } 

  int n = l->tam;

  k = k % n;

  if (k == 0){
    return;
  }

  Nodo *ult = l->head;
  while(ult->prox != NULL){
    ult = ult->prox;
  }

  Nodo *novo_ult = l->head;
  int qtd_andar = n - k - 1;

  for(int i = 0; i < qtd_andar; i++){
    novo_ult = novo_ult->prox;
  }

  Nodo *nova_head = novo_ult->prox;

  novo_ult->prox = NULL;

  l->head = nova_head;
}

// exercicio 7
Lista* intercalate_lists(Lista* l1, Lista* l2){
  Lista *new_list = cria_lista();
  new_list->tam = l1->tam + l2->tam;

  Nodo *n1 = l1->head;
  Nodo *n2 = l2->head;
  
  int qual_colocar = 0;
  while(n1 != NULL && n2 != NULL){
    if(qual_colocar % 2 == 0){
      insere_lista(new_list, n1->info);
      n1 = n1->prox;
    } else {
      insere_lista(new_list, n2->info);
      n2 = n2->prox;
    }
  
    qual_colocar++;
  }
  
  Nodo *last = new_list->head;
  while(last->prox != NULL){
    last = last->prox;
  }

  if(n1 == NULL){
    last->prox = n2;
  }

  if(n2 == NULL){
    last->prox = n1;
  }
  
  return new_list;
}

// exercicio 8
int get_kth_element(Lista *l, int x){
  if(l->tam < 1 || x < 0 || x > l->tam){
    return 0;
  }

  int index = 0;
  int info;
  Nodo *navegar = l->head;

  while(navegar != NULL){
    if(index == x){
      info = navegar->info;
      break;
    }

    navegar = navegar->prox;
    index++;
  }

  return info;
}

// exercicio 9
void split_list(Lista* l, Lista **pares, Lista **impares){
  *pares = cria_lista();
  *impares = cria_lista();
  
  Nodo par;
  Nodo impar;
  par.prox = NULL;
  impar.prox = NULL;

  Nodo *cauda_par = &par;
  Nodo *cauda_impar = &impar;
  Nodo *atual = l->head;
  Nodo *proximo = NULL;

  while(atual != NULL){
    proximo = atual->prox;

    if(atual->info % 2 == 0){
      cauda_par->prox = atual;
      cauda_par = atual;
      (*pares)->tam++;
    } else {
      cauda_impar->prox = atual;
      cauda_impar = atual;
      (*impares)->tam++;
    }

    atual = proximo;
  }

  cauda_par->prox = NULL;
  cauda_impar->prox = NULL;

  (*pares)->head = par.prox;
  (*impares)->head = impar.prox;

  l->head = NULL;
  l->tam = 0;
}

// exercicio 10
void sort_list(Lista *l){
  Nodo *atual = l->head;
  Nodo *comparado = l->head->prox;
  for (int i = 0; i < l->tam - i - 1; i++){
    for(int j = 0; j < l->tam - j - 1; j++)
    atual = atual->prox;
  }
}
