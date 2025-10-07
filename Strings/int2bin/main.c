/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int GetTamanhoString(char string[]){
   
    int i;
    int count = 0;
    for(i = 0; string[i] != '\0'; i++){
        count++;
    }
    
    return count;
}

int main()
{
    int num;
    
    scanf("%d", &num);
    
    char string[100];
    
    int i=0;
    
    while(num > 0){
        string[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }
    
    int tamanho = GetTamanhoString(string);
    
    for(i = tamanho-1; i>=0; i--){
        printf("%c", string[i]); // or printf("%d", string[i] + '0');
    }
    
    return 0;
}