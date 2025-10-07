/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
int ehPalidromo(char s[]){
    int i,j;
    
    int tamanho = strlen(s);
    
    for(i = 0, j = tamanho-1; i < j; i++, j--){
        if(toupper(s[i]) != toupper(s[j])){
            return 0;
        }
        
    }
    
    return 1;
}
int main()
{
    char s[100];
    gets(s);
    
    if(ehPalidromo(s)){
        printf("%s, eh palindromo", s);
    }else{
        printf("%s, NAO eh palindromo", s);
    }
    
    return 0;
}