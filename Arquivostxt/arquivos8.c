#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_arquivos(char *arquivo1, char *arquivo2, char *final)
{

    int n1, n2, n3;
    int r1, r2;

    FILE *j1 = fopen(arquivo1, "r");
    if (j1 == NULL)
    {
        exit(1);
    }

    FILE *j2 = fopen(arquivo2, "r");
    if (j2 == NULL)
    {
        exit(1);
    }

    FILE *f = fopen(final, "w");

    r1 = fscanf(j1, "%d", &n1);
    r2 = fscanf(j2, "%d", &n2);

    while (r1 == 1 || r2 == 1)
    {
        if (r1 == 1 && r2 == 1)
        {
            if (n1 <= n2)
            {
                fprintf(f, "%d\n", n1);
                r1 = fscanf(j1, "%d", &n1);
            }
            else
            {
                fprintf(f, "%d\n", n2);
                r2 = fscanf(j2, "%d", &n2);
            }
        }

        else if(r1 == 1){
            fprintf(f, "%d\n", n1);
            r1 = fscanf(j1, "%d", &n1);
        }
        else if(r2 == 1){
            fprintf(f, "%d\n", n2);
            r2 = fscanf(j2, "%d", &n2);
        }
       
    }

    fclose(j1);
    fclose(j2);
    fclose(f);
}

int main()
{
    char arquivo1[] = "juntar1.txt";
    char arquivo2[] = "juntar2.txt";

    char arquivoResultado[] = "juntarResultado.txt";

    merge_arquivos(arquivo1, arquivo2, arquivoResultado);
}