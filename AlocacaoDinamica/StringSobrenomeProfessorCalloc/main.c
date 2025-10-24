#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100
char * sobrenome(char *nome){
    int i, espaco, t, k;
    
    for(i = 0; nome[i] != '\0'; i++){
        if(nome[i] == ' '){
            espaco = i;
        }
    }
    
    // return &nome[espaco+1]; e tirar free()
    
    t = i - espaco;
    
    char * s = (char *)calloc(t,sizeof(char));
    
    if(s == NULL){
        return NULL;
    }
    
    for(i = espaco + 1, k = 0; nome[i] != '\0'; k++, i++){
        s[k] = nome[i];
    }
    s[k] = '\0';
    
    return s;
}

int main()
{
    char nome[N];
    int i;
    
    for(i=0; i < 5; i++){
        printf("Digite o nome:\n");    
        
        gets(nome);
        
        char * ss = sobrenome(nome);
        
        printf("%s\n", ss);
        
        free(ss);
    }
    

    return 0;
}