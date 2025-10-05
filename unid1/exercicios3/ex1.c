#include <stdio.h>

typedef struct ponto{
    int x;
    int y;
} Ponto;

void ler_ponto(Ponto* p){
    scanf("%d %d", &(*p).x, &(*p).y);
}

void mostrar_ponto(Ponto* p){
    printf("%d %d\n", (*p).x, (*p).y);
}

int main(void){
    Ponto p;
    ler_ponto(&p);
    mostrar_ponto(&p);
    return 0;
}
