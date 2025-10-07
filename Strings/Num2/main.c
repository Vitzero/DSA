/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
    char s[N];
    char sDup[N];
    
    gets(s);
    
    int i,j = 0;
    
    for(i = 0; s[i] != '\0'; i++){
        sDup[j++] = s[i];
        sDup[j++] = s[i];
    }
    
    puts(sDup);
}