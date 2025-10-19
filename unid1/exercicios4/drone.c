#include "drone.h"
#include <stdlib.h>
#include <stdio.h>

Drone* cria_drone(){
    Drone* new = (Drone*) malloc(sizeof(Drone));
    if(new != NULL){
        new->comeco = 0;
        new->fim = 0;
        new->tam = 0;
    }
    return new;
}

int add(Entrega x, Drone *drone){
    if(!esta_cheia(drone)){

        drone->vetor[drone->fim] = x;

        // verifica se o fim da fila está no máximo, se sim, ele volta ao index 0
        if(drone->fim == MAX - 1){
            drone->fim = 0;
        } else{
            drone->fim++;
        }

        drone->tam++;

        return 1;
    }
    printf("A fila esta cheia!\n");
    return 0;
}

int pop(Entrega *x, Drone *drone){
    if(!esta_vazia(drone)){

        *x = drone->vetor[drone->comeco];

        // verifica se o comeco da fila nao esta no maximo permitido
        if(drone->comeco == MAX - 1){
            drone->comeco = 0;
        } else {
            drone->comeco++;
        }

        drone->tam--;

        return 1;
    }
    printf("A fila esta vazia!\n");
    return 0;
}

int esta_cheia(Drone *drone){
    return drone->tam == MAX;
}

int esta_vazia(Drone *drone){
    return drone->tam == 0;
}

void libera_fila(Drone *drone){
    free(drone);
}

int verifica_peso(Entrega *entrega){
    return entrega->peso <= 10;
}

Entrega construtor_entrega(int id, int peso, char endereco){
    Entrega new;
    new.id = id;
    new.peso = peso;
    new.endereco = endereco;
}