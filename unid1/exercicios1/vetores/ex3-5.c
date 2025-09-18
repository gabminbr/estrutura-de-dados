#include <stdio.h>

void deriva(double* poli, int grau, double* out);

int main(void){
  double poli[3] = {12, 2, 3};
  double out[3];
  deriva(poli, 2, out);
 
  printf("%f %f %f\n", out[2], out[1], out[0]);
  return 0;
}

void deriva(double* poli, int grau, double* out){
  for(int i = grau; i >= 0; i--){
    *(out + i) = *(poli + i) * i;
  }
}
