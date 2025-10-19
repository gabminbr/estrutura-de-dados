#include <stdio.h>
#include <stdlib.h>

#define MAX 1010

typedef struct palavra{
  char palavra[10];
  int tam;
}Palavra;

int verifica_um(Palavra* palavra);
int verifica_dois(Palavra* palavra);
int verifica_tres(Palavra* palavra);


int main(void){
  int a;
  scanf("%d", &a);
  
  char garb;
  scanf("%c", &garb);
  
  Palavra *palavra = (Palavra*) malloc(sizeof(Palavra));
  for(int i = 0; i < a; i++){
    palavra->tam = 0;
    for(int j = 0; j < MAX; j++){
      scanf("%c", &palavra->palavra[j]);
      if(palavra->palavra[j] == '\n'){
        palavra->palavra[j] = '\0';
        break;
      }
      palavra->tam++;
    }
    
    if(verifica_um(palavra) == 1){
      printf("1\n");
    } else if(verifica_dois(palavra) == 1){
      printf("2\n");
    } else if(verifica_tres(palavra) == 1){
      printf("3\n");
    }
  } 
}

int verifica_um(Palavra *palavra){
  if(palavra->tam == 3){
    if(palavra->palavra[0] == 'o' || palavra->palavra[1] == 'n'){
      return 1;
    }
  }

  return 0;
}

int verifica_dois(Palavra *palavra){
  if(palavra->tam == 3){
    if(palavra->palavra[0] == 't' || palavra->palavra[1] == 'w'){
      return 1;
    }
  }

  return 0;
}

int verifica_tres(Palavra *palavra){
  if(palavra->tam == 5) return 1;

  return 0;
}
