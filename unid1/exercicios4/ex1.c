#include "fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    Fila *norte = cria_fila();
    Fila *sul = cria_fila();

    int direcao;

    add(rand(), norte);
    add(rand(), sul);
    add(rand(), sul);
    add(rand(), norte);
    add(rand(), norte);

    while(norte->tam != 0 || sul->tam != 0){
        direcao = (rand() % 2) + 1;
        printf("Ponte aberta na direcao: ");
        int *veiculo_saindo = (int*) malloc(sizeof(int));
        if(direcao == 1){
            printf("NORTE\n");
            pop(veiculo_saindo, norte);
            printf("Veiculo %d atravessou a ponte\n", *veiculo_saindo);
        } else {
            printf("SUL\n");
            pop(veiculo_saindo, sul);
            printf("Veiculo %d atravessou a ponte\n", *veiculo_saindo);
        }
    }

    libera_fila(norte);
    libera_fila(sul);
}