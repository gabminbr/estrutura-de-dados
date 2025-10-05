#include "pontos.h"
#include <stdio.h>
#include <math.h>

void ler_ponto(Ponto* p){
    printf("x: ");
    scanf("%d", &p->x);

    printf("y: ");
    scanf("%d", &p->y);
}

void mostrar_ponto(Ponto* p){
    printf("x: %d, y: %d\n", p->x, p->y);
}

float dist_pontos(Circulo* circ, Ponto* p){
    return sqrt(pow(circ->centro.x - p->x, 2) + pow(circ->centro.y - p->y, 2));
}

int is_dentro_circ(Circulo* circ, Ponto* p){
    float dist = dist_pontos(circ, p);
    if(dist > r){
        return 1;
    }
    return 0;
}

float calc_circunf(Circulo* circ){
    return 2 * PI * circ->raio;
}

float calc_area_circ(Circulo* circ){
    return PI * pow(circ->raio, 2);
}