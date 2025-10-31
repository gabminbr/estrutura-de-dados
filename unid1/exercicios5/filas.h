typedef struct nodo {
    int info;
    struct nodo *prox;
}Nodo;

typedef struct fila {
    int tam;
    Nodo *prim;
    Nodo *ult;
}Fila;

Fila* cria_fila();

void libera_fila(Fila*);

void insere_fila(Fila*, int);

void remove_fila(Fila*, int*);

void imprime_fila(Fila*);