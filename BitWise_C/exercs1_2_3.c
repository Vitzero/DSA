#include <stdlib.h>
#include <stdio.h>

int ehPar(int n){
    
    int par = n & 1;
    
    return par;
    
}

char char2upper(char c){
    
    c = (c & ~32);
    return c;
    
}

char char2lower(char b){
    b = (b | 32);
    return b;
}

int main()
{
    int n;
    printf("digite um numero pra ver se é par:\n");
    scanf("%d", &n);
    
    if(!ehPar(n)){
        printf("eh par!\n\n");
    }
//----------------------//char para maiusculo
    char c;
    
    printf("digite uma letra minuscula:\n");
    scanf(" %c", &c);
        
    c = char2upper(c);
    
    printf("letra pra maiusculo: %c\n", c);

//----------------------//char para minusculo

    char b;
    printf("digite uma letra maiuscula:\n");
    scanf(" %c", &b);

    b = char2lower(b);

    printf("letra pra maiusculo: %c\n", b);
        
//------------------------------------------------

    return 0;
}