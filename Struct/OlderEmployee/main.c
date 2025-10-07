#define N 4
#include <stdio.h>
#include <stdio_ext.h>
struct data{
    int d,m,a;    
};
typedef struct data DATA;

struct pessoa{
    char nome[50];
    DATA nasc;
};
typedef struct pessoa PESSOA;

void le_pessoa(PESSOA v[]){
    int i;
    
    for(i = 0; i < N; i++){
        printf("Nome:");
        gets(v[i].nome);
        printf("Data de nascimento: xx/xx/xxxx:\n");
        scanf("%d/%d/%d", &v[i].nasc.d, &v[i].nasc.m, &v[i].nasc.a);
        __fpurge(stdin);
    }
}
void escreve_pessoa(PESSOA v[]){
    int i;
    for(i = 0; i < N; i++){
        printf("nome: %s data: %d/%d/%d \n",v[i].nome, v[i].nasc.d, v[i].nasc.m, v[i].nasc.a);
    }
}

PESSOA mais_velha(PESSOA v[N]){
    PESSOA m = v[0];
    
    int i;
    
    for(i = 1; i < N; i++){
        if(v[i].nasc.a < m.nasc.a){
            m = v[i];
        }
        else if (v[i].nasc.a == m.nasc.a && v[i].nasc.m < m.nasc.m){
            m = v[i];
        }
        else if (v[i].nasc.a == m.nasc.a && v[i].nasc.m == m.nasc.m && v[i].nasc.d < m.nasc.d ){
            m = v[i];
        }
    }
    
    return m;
}

int main()
{
    PESSOA v[N];    
    
    le_pessoa(v);
    escreve_pessoa(v);
    PESSOA maisVelha = mais_velha(v);
    
    printf("Pessoa mais velha: %s nasceu em %d/%d/%d", maisVelha.nome, maisVelha.nasc.d, maisVelha.nasc.m, maisVelha.nasc.a);
    
    
    return 0;
}
