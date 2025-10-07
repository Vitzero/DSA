/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    char sobrenome[50];
    gets(s);
    
    int i,j;
    int index;
    int tamanho = strlen(s);
    
    for(i = tamanho-1; i>=0; i--){
        if(s[i] == ' '){
            index = i;
            break;
        }
    }
    
    for(i = index + 1, j = 0; s[i] != '\0'; i++, j++) {
        sobrenome[j] = s[i];
    }
    
    
    printf("%s", sobrenome);

    return 0;
}
