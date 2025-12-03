#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Paises
{
    char nome[30];
    int medalhasOuro;
    int medalhasPrata;
    int medalhasBronze;
};

typedef struct Paises PAISES;

PAISES *le_arquivo(char *arquivo, int *tamanho)
{

    FILE *f = fopen(arquivo, "r");
    if(NULL){
        exit(1);
    }

    int qtd;
    fscanf(f, "%d", &qtd);

    PAISES *p = (PAISES *)malloc(qtd * sizeof(PAISES));
    if(p == NULL){
        exit(1);
    }

    int i;
    for (i = 0; i < qtd; i++)
    {
        fscanf(f, "%s %d %d %d", p[i].nome, &p[i].medalhasOuro, &p[i].medalhasPrata, &p[i].medalhasBronze);
    }

    fclose(f);

    *tamanho = qtd;

    return p;
}

void ordenaMedalhas(PAISES *p, int qtd)
{
    int i, j;

    PAISES aux;

    for (int i = 0; i < qtd - 1; i++)
    {
        for (j = 0; j < qtd - i - 1; j++)
        {
            if (
                (p[j].medalhasOuro < p[j + 1].medalhasOuro) ||
                (p[j].medalhasOuro == p[j + 1].medalhasOuro && p[j].medalhasPrata < p[j + 1].medalhasPrata) ||
                (p[j].medalhasOuro == p[j + 1].medalhasOuro && p[j].medalhasPrata == p[j + 1].medalhasPrata && p[i].medalhasBronze < p[j + 1].medalhasBronze) ||
                (p[j].medalhasOuro == p[j + 1].medalhasOuro && p[j].medalhasPrata == p[j + 1].medalhasPrata && p[i].medalhasBronze == p[j + 1].medalhasBronze && strcasecmp(p[j].nome, p[j + 1].nome))
            )
            {
                aux = p[j];
                p[j] = p[j + 1];
                p[j + 1] = aux;
            }
        }
    }
}
void escreve_saida(PAISES * p, char * arq, int quantidade){
    int i;

    FILE * f = fopen(arq, "w");

    for(i = 0; i < quantidade; i++){
        fprintf(f, "%s %d %d %d\n", p[i].nome, p[i].medalhasOuro, p[i].medalhasPrata, p[i].medalhasBronze);
    }

    fclose(f);

}

int main()
{

    char arquivo[] = "entrada6.txt";
    char arquivoSaida[] = "Saida6.txt";
    int tamanhoPaises;

    PAISES *p = le_arquivo(arquivo, &tamanhoPaises);

    ordenaMedalhas(p, tamanhoPaises);

    escreve_saida(p, arquivoSaida, tamanhoPaises);
}