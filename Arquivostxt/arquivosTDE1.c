#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

    char arquivo[] = "entradatde1.txt";
    char saida[] = "saidatde1.txt";

    FILE * f = fopen(arquivo, "r");
    FILE * s = fopen(saida, "w");
    if(f == NULL){
        printf("problema no arquivo de entrada;");
        return 0;
    }
    if(s == NULL){
        printf("problema no arquivo de saida;");
        return 0;
    }

    int elementos, maioresQTD;

    while (fscanf(f,"%d %d", &elementos, &maioresQTD) == 2)
    {
        int i, j, aux;

        int * numeros = (int *)malloc(elementos * sizeof(int));
        if(numeros == NULL){
            return 0;
        }

        for(i = 0; i < elementos; i++){
            fscanf(f,"%d", &numeros[i]);
        }

        for(i = 0; i < elementos - 1; i++){
            for(j = 0; j < elementos - 1; j++){
                if(numeros[j] > numeros[j+1])
                {
                    aux = numeros[j];
                    numeros[j] = numeros[j+1];
                    numeros[j+1] = aux; 
                }
            }
        }

        int soma = 0;

        for(i = elementos - maioresQTD; i < elementos; i++){
            soma+= numeros[i];
        }

        fprintf(s,"%d\n",soma);
        free(numeros);
    }
    
    fclose(f);
    fclose(s);

}