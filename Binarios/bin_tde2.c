#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
    char nome[51];
    float preco;
};
typedef struct produto PRODUTO;

int main(){

    char entrada[] = "entradatde2.txt";
    char binarios[] = "produtos.bin";
    char saida[] = "saida_tde2.txt";
    FILE * f = fopen(entrada, "r");
    FILE * b = fopen(binarios, "rb");
    FILE * s = fopen(saida, "w");


    int contador =0;
    PRODUTO x;

    while (fread(&x, sizeof(PRODUTO), 1, b))
    {
        contador++;
    }

    rewind(b); 

    PRODUTO * ps = (PRODUTO *) malloc(contador * sizeof(PRODUTO));

    int i = 0;

    while (fread(&ps[i],sizeof(PRODUTO),1,b) == 1){
        i++;
    }

    char nome[50];
    int quantidade;
    float total = 0;

    int produtosCount;

    int j,k,l;

    while (fscanf(f,"%d", &produtosCount) == 1)
    {
        for(j = 0; j < produtosCount; j++){

            fscanf(f, "%s %d", nome, &quantidade);
            
            for(i = 0; i < contador; i ++){
                if(strcmp(ps[i].nome, nome) == 0){
                    total+= quantidade * ps[i].preco;
                }
            }
        }

        fprintf(s,"R$ %.2f\n",total);
        total = 0;

    }

    fclose(f);
    fclose(s);
    fclose(b);

}