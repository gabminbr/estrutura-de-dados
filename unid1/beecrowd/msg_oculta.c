#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM 60


int main(void){
  char palavra[TAM];
  char mensagem[TAM];
  int index_msg;
  int achou_letra;
  int vezes;
  scanf("%d", &vezes);

  for(int i = 0; i < vezes; i++){
    fgets(palavra, TAM, stdin);
    palavra[strcspn(palavra, "\n")] = '\0';
    
    index_msg = 0;

    for(int j = 0; j < TAM; j++){
      if(isalpha(palavra[j])){
        mensagem[index_msg] = palavra[j];
        index_msg++;
      }  
    }

    for(int j = 0; j <= index_msg; j++){
      printf("%c", mensagem[j]);
    }
    printf("\n");
  }
}

