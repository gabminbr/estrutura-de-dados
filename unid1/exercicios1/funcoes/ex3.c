#include <stdio.h>

int fibonacci (int n);

int main(void){
  printf("Fib 1: %d\n", fibonacci(1));
  printf("Fib 2: %d\n", fibonacci(2));
  printf("Fib 3: %d\n", fibonacci(3));
  printf("Fib 4: %d\n", fibonacci(4));
  printf("FIb 5: %d\n", fibonacci(5));
  return 0;
}

int fibonacci (int n){
  if(n <= 2){
    return 1;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}
