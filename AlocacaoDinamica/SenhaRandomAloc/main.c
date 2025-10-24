#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char * gera_senha(int n, int * ma, int * mi, int * num){
    // Ponteiro Armazena o endereço de uma variavel ( &variavel );
    
    char * str = (char *)malloc((n+1) * sizeof(char));
    if(str == NULL){
        return NULL;
    }
    
    *ma = 0;
    *mi = 0;
    *num = 0;
    
    int i, tipo;
    srand(time(NULL));
    
    for(i = 0; i < n; i++){
        tipo = rand() % 3;
        
        switch(tipo){
            case 0: str[i] = 'A' + rand() % 26;
            *ma+=1;
            break;
            case 1: str[i] = 'a' + rand() % 26;
            *mi+=1;
            break;
            case 2: str[i] = '0' + rand() % 10;
            *num+=1;
            break;
        }
    }

    return str;
    
}

int main()
{
    int n, ma, mi, num;
    
    printf("digite o tamanho da senha\n");
    scanf("%d", &n);
    
    char * s = gera_senha(n, &ma, &mi, &num);
    
    if(s != NULL){
        printf("%s\n", s);
        printf("Mausculas: %d Minusculas: %d Numeros: %d", ma, mi, num);
        free(s);
    }

    return 0;
}