/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
typedef struct sttHorario{
    int h, m, s;
};


sttHorario Adiciona (sttHorario atual, int seg){
    int somaSegundos = 0;
    
    somaSegundos = (atual.h * 3600 + atual.m *60 + atual.s + seg);
    
    sttHorario novo;
    
    novo.h = (somaSegundos / 3600) % 24;
    somaSegundos %= 3600;
    
    novo.m = somaSegundos / 60;
    novo.s = somaSegundos % 60;
    
    return novo;
}

int main()
{
    sttHorario atual = {23, 59 ,59};
    
    int seg = 1;
    sttHorario novo = adiciona(atual, seg);
    printf("%d:%d:%d\n", novo.h, novo.m, novo.s); 
    return 0;
}
