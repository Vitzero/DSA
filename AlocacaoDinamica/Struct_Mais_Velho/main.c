#include <stdio.h>
#define N 4

struct data{
    int d, m, a;
};
typedef struct data DATA;

struct cliente{
    char nome[50];
    DATA nasc;
};
typedef struct cliente CLIENTE;

CLIENTE velho(CLIENTE *v, int n){
    int i, p = 0;
    
    for(i=1; i < n; i++){
        if ( v[i].nasc.a*10000+ v[i].nasc.m*100 + v[i].nasc.d < v[p].nasc.a*10000+ v[p].nasc.m*100 + v[p].nasc.d){
            p = i;
        }    
    }
    
    return v[p];
}

int main()
{
    CLIENTE v[N] = {
        {"teste1", {21,10,2025}},
        {"teste2", {20,10,2025}},
        {"teste3", {18,10,2025}},
        {"teste4", {30,10,2025}},
        {"teste5", {15,10,2025}}
    };
    
    CLIENTE m = velho(v, N);
    
    printf("%s", m.nome);
    
        
    return 0;
}
