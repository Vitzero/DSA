/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define N 5
struct aluno{
  char nome[50];
  float media;
};
typedef struct aluno ALUNO;

void escreve_alunos(ALUNO v[N]){
    int i;
    for(i=0; i < N; i++){
        printf("%s %.2f\n", v[i].nome, v[i].media);
    }
}
void maiores_medias(ALUNO v[N], ALUNO *m1, ALUNO *m2){
    int i;
    (*m1).media = -1;
    (*m2).media = -1;
    for(i=0; i < N; i++){
        if(v[i].media > (*m1).media){ // v[i].media > m1->media
            *m2 = *m1;
            *m1 = v[i];
        }
        else if(v[i].media > (*m2).media){ //v[i].media > m2->media
            *m2 = v[i];
        }
        
    }
    
}
int main()
{
    ALUNO v[N] = {{"teste1", 7}, {"teste2", 8},{"teste3", 9}, {"teste4", 10},{"teste5", 5}};
    escreve_alunos(v);
    
    ALUNO m1, m2;
    maiores_medias(v, &m1, &m2);

    
    printf("%s %2.f\n", m1.nome, m1.media);
    printf("%s %2.f\n", m2.nome, m2.media);

    
        return 0;
}
