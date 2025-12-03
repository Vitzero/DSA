#include <stdio.h>
#include <stdlib.h>
unsigned char calcula_bit_de_paridade(unsigned char valor){
    int i, j;

    int contador = 0;
    for(j = 7; j >= 1; j--){
        int a = valor >> j;
        if((a & 1)){
            contador++;
        }

    }
    if(contador % 2 == 0){
        valor = valor & ~1;
    }else{
        valor = valor | 1;
    }

    return valor;

}

void printa_saida(unsigned char saida){
    int i = 8;
    printf("\n");
    for(i = 8; i >= 0; i--){
        int printa = (saida >> i) & 1;
        printf("%d", printa);
    }
    printf("\n");

}

int main(){

    unsigned char entrada = 0b11000100;
    unsigned char entrada2 = 0b11011000;

    unsigned char saida = calcula_bit_de_paridade(entrada);
    unsigned char saida2 = calcula_bit_de_paridade(entrada2);

    printf("\n%x\n", saida);
    printf("\n%x\n", saida2);

    printa_saida(saida);
    printa_saida(saida2);

}