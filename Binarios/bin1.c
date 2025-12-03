#include <stdio.h>
int main(){

    char arquivoentrada[] = "questao1.bin";

    FILE * f = fopen(arquivoentrada, "rb");
    if(f == NULL){
        printf("ERRO!");
        return 0;
    }

    float valor;
    float soma = 0;
    float media;
    float valorMaiorMenor;
    int contador;

    while( fread(&valor, sizeof(float), 1, f)){
        soma += valor;
        contador++;
    }
    
    media = soma / contador;

    rewind(f);
    
    while( fread(&valor, sizeof(float), 1, f)){
        if(valor >= media){
            valorMaiorMenor = valor;
            break;
        }
    }

    printf("%f", valorMaiorMenor);
    fclose(f);
}