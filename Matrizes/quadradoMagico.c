#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void geraMatriz(int mat[N][N]){
    int i,j;
    
    for (i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

void printMatriz(int mat[N][N]){
    int i,j;

    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%5d", mat[i][j]);
        }
        printf("\n");
    }
    
}

int somaColunas(int mat[N][N]){
    int i,j, soma,guardaSoma,boolean = 1;

    for(i = 0; i < N; i++){
        soma=0;
        for(j = 0; j < N; j++){
            soma += mat[j][i];
        }
        if(i == 0){
            guardaSoma = soma;
        }
        
        if(soma != guardaSoma){
            boolean = 0;
            break;       
        }
    }

    return boolean;
}

int somaLinhas(int mat[N][N]){
    int i,j, soma,guardaSoma,boolean = 1;

    for(i = 0; i < N; i++){
        soma=0;
        for(j = 0; j < N; j++){
            soma += mat[i][j];
        }
        if(i == 0){
            guardaSoma = soma;
        }
        
        if(soma != guardaSoma){
            boolean = 0;
            printf("Não é quadrado mágico!");
            break;     
        }
    }

    return guardaSoma;
}

int somaDiagonais(int mat[5][5], int somaTrue){
    int soma = 0;

    for(int i = 0, j = N-1; i < N; i++,j--){
        printf("%d ,", mat[i][j]);
        soma += mat[i][j];
    }

}

int main(){
    
    srand(time(NULL)); 
    int mat[N][N];

    geraMatriz(mat);
    printMatriz(mat);

    somaLinhas(mat);
    SomaColunas(mat);
    SomaDiagonalPrincipal(mat);
    SomaDiagonalSecundaria(mat);
    

    return 0;
}