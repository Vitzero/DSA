#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#define N 4
struct aluno{
    char nome[50];
    float n1,n2,n3;
};
typedef struct aluno ALUNO;


float media(ALUNO a){
    return (a.n1 + a.n2 + a.n3) / 3;
}

void ordena_alunos(ALUNO v[]){
    int i = 0,j = 0;
    ALUNO aux;
    for(i = 0; i < N - 1; i++){
        for(j = 0; j < N - i; j++){
            if(media(v[j]) < media(v[j+1])){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
            else if(media(v[j]) == media(v[j+1]) && strcasecmp(v[j].nome, v[j+1].nome) > 0 ){
               aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void escreve_alunos (ALUNO v[]){
    int i;
    
    for(i = 0; i < N; i++){
        printf("\n%s %2.2f", v[i].nome, media(v[i]));
    }
}

void le_alunos(ALUNO v[]){
    int i;
    for(i=0; i < N; i++){
        printf("Digite o nome:\n");
        gets(v[i].nome);
        printf("Digite as 3 notas:\n");
        scanf("%f %f %f", &v[i].n1 ,&v[i].n2, &v[i].n3);
        __fpurge(stdin);
    }
}

int main()
{
    ALUNO v[N];
    le_alunos(v);
    ordena_alunos(v);
    escreve_alunos(v);
    
    
    return 0;
}