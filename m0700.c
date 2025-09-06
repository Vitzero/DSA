#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main(){
    srand((int)time(0));
    int mat[N][N];
    int aux;
    int i,j;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            mat[i][j] = rand( ) % 10;
        }
    }
    printf("\n");


    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            printf("% 5d", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n fazendo inversao de linhas 1 e 3: \n");
    for(i = 0; i < N; i++){
        aux = mat[0][i];
        mat[0][i] = mat[2][i];
        mat[2][i] = aux;
    }


printf("\n");
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N; j++){
            printf("% 5d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}