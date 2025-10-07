
#include <stdio.h>

int SomaStringNums(char string[]){
    int soma = 0;
    int num = 0;
    int i;
    
    for(i = 0; string[i] != '\0'; i++){
        if(string[i] >= '0' && string[i] <= '9'){
            
            num = num * 10 + (string[i] - '0');
        }
        else{
            soma+= num;
            num = 0;
        }
        
    }
    soma+= num;
    
    return soma;
}

int main()
{
    
    char string[] = {'0','1','2','a','b','3','n','2'};
    
    int resultado = SomaStringNums(string);
    
    printf("%d",resultado);

    return 0;
}