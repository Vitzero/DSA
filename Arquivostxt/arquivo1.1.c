#include <stdio.h>
#include <stdlib.h>

struct resultado
{
    int aprovados;
    int reprovados;
};
typedef struct resultado RESULTADO;

int le_arquivo(char *nomeArq, RESULTADO *resultados)
{
    FILE *f = fopen(nomeArq, "r");
    if (f == NULL)
    {
        return -1;
    }

    char nome[50];
    float p1, p2, p3;

    while (fgets(nome, 50, f) != NULL)
    {
        int returo = fscanf(f, "%f %f %f\n", &p1, &p2, &p3);

        if (returo != 3)
        {
            break;
        }

        float media = (p1 + p2 + p3) / 3;
        if (media >= 5)
        {
            resultados->aprovados += 1;
        }
        else
        {
            resultados->reprovados += 1;
        }
    }

    printf("aprovados: %d\n", resultados->aprovados);

    printf("reprovados: %d\n", resultados->reprovados);

    return 0;
}

int main()
{
    char arquivo[50] = "entrada.txt";
    RESULTADO result;

    le_arquivo(arquivo, &result);
}