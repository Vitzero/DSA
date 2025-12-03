#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float le_arquivo(char *arq, char *matricula)
{
    FILE *f = fopen(arq, "r");
    if (NULL)
    {
        return -1;
    }

    char mat[11];
    float p1, p2, p3;

    while (fscanf(f, "%s %f %f %f", mat, &p1, &p2, &p3) == 4)
    {
        if (strcmp(matricula, mat) == 0)
        {
            float media = 0;

            return media = (p1 + p2 + p3) / 3.0;
        }
    }

    return -1;
}

int main()
{
    char matricula[10] = "8820324-3";
    char arquivo[50] = "entrada2.txt";

    float n1;

    n1 = le_arquivo(arquivo, matricula);

    if (n1 > 0)
    {
        printf("\nMedia foi: %f", n1);
    }
}