#define M 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct motorista{
    char nome[50];
    int codigo;
    int multas;
};
typedef struct motorista MOTORISTA;

MOTORISTA *piores_motoristas(MOTORISTA m[], int num_motoristas, int N){
    int i=0, j=0, k=0;
    MOTORISTA aux;
    
    for(i = 0; i < num_motoristas - 1; i++){
        for(j = 0; j < num_motoristas - i - 1; j++){
            if(m[j].multas < m[j+1].multas){
                aux = m[j]; 
                m[j] = m[j+1];
                m[j+1] = aux;
            }
            else if(m[j].multas == m[j+1].multas){
                if(strcmp(m[j].nome, m[j+1].nome) > 0){ 
                    aux = m[j];
                    m[j] = m[j+1];
                    m[j+1] = aux;
                }
            }
        }
    }
    
    MOTORISTA * result = (MOTORISTA *)malloc(N * sizeof(MOTORISTA));
    if(result == NULL){
        return NULL;
    }
    
    for(i=0; i < N; i++){
        result[k++] = m[i];
    }
    
    
    return result;
}

void escreve(MOTORISTA * m, int qtd){
    int i = 0;
    printf("PIORES MOTORIAS LISTA:\n");
    for(i = 0; i < qtd; i++){
        printf("Nome: %s Codigo: %d Multas: %d\n", m[i].nome, m[i].codigo, m[i].multas);
    }
}
int main()
{
       MOTORISTA m[M] = {
        {"Marcos Gomes Silva", 2331, 8},
        {"Rodrigo Correia Ribeiro", 145, 4},
        {"Alice Oliveira Santos", 1465, 6},
        {"Nicolas Silva Cavalcanti", 2934, 7},
        {"Daniel Silva Melo", 2127, 9},
        {"Diogo Sousa Almeida", 1814, 11}
    };
    
    int N = 4;
    
    
    MOTORISTA * piores = piores_motoristas(m, M, N);
    escreve(piores, N);
    
    free(piores);
    
    return 0;
}