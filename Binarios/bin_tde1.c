#include <stdio.h>
#include <stdlib.h>
typedef struct aluno { 
        char nome[50];
        char cadastro[10]; 
        float n1; 
        float n2; 
        float n3;
} ALUNO;

int CalcMedia(ALUNO a){
    int result = (int)(a.n1 + a.n2 + a.n3) / 3.0;
    return result;
}

int main(){

    int histograma[10] = {0};

    char entrada[] = "alunos.dat";

    FILE * f = fopen(entrada, "rb");

    ALUNO a;

    while (fread(&a, sizeof(ALUNO), 1, f) == 1)
    {
        int media = (int) CalcMedia(a);
        

        if(media >= 0 && media <= 10){
            histograma[media]++;
        }
    }
    
    int i = 0;
    int j = 0;
    for(i = 0; i < 10; i++){
        printf("Intervalo %d - %d: ", i, i+1);
        for(j = 0; j < histograma[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    fclose(f);
}