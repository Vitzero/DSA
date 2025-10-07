/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int *v = NULL;
    int i;
    
    v = (int *)malloc(10 *sizeof(int));
    
    if ( v == NULL){
        printf("erro na alocação\n");
        exit(0);
    }

    for(i=0; i < 10; i++){
        printf("%d\n", v[i]);
    }
    
    free(v);
    return 0;
}
