#include <stdlib.h>
#include <stdio.h>

int * separa(char str[], int * qtd){
    int i = 0, j=0;
    int countEspace = 0;
    
    for(i = 0; str[i] != '\0'; i++){
        if (str[i] == ','){
            countEspace++;
        }
    }
    
    int * intVet = (int *) malloc(countEspace + 1 * sizeof(int));
    if(intVet == NULL){
        return NULL;
    }
    
    int num = 0;
    for(i = 0; str[i] != '\0'; i++){
       if(str[i] >= '0' && str[i] <= '9')
       {
           num = num * 10 + (str[i] - '0');
       }
       else if(str[i] == ',')
       {
           intVet[j++] = num;
           num = 0;
       }
    }
    intVet[j] = num;
    
    *qtd = countEspace;
    return intVet;
    
}
void escreve(int * v, int qtd){
    int i = 0;
    
    for(i=0; i<qtd; i++){
        printf("%d,", v[i]);
    }
    printf("%d", v[qtd]);
}

int main()
{
    char str[] = "10,15,245,11,5,1243";

    int qtd = 0;
    
    int * inteirosResultado = separa(str, &qtd);
    
    escreve(inteirosResultado, qtd);
    
    free(inteirosResultado);

    return 0;
}
