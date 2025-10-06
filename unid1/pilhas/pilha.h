#define MAX 100

typedef struct pilha{
  int topo;
  char palavra[MAX];
} Pilha;

Pilha* cria_pilha();

int is_cheia(Pilha* p);

int is_vazia(Pilha* p);

int push(Pilha* p, char letra);

int pop(Pilha*p, char* retirado);

char get_topo(Pilha* p);

int is_palindromo(Pilha* p);
