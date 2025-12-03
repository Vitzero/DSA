#include <stdio.h>
struct estado{
            char nome[31];
            int numveic;
            int numacid;
};
typedef struct estado ESTADO;

int main(){
    char entrada[] = "questao3.bin";
    FILE * f = fopen(entrada, "rb");

    ESTADO estados[26];
    ESTADO atual;
    ESTADO maior;
    maior.numacid = -1;
    int contador = 0;

    while (fread(&atual, sizeof(ESTADO), 1, f))
    {
        if(atual.numacid > maior.numacid){
            maior = atual;
        }
    }

    rewind(f);

    for(contador = 0; contador < 26; contador++){
        fread(&atual, sizeof(ESTADO), 1, f);

        printf("\n%s %d %d", atual.nome, atual.numveic, atual.numacid);
    }
    
    printf("\n%s %d %d", maior.nome, maior.numveic, maior.numacid);

    fclose(f);

}


