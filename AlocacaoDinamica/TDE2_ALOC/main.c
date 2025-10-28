#include <stdio.h>
#include <stdlib.h>

typedef struct data { 
        int dia;
        int mes; 
        int ano; 
}DATA;
 
typedef struct transacao { 
        DATA data;
        float valor; 
        char descricao[100];
}TRANSACAO;

TRANSACAO * filtrarPorData(TRANSACAO *transacoes, int n, DATA inicio, DATA fim, int *nt){
    int i, j = 0, k;
    int countM = 0;
    
    
    int dataInicio = (inicio.ano * 10000) + (inicio.mes * 100) + (inicio.dia);
    int dataFim = (fim.ano * 10000) + (fim.mes * 100) + (fim.dia);
    
    for(i = 0; i < n; i++){
        int transacaoDia = (transacoes[i].data.ano * 10000) + (transacoes[i].data.mes * 100) + (transacoes[i].data.dia);
        
        if( transacaoDia >= dataInicio && transacaoDia <= dataFim ){
            countM++;
        }
        
    }
    
    TRANSACAO * transacaoFiltrada = (TRANSACAO *)malloc(countM * sizeof(TRANSACAO));
    if(transacaoFiltrada == NULL){
        return NULL;
    }

    for(i = 0; i < n; i++){
        int transacaoDia = (transacoes[i].data.ano * 10000) + (transacoes[i].data.mes * 100) + (transacoes[i].data.dia);
        
        if( transacaoDia >= dataInicio && transacaoDia <= dataFim ){
            transacaoFiltrada[j++] = transacoes[i]; 
        }
        
    }
    
    *nt = countM;
    
    return transacaoFiltrada;
}

void escreve(TRANSACAO * t, int n){
    int i = 0;
    
    for(i=0;i<n;i++){
        
        printf("Data: %02d/%02d/%04d\n",
               t[i].data.dia,
               t[i].data.mes,
               t[i].data.ano);
               
        printf("Descricao: %s\n", t[i].descricao);
        printf("Valor: R$ %.2f\n\n", t[i].valor);
        
    }
}


int main()
{
    int n = 5;
    TRANSACAO transacoes[] = {
        {{15, 10, 2025}, 250.75, "Pagamento de salario"},
        {{17, 10, 2025}, -120.50, "Conta de luz"},
        {{21, 10, 2025}, -73.25, "Supermercado"},
        {{24, 10, 2025}, -57.00, "Farmacia"},
        {{27, 10, 2025}, -32.00, "Gasolina"}
    };
    
    DATA DtInicio = { 16, 10, 2025 };
    DATA DtFim = { 25, 10, 2025 };
    
    int tamanho = 0;
    
    TRANSACAO * resultado = filtrarPorData(transacoes, n, DtInicio, DtFim, &tamanho);
    
    escreve(resultado, tamanho);
    
    free(resultado);
    
    return 0;
}