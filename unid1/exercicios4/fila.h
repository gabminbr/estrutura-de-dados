#define MAX 10

typedef struct fila{
    int comeco;
    int fim;
    int tam;
    int vetor[MAX];
} Fila;

Fila* cria_fila();

int add(int x, Fila* fila);

int pop(int *x, Fila* fila);

int esta_cheia(Fila* fila);

int esta_vazia(Fila* fila);

void libera_fila(Fila* fila);