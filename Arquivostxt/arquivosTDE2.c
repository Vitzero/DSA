#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct colaborador
{
    int cod;
    char nome[15];
    float size;
};
typedef struct colaborador COLA;

int main()
{

    char entrada[] = "entradatde2.txt";
    char saida[] = "saidatde2.txt";

    FILE *f = fopen(entrada, "r");
    FILE *s = fopen(saida, "w");

    if (f == NULL || s == NULL)
    {
        printf("erro na abertura dos arquivos!");
        return 0;
    }

    char nome[15];
    long long espacoUtilizado;
    float EspacoEmMB;

    fprintf(s, "Nr.      User          espaco usado\n");
    int i = 0;

    while (fscanf(f, "%s %lld", nome, &espacoUtilizado) == 2)
    {
        i++;
    }

    int tamanho_colaboradores = i;

    i = 0;

    COLA *cs = (COLA *)malloc(tamanho_colaboradores * sizeof(COLA));

    int j = 0;

    rewind(f);

    while (fscanf(f, "%s %lld", cs[j].nome, &espacoUtilizado) == 2)
    {
        EspacoEmMB = (float)espacoUtilizado / (1024 * 1024);
        cs[j].size = EspacoEmMB;

        j++;
    }

    COLA aux;

    for (i = 0; i < tamanho_colaboradores - 1; i++)
    {
        for (j = 0; j < tamanho_colaboradores - 1 - i; j++)
        {
            if (cs[j].size < cs[j + 1].size)
            {
                aux = cs[j];
                cs[j] = cs[j + 1];
                cs[j + 1] = aux;
            }
        }
    }

    for (i = 0; i < tamanho_colaboradores; i++)
    {
        fprintf(s, "%-8d %-15s %10.2f MB\n", i + 1, cs[i].nome, cs[i].size);
    }

    fclose(f);
    fclose(s);
}