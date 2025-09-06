#include <stdio.h>

void Abaixo(int mat[5][5]){
    int identidade = 1;
    int i,j;

    //inferior
    for(i = 1; i < 5; i++){
        for(j = i + 1; j < 5; j++){
            if(mat[i][j]!= 0){
                identidade = 0;
            }
        }
    }
    if(identidade){
        printf("primeira matriz é identidade!\n");
    }else {
    printf("Matriz NÃO é identidade!\n");
    }
}

void Acima(int mat[5][5]){
    int identidade = 1;
    int i,j;

    //superior
    for(i = 0; i < 5; i++){
        for(j = 0; j < i; j++){
            if(mat[i][j]!= 0){
                identidade = 0;
            }
        }
    }
    if(identidade){
        printf("matriz é identidade!\n");
    }else {
    printf("Matriz NÃO é identidade!\n");
    }
}

void diagonal(int mat[5][5]){
    int identidade = 1;
    int i,j;
    for(i = 0; i < 5; i++){
            if(mat[i][i] != 1){
                identidade = 0;
            }
        }
    if(identidade){
        printf("matriz é identidade!\n");
    } else {
        printf("Matriz NÃO é identidade!\n");
    }
}

int main(){
    
    int i,j;
    int identidade = 1;
    int mat[5][5] =
    {
        {1,1,1,1,1},
        {0,1,1,1,1},
        {0,0,0,1,1},
        {0,0,0,0,1},
        {0,0,0,0,0}
    };
    int mat2[5][5] =
    {
        {1,0,0,0,0},
        {1,1,0,0,0},
        {1,1,1,0,0},
        {1,1,1,1,0},
        {1,1,1,1,1}
    };

    printf("Verificando primeira matriz:\n");
    Abaixo(mat);
    Acima(mat);
    diagonal(mat);

    printf("\nVerificando segunda matriz:\n");
    Abaixo(mat2);
    Acima(mat2);
    diagonal(mat2);
}
