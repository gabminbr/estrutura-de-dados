#include "pilha.h"

Pilha *cria_pilha(){
  Pilha* p;
  p->topo = 0;
  return p;
}

int is_cheia(Pilha* p){
  if(p->topo == MAX){
    return 0;
  }

  return 1;
}

int is_vazia(Pilha* p){
  if(p->topo == 0){
    return 0;
  }

  return 1;
}

int push(Pilha* p, char letra){
  if(is_cheia(p)){
    return 1;
  }
  p->palavra[p->topo] = letra;
  p->topo++;
  return 0;
}

int pop(Pilha* p, char* retirado){
  if(is_vazia(p)){
    return 1;
  }

  *retirado = p->palavra[p->topo];
  p->topo--;
  return 0;
}

char get_topo(Pilha* p){
  return p->palavra[p->topo-1];
}

int is_palindromo(Pilha* p){
  for(int i = 0; i < p->topo / 2; i++){
    if(p->palavra[i] != p->palavra[p->topo - 1 - i]){
      return 1;
    }
  }
  return 0;
}
