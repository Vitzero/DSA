#include <stdio.h>
#include <stdlib.h>
#define N 5
int main(){

    int mat[N][N];
    int soma;

    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            printf("digite o valor para o vetor [%d] [%d]:", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
    

  for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            printf("% 5d", mat[i][j]);
            soma += mat[i][j];
        }
        printf("\n");
    }


    printf("\n Soma total de todos é igual a: %d \n", soma);
    soma = 0;

    printf("\n Irei Digitar apenas da diagonal principal agora! \n");

    for(int i = 0; i < N; i++){
        printf("%d", mat[i][i]);
        soma += mat[i][i];
    }

    printf("\n soma da diagonal principal é igual a: %d \n", soma);

    soma = 0;
    
    printf("\n Irei Digitar apenas da diagonal secundaria agora! \n");

    for(int i = 0, j = N-1; i < N; i++,j--){
        printf("%d", mat[i][j]);
        soma += mat[i][j];
    }

    printf("\n soma da diagonal secundaria é igual a: %d \n", soma);

    printf("\n Apenas a diagonal superior agora: \n");

    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            printf("%d", mat[i][j]);
        }   
    }
}