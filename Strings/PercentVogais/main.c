/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100

int GetSizeStr(char s[]){
    int i,count = 0;
    
    for(i = 0; s[i] != '\0'; i++){
        count++;
    }
    
    return count;
}

float ContVogais (char s[]){
    int tamanho = GetSizeStr(s);
    int vogais = 0;
    float porcentagemVogal = 0;
    int i;
    
    for(i = tamanho-1; i>=0; i--){
        if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u' ){
            vogais++;
        }
    }
    
    porcentagemVogal = ((float)vogais / tamanho) * 100.0f;
    
    return porcentagemVogal;
    
}

int main()
{
    char s[N];
    gets(s);

    float porcentagemVogal;
    
    porcentagemVogal = ContVogais(s);

    printf("\n%.4f", porcentagemVogal);

    return 0;
}
