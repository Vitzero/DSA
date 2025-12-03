#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct compras
{
    char nome[30];
    float preco;
};
typedef struct compras COMPRAS;


float le_e_soma(char * arquivo){

    FILE * f = fopen(arquivo, "r");
    if(f == NULL){
        printf("erro!");
        return -1;
    }

    int quantidade = 0, i = 0;

    char nomeIn[30];
    float precoIn;

    fscanf(f,"%d\n", &quantidade);

    COMPRAS * c = (COMPRAS *)malloc (quantidade * sizeof(COMPRAS));
    if(c == NULL){
        printf("ERRO no malloc.");
        return -1;
    }

    for(i = 0; i < quantidade; i++){
        fscanf(f,"%s %f", c[i].nome, &c[i].preco);
    }

    int seraoComprados = 0;

    fscanf(f,"%d", &seraoComprados);

    float somaTotal = 0;
    char NomeComparar[30];
    int quantidadeComparar;

    int j = 0;

    for(i = 0; i < seraoComprados; i++){
        fscanf(f, "%s %d", NomeComparar, &quantidadeComparar);
        
        for(j = 0; j < quantidade; j++){
            if(strcmp(NomeComparar, c[j].nome) == 0){
                somaTotal+= (float)c[j].preco * quantidadeComparar;
            }
        }

    }

    free(c);
    fclose(f);

    return somaTotal;

}

int main(){

    char arquivoEntrada[] = "entrada4.txt";

    float preco;

    float resultado = le_e_soma(arquivoEntrada);

    if(resultado > 0){
        printf("%.2f", resultado);
    }else{
        printf("erro!");
    }

}