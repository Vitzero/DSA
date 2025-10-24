/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
void escreve( int *v, int n){
    
    int i;
    
    for(i=0; i < n; i++){
        printf("%d\n", v[i]);
    }
}
int main()
{
    int v1[5] = {7,8,2,1,4};
    int v2[3] = {5,1,4};
    
    escreve(v1,5);
    escreve(v1,3);
    
    return 0;
}
