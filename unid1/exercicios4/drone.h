#define MAX 3

typedef struct drone{
    int comeco;
    int fim;
    int tam;
    Entrega vetor[MAX];
} Drone;

typedef struct entrega{
    int id;
    int peso;
    char endereco;
} Entrega;

Drone* cria_drone();

int add(Entrega x, Drone* drone);

int pop(Entrega *x, Drone* drone);

int esta_cheia(Drone* drone);

int esta_vazia(Drone* drone);

void libera_fila(Drone* drone);

int verifica_peso(Entrega *entrega);

Entrega construtor_entrega(int id, int peso, char endereco);