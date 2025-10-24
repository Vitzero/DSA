#include <stdio.h>
#include <stdlib.h>
void escreve(int *v, int n){
    int i = 0;
    
    for(i = 0; i < n; i++){
        printf("%d", v[i]);
    }
    
}

int * interseccao(int *v1, int *v2, int n1, int n2, int *tamanho){
    int i,j,k,cont = 0;
    
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(v1[i] == v2[j]){
                cont++;
                break;
            }
        }
    }
    
    int *r = (int *) malloc(cont * sizeof(int));
    if (r == NULL){
        return NULL;
    }
    
    for(i = 0; i < n1; i++){
        for(j = 0; j < n2; j++){
            if(v1[i] == v2[j]){
                r[k++] = v1[i];
            }
        }
    }
    
    *tamanho = k;
    
    return r;
    
}

int main()
{
   int v1[3] = {4,1,2};
   int v2[2] = {1,5};
   
   int tamanhoReturn = 0;
   
   //escreve(v1,3);
   
   int *r = interseccao(v1,v2,3,2, &tamanhoReturn);
   
   if(r != NULL){
      escreve(r, tamanhoReturn);
      free(r);
   }
   
   
    return 0;
}
