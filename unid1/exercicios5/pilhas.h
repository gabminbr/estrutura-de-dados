typedef struct nodo {
    int info;
    struct nodo *prox;
}Nodo;

typedef struct pilha {
    int tam;
    Nodo *topo;
} Pilha;

Pilha* cria_pilha();

void libera_pilha(Pilha*);

void pop(Pilha*, int*);

void push(Pilha*, int);

void imprime_pilha(Pilha*);
