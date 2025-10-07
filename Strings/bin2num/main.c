/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
    char s[N];
    gets(s);
    int i,num = 0,mult = 1;
    int tamanho = strlen(s);
    
    for(i = tamanho-1; i >= 0; i--){
        num = num + (s[i] - '0') * mult;
        mult *= 2;
    }
    
    printf("%d", num);
    
    return 0;
}
