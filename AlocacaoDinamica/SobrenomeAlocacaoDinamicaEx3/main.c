#include <stdio.h>
#include <stdlib.h>
char * ultimo_nome(char *nome_completo){
    int i = 0,espaco = 0;
    
    for(i = 0; nome_completo[i] != '\0'; i++){
        if(nome_completo[i] == ' '){
            espaco = i;
        }
    }
    
    char * NovaStr = (char *) malloc((espaco + 1) * sizeof(char));
    if(NovaStr == NULL){
        return null;
    }
    
    int j=0;
    
    for(i = espaco + 1; nome_completo[i] != '\0'; i++){
        NovaStr[j++] = nome_completo[i];
    }
    
    NovaStr[j] = '\0';
    
    return NovaStr;
    
}

int main()
{
    char string[100] = "Mário Jorge Lobo Zagallo"; 

    char * sobrenome = ultimo_nome(string);

    puts(sobrenome);
    
    free(sobrenome);    
    
    return 0;
}
