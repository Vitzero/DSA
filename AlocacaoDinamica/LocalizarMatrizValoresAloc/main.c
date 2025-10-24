
#include <stdio.h>
#include <stdlib.h>
#define N 5
struct valor{
    int v, l, c;
};
typedef struct valor VALOR;

VALOR * cria_vetor(int mat[5][5], int * n){
    int i, j, cont = 0;
    for(i = 0; i < N; i++){
        for(j=0;j<N;j++){
            if(mat[i][j] != 0){
                cont++;
            }
        }
    }
    
    VALOR * v = (VALOR *)malloc(cont * sizeof(VALOR));
    int k = 0;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(mat[i][j] != 0){
                v[k].v = mat[i][j];
                v[k].l = i;
                v[k++].c = j;
            }
        }
    }
    *n = cont;
    return v;
}
void escreve(VALOR *v, int n){
    int i = 0;
    for(i = 0; i < n; i++){
        printf("valor: %d linha: %d coluna: %d\n", v[i].v, v[i].l + 1, v[i].c + 1);
    }
}
int main()
{
    int n;
    
    int mat[5][5] = {   {0,2,0,0,0},
                        {0,0,0,0,0},
                        {0,0,0,4,0},
                        {1,0,0,0,0},
                        {0,0,0,0,8}
    };

    VALOR *v = cria_vetor(mat, &n);

    if(v != NULL){
        escreve(v,n);
    }
    
    free(v);

    return 0;
}