#define PI 3.14159

typedef struct{
    float x;
    float y;
} Ponto;

typedef struct{
    Ponto centro;
    float raio;
} Circulo;

void ler_ponto(Ponto* p);

void mostrar_ponto(Ponto* p);

float dist_pontos(Circulo* circ, Ponto* p);

int is_dentro_circ(Circulo* circ, Ponto* p);

float calc_circunf(Circulo* circ);

float calc_area_circ(Circulo* circ);