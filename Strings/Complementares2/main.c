/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[100];
    int i,j;
    gets(s);
    int somaChars;
    
    for(i = 0; s[i] != '\0'; i++){
        if( s[i] > '0' && s[i] < '9' ){
            somaChars+= (s[i] - '0');
        }
       
    }
    
    printf("%d", somaChars);

    return 0;
}