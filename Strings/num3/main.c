/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
    char s[N];
    char sEspac[N];
    
    gets(s);
    
    int i,j = 0;
    
    for(i = 0; s[i] != '\0';i++){
        if(s[i] == ' '){
            continue;
        }else{
            sEspac[j++] = s[i];
            sEspac[j++] = ' ';
        }
        
    }
    
    puts(sEspac);
    
    return 0;
}
