#include <stdlib.h>
#include <stdio.h>
int *uniao(int *v1, int *v2, int t1, int t2, int *qtd){
    int i=0,j=0,k=0;
    int TamanhoMalloc = 0;
   
    for(i = 0; i < t1; i++){
        for(j = 0; j < t2; j++){
            if(v1[i] == v2[j]){
                TamanhoMalloc++;
            }
        }
    }
    
    int tamanhoUniao = ((t1 + t2) - TamanhoMalloc);
    
    int *ptrReturn = (int *)malloc(tamanhoUniao * sizeof(int));
    if(ptrReturn == NULL){
        return NULL;
    }
    
    for(i = 0; i < t1; i++){
        ptrReturn[k] = v1[i];
        k++;
    }
    
    int existe = 0;
    for(i = 0; i < t2; i++){
        existe = 0;
        for(j = 0; j < t1; j++){
            if(v2[j] == v1[i]){
                existe = 1;
                break;
            }
        }
        if(!existe){
            ptrReturn[k++] = v2[i];
        }
       
    }
    
    * qtd = tamanhoUniao;
    
    return ptrReturn;
    
}

void escreve( int * v, int qtd){
    int i=0;
    for(i= 0; i < qtd  ; i++){
        printf("%d", v[i]);
    }
}

int main()
{
    int t1 = 5, t2 = 5, qtd;
    int v1[5]={1,3,5,6,7};
    int v2[5]={1,3,4,6,8};
    
    int * vetUniao = uniao(v1, v2, t1, t2, &qtd);
    
    escreve(vetUniao,qtd);
    free(vetUniao);
    return 0;
}
