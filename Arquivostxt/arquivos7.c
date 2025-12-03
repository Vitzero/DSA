#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    int i;

    char arquivo[]="entrada7.txt";
    char arquivoSaida[]="saida7.txt";

    FILE * f = fopen(arquivo, "r");
    FILE * s = fopen(arquivoSaida, "w");

    int codigo, num;
    float variavel = 0;
    
    while (fscanf(f,"%d %d", &codigo, &num) == 2)
    {
        
        float media = 0;

        for(i = 0; i < num; i++){
            fscanf(f, "%f", &variavel);
            media += variavel;
        }
        fprintf(s,"%4.d %4.d %4.2f\n",codigo,num, (float)media/num);
    }

    fclose(f);
    fclose(s);
}