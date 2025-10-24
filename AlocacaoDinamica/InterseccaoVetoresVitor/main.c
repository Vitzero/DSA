#include <stdio.h>
#include <stdlib.h>
int * interseccao(int * v1, int * v2, int t1, int t2, int * tamanhoReturn){
    int i,j,k;
    int TamanhoMalloc;
    
    for(i = 0; i < t1; i++){
        for(j = 0; j < t2; j++){
            if(v1[i] == v2[j]){
                TamanhoMalloc++;
            }
        }
    }
    
    int * ReturnVetor = (int *)malloc(TamanhoMalloc * sizeof(int));
    if(ReturnVetor == NULL){
        return NULL;
    }
    
    
    for(i = 0; i < t1; i++){
        for(j = 0; j < t2; j++){
            if(v1[i] == v2[j]){
                ReturnVetor[k] = v1[i];
                k++;
            }
        }
    }
    
    * tamanhoReturn = k;
    
    return ReturnVetor;
    
}

void EscreveVetor(int * vetor, int tamanho){
    int i = 0;
    for (i = 0; i < tamanho; i++){
        printf("%d ", vetor[i]);
    }
}

int main()
{
    int v1[4] = {1,2,3,4};
    int v2[3] = {3,4,6};
    
    
    int tamanhoReturn;
    
    int * interseccaoVetor = interseccao(v1, v2, 4, 3, &tamanhoReturn); 
        
    EscreveVetor(interseccaoVetor, tamanhoReturn);
    
    free(interseccaoVetor);
    
    return 0;
}