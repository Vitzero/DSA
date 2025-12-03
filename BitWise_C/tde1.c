#include <stdio.h>

unsigned char calcula_bit_de_paridade(unsigned char valor){
    int i = 0;
    int contador = 0;
    int bit;
    for(i = 0; i < 8; i++){
        bit = (valor >> i) & 1;
        if(bit){
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

void printaSaidaBinaria(unsigned char valor){

    int i,bit;
    
    printf("\n");
    for(i = 7; i >= 0; i--){
        bit = (valor >> i) & 1;
        printf("%d",bit);
    }
    printf("\n");

}

int main(){

    unsigned char valor = 0b11000100; 
    unsigned char valor1 = 0b11011000; 
    unsigned char valor2 = 0b10000010; 
    unsigned char valor3 = 0b10000110; 

    unsigned char result = calcula_bit_de_paridade(valor);
    printaSaidaBinaria(result);

}