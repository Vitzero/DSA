#include <stdio.h>
#include <stdlib.h>
struct naonulo{
       int valor; 
       int linha; 
       int coluna;
};
typedef struct naonulo NAONULO;

NAONULO * valores_nao_nulos(int m[5][5],  int *num_nao_nulos){
    int i,j,k = 0;
    int naoNulosCount = 0;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(m[i][j] != 0){
                naoNulosCount++;
            }
        }
    }
    
    NAONULO * vetorStruct = (NAONULO *)malloc(naoNulosCount * sizeof(NAONULO));
    if(vetorStruct == NULL){
        return NULL;
    }
    
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(m[i][j] != 0){
                vetorStruct[k].valor = m[i][j];
                vetorStruct[k].linha = i;
                vetorStruct[k++].coluna = j;
            }
        }
    }
    
    * num_nao_nulos = naoNulosCount;
    
    return vetorStruct;
    
}
void escreve(NAONULO * m, int qtd){
    int i=0;
    for(i = 0; i < qtd; i ++){
        printf("valor: %d linha: %d coluna: %d\n", m[i].valor, m[i].linha, m[i].coluna);
    }
}

int main()
{
    int m[5][5] = {
        {1, 2, 3, 4, 5},
        {0, 5, 1, 0, 0},
        {7, 0, 0, 2, 0},
        {0, 1, 0, 3, 4},
        {5, 0, 2, 0, 1}
    };
   
    int qtd = 0;
    
    NAONULO * ptr = valores_nao_nulos(m, &qtd);
    
    escreve(ptr,qtd);
    
    free(ptr);
    
    return 0;
}
