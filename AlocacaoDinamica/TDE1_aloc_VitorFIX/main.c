#include <stdlib.h>
#include <stdio.h>
void escreve(int * v, int qtd){
    int i = 0;
    
    for(i=0;i<qtd;i++){
        printf("%d,", v[i]);
    }
}

int * separa(char str[], int * qtd){
    int i=0,j=0;
    int countElements = 0;
    
    for(i = 0; str[i]!= '\0'; i++){
        if(str[i] == ','){
            countElements++;
        }
    }
    
    int * retorno = (int *)malloc((countElements + 1) * sizeof(int));
    int num = 0;
    for(i = 0; str[i] != '\0' ; i++){
        if(str[i] == ','){
            retorno[j++] = num;
            num = 0;
        }
        else{
            num = num * 10 + (str[i] - '0');
        }
    }
    retorno[j] = num;
    
    *qtd = countElements+1;
    return retorno;
    
}
int main()
{
    char str[] = "10,15,245,11,5,1243";
    
    int qtd;

    int * intReturn = separa(str, &qtd);
    
    escreve(intReturn, qtd);
    
    return 0;
}
