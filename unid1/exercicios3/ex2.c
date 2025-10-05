#include <stdio.h>
#include <math.h>

typedef struct{
    float x;
    float y;
} Ponto;

typedef struct{
    Ponto centro;
    float r;
} Circulo;

int is_ponto_dentro(Circulo* c, Ponto* p){
    float dist = dist_ponto_centro(c, p);
    if(dist > c->r){
        return 1;
    } 
    return 0;
}

float dist_ponto_centro(Circulo* c, Ponto* p){
    return sqrt(pow(c->centro.x - p->x, 2) + pow(c->centro.y - p->y, 2));
}