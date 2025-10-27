#include <stdio.h>
#include <stdlib.h>
#define N 6
struct data {
    int dia;
    int mes;
    int ano;
};
typedef struct data DATA;

struct cliente {
    int codigo;
    char nome[50];
    DATA nasc;
};
typedef struct cliente CLIENTE;


int EhMaiorDeIdade(CLIENTE p, DATA CurrentDate){
    DATA DataMaiorDeIdade = CurrentDate;
    DataMaiorDeIdade.ano -= 18;
    
    if( p.nasc.ano < DataMaiorDeIdade.ano ){
        return 1;
    }
    if( p.nasc.ano == DataMaiorDeIdade.ano && p.nasc.mes < DataMaiorDeIdade.mes){
        return 1;
    }
    if(p.nasc.ano == DataMaiorDeIdade.ano && p.nasc.mes == DataMaiorDeIdade.mes && p.nasc.dia <= DataMaiorDeIdade.dia){
        return 1;
    }
    
    return 0;
    
}

CLIENTE * funcaoTeste(CLIENTE * p, int * quantidade, DATA CurrentDate){
    int i = 0, j = 0, k = 0, countIdade = 0;
    int tamanho = *quantidade;
    
    
    for(i = 0; i < tamanho; i++){
        if(EhMaiorDeIdade(p[i] , CurrentDate)){
            countIdade++;
        }
    }
    
    CLIENTE * ReturnMaiores = (CLIENTE *)malloc(countIdade * sizeof(CLIENTE));
    if (ReturnMaiores == NULL) {
        printf("Erro: memoria insuficiente.\n");
        *quantidade = 0;
        return NULL;
    }
 
    for(i = 0; i < tamanho; i++){
        if(EhMaiorDeIdade(p[i], CurrentDate)){
            ReturnMaiores[k++] = p[i];
        }
    }   
    
    * quantidade = countIdade;
    
    return ReturnMaiores;
}

void EscreveCliente(CLIENTE * p, int quantidade){
    int i = 0;
    printf("Pessoas maiores de idade:\n");
    for(i = 0; i < quantidade; i++){
        printf("codigo: %d, nome: %s, nasc: %d/%d/%d\n", p[i].codigo, p[i].nome, p[i].nasc.dia, p[i].nasc.mes, p[i].nasc.ano);
    }
}

int main()
{
    DATA CurrentDate = {27,10,2025};
    
    CLIENTE clientes[N] = {
        {123, "Teste1", {30, 5, 2005}},
        {456, "teste222", {12, 8, 1999}},
        {789, "João abreu", {25, 12, 2015}},
        {789, "Souza dev", {25, 12, 2016}},
        {789, "Frois", {25, 12, 2012}},
        {789, "Vituphp", {25, 12, 2010}}
    };
    
    int quantidade = N;
 
    CLIENTE * resultado = funcaoTeste(clientes, &quantidade, CurrentDate);

    EscreveCliente(resultado, quantidade);
    
    free(resultado);
    

    return 0;
}