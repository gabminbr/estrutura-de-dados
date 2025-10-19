#define MAX 5

typedef struct fila{
  int ini, fim, tam;

  int vet[MAX];
}Fila;

Fila* cria_fila();

void destroi_fila(Fila* fila);

int esta_vazia(Fila* fila);

int esta_cheia(Fila* fila);

int incrementa(Fila* fila, int elemento);

int decrementa(Fila* fila, int* elemento);
