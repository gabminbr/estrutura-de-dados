#include <stdio.h>

int dentro_ret (int x0, int y0, int x1, int y1, int x, int y);
int main(void){
  int x0 = 2;
  int y0 = 4;
  int x1 = 5;
  int y1 = 8;

  printf("%d\n", dentro_ret(x0, y0, x1, y1, 1, 8));
  return 0;
}

int dentro_ret(int x0, int y0, int x1, int y1, int x, int y){
  if((x >= x0 && x <= x1) && (y >= y0 && y <= y1)){
    return 1;
  } return 0;
}
