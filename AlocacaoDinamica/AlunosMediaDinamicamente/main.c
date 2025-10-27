#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 7
struct aluno{
  char turma[20];
  char matricula[20];
  float nota;
};
typedef struct aluno ALUNO;

ALUNO *media (ALUNO *a, int nalunos, char codigo[15], float *media_calc, int *qtd){
    int i, j = 0, contadorAlunosX = 0;
    double somaNotas = 0;
    
    for(i = 0; i < nalunos; i++){
         if(strcmp(a[i].turma, codigo) == 0){
            contadorAlunosX++;
            somaNotas+= a[i].nota;
        }
    }
    
    ALUNO * resultado = (ALUNO *)malloc(contadorAlunosX * sizeof(ALUNO));
    if(resultado == NULL){
        *media_calc = -1;
        printf("%f", *media_calc);
        return NULL;
    }
    
    for(i = 0; i < nalunos; i++){
        if(strcmp(a[i].turma, codigo) == 0){
            resultado[j++] = a[i];
        }
    }
    
    *media_calc = somaNotas / contadorAlunosX;
    
    *qtd = contadorAlunosX;
    
    return resultado;
}

void escreve(ALUNO * resultado, int qtd){
    int i = 0;
    printf("Alunos do curso selecionado:\n");
    for(i = 0; i < qtd; i++){
        printf("%s %s %f\n", resultado[i].turma, resultado[i].matricula, resultado[i].nota);
    }
    
}

int main()
{
      ALUNO alunos[N] = {
        {"INF", "9911234-9", 7.3},
        {"INF", "9821234-9", 8.7},
        {"CRE", "9926789-1", 10.0},
        {"CRE", "9010087-2", 9.2},
        {"INF", "8820324-3", 3.4},
        {"INF", "9210478-5", 7.2},
        {"INF", "9020256-8", 6.7}
    };

    float media_calc = 0;
    int qtd = 0;
    
    ALUNO * resultado = media(alunos, N, "INF", &media_calc, &qtd);
    
    escreve(resultado, qtd);
    printf("A media da turma foi: %2.f\n", media_calc);
    
    free(resultado);
    
    
    return 0;
}
