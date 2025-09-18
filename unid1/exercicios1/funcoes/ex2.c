#include <stdio.h>

int primo(int n);

int main(void){
  printf("%d\n", primo(4));
  return 0;
}

int primo(int n){
  if (n % 2 == 0){
    return 0;
  } return 1;
}
