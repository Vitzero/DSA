#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario
{
    char cpf[20];
    char nome[50];
    float salario;
    char departamento[30];
};
typedef struct funcionario FUNC;

FUNC *le_arquivo(char *arq, int *t)
{

    int tamanho;

    FILE *p = fopen(arq, "r");
    if (p == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    fscanf(p, "%d\n", &tamanho);

    FUNC *ListaFuncs = (FUNC *)malloc(tamanho * sizeof(FUNC));

    int i = 0;
    for (i = 0; i < tamanho; i++)
    {
        fgets(ListaFuncs[i].cpf, 20, p);
        ListaFuncs[i].cpf[strlen(ListaFuncs[i].cpf) - 1] = '\0';
        fgets(ListaFuncs[i].nome, 50, p);
        ListaFuncs[i].nome[strlen(ListaFuncs[i].nome) - 1] = '\0';
        fscanf(p, "%f\n", &ListaFuncs[i].salario);
        fgets(ListaFuncs[i].departamento, 30, p);
        ListaFuncs[i].departamento[strlen(ListaFuncs[i].departamento) - 1] = '\0';
    }

    fclose(p);

    *t = tamanho;

    return ListaFuncs;
}

void escreve_saida(FUNC *FuncsLista, int tamanho, char *arquivoSaida)
{
    FILE *f = fopen(arquivoSaida, "w");
    int i = 0;

    for (i = 0; i < tamanho; i++)
    {
        fprintf(f, "%s\n", FuncsLista[i].cpf);
        fprintf(f, "%s\n", FuncsLista[i].nome);
        fprintf(f, "%.2f\n", FuncsLista[i].salario);
        fprintf(f, "%s\n", FuncsLista[i].departamento);
    }

    fclose(f);
}
FUNC *ordena_Lista(FUNC *Lista, int tamanho)
{
    int i, j;

    FUNC aux;

    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = 0; j < tamanho - i - 1; j++)
        {
            if (strcmp(Lista[j].nome, Lista[j + 1].nome) > 0)
            {
                aux = Lista[j];
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = aux;
            }
        }
    }

    return Lista;
}

int main()
{
    char *arquivo = "entrada3.txt";
    int tamanho;

    char *arquivoSaida = "saida3.txt";

    FUNC *s = le_arquivo(arquivo, &tamanho);
    FUNC *sOrdenada = ordena_Lista(s, tamanho);
    escreve_saida(sOrdenada, tamanho, arquivoSaida);
}