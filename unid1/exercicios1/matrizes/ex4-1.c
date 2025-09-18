#include <stdio.h>

int eh_simetrica1(int** mat, int linha, int coluna){
  if(linha != coluna){
    return 1;
  }
  for(int i = 0; i < linha; i++){
    for(int j = 0; j < coluna; j++){
      if(mat[i][j] != mat[j][i]){
        return 1;
      }
    }
  }
  return 0;
}

int eh_simetrica2(int* mat, int linha, int coluna){
  if(linha != coluna){
    return 1;
  }

  for(int i = 0; i < linha; i++){
    for(int j = 0; j < linha; j++){
      if(*(mat + i * n + j) != *(mat + j * n + i)) {
        return 1;
      }
    }
  }
  return 0
}
