/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#define N 5
#include <stdio.h>
void ApontaMaiores(int matriz[N][N], int* coluna, int* linha, int* maior){
    int i = 0, j = 0;
    
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(matriz[i][j] > *maior){
                *maior = matriz[i][j];
                *linha = i;
                *coluna = j;
            }
        }
    }
}

void ApontaMiniMax(int *linha, int *menor, int matriz[N][N], int *coluna2){
    int i = *linha;
    int j = 0;
    while(j < N){
        if(matriz[i][j] < *menor){
            *menor = matriz[i][j];
            *coluna2 = j;
        }
        j++;
    }
    
}

int main()
{
    int matriz[N][N] = {
        {17,  3, 94, 58, 26},
        {81, 44, 67, 13, 92},
        {10, 39, 55, 76,  2},
        {88, 21, 73, 30, 60},
        { 7, 99, 41, 12, 84}
    };
    
    int maior = -1;
    int coluna = 0;
    int linha = 0;
    
    int menor = 100;
    int coluna2 = -1;
    
    ApontaMaiores(matriz, &coluna, &linha, &maior);
    ApontaMiniMax(&linha, &menor, matriz, &coluna2);
    
    printf("Maior valor encontrado: %d\n", maior);
    printf("Posição: Linha %d, Coluna %d\n", linha + 1, coluna + 1);
    
    printf("Menor valor encontrado: %d\n", menor);
    printf("Posição minimax: Linha %d, Coluna %d\n", linha + 1, coluna2 + 1);
    
    

    
    return 0;
}