#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct aluno
{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
};
typedef struct aluno ALUNO;

float CalcMedia(ALUNO a){
    float soma = 0;
    soma = a.nota1 + a.nota2 + a.nota3;

    return soma/3;

}

int main()
{
    char entrada[] = "questao5.bin";

    FILE *f = fopen(entrada, "rb");
    if(f == NULL){
        printf("ERRO ABRINDO ARQUIVO ENTRADA");
    }

    ALUNO a;

    int contador = 0;

    while (fread(&a, sizeof(ALUNO), 1, f))
    {
        contador++;
    }

    rewind(f);

    ALUNO *aa = (ALUNO *)malloc(contador * sizeof(ALUNO));

    int incrementador = 0;
    while (fread(&aa[incrementador], sizeof(ALUNO), 1, f))
    {
        incrementador++;
    }

    int i, j;
    ALUNO aux;
    
    for(i = 0; i < contador - 1; i++){
        for(j = 0; j < contador - 1 - i; j++){
            if(CalcMedia(aa[j]) < CalcMedia(aa[j+1])){
                aux = aa[j];
                aa[j] = aa[j+1];
                aa[j+1] = aux;
            }
            else if(CalcMedia(aa[j]) == CalcMedia(aa[j+1])){
                int resultado = strcmp(aa[j].nome, aa[j+1].nome);

                if(resultado > 0){
                    aux = aa[j];
                    aa[j] = aa[j+1];
                    aa[j+1] = aux;
                }
            }
        }
    }

    FILE * s = fopen("saida5.txt", "wb");

    for(i = 0; i<contador; i++){
        fprintf(s, "%s %.2f\n", aa[i].nome, CalcMedia(aa[i]));
    }

    free(aa);
    fclose(s);
    fclose(f);

    return 0;
}
