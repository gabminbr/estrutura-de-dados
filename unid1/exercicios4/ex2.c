#include "drone.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    Entrega e1 = construtor_entrega(101, 7, 'A');
    Entrega e2 = construtor_entrega(102, 5, 'B');
    Entrega e3 = construtor_entrega(103, 4, 'C');

    Drone *drone = cria_drone();

    add(e1, drone);
    add(e2, drone);
    add(e3, drone);

    Entrega *temp = (Entrega*) malloc(sizeof(Entrega));
    
}