/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

struct horario{
    int h, m, s;
};
typedef struct horario HORARIO;

void converte(int min, HORARIO *p){
    p->h = min /3600;
    min %= 3600;
    p->m = min / 60;
    p->s = min % 60;
}

int main()
{
    
    int min = 7359;
    HORARIO h;
    
    converte(min, &h);
    
    printf("%02d : %02d : %02d", h.h, h.m, h.s);
    
    return 0;
}