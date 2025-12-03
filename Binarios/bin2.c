#include <stdio.h>
int main(){
    char arquivoentrada[] = "questao2.bin";
    int contadores[5];

    FILE * f = fopen(arquivoentrada, "rb");
    if(f == NULL){
        printf("ERRO!");
        return 0;
    }

    int valor;

    while (fread(&valor, sizeof(int), 1, f))
    {
        if(valor <= 5 && valor >= 1){
            contadores[valor]++;
        }
        
    }
    int i,j;

    char arquivoSaida[] = "arquivoSaida.txt";

    FILE * new = fopen(arquivoSaida, "w");

    for(i = 1; i <= 5; i++){
        fprintf(new, "%d ", i);
        for ( j = 0; j < contadores[i]; j++)
        {
            fputc('*', new);
        }
        fprintf(new, "\n");
    }

    fclose(f);
}