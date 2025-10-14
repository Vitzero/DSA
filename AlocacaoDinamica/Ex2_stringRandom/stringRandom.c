
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char * GerarStringAleatoria(int n){
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charsetSize = strlen(charset);
    
    char * str = (char *)malloc(n * sizeof(char));
    int i = 0;
    int indice;
    for(i = 0; i < n;){
        indice = rand() % charsetSize;
        str[i++] = charset[indice];
    }
    
    str[i] = '\0';
    
    return str;
   
}
int main()
{
    srand(time(NULL));
    
    char * s = GerarStringAleatoria(15);
    
    puts(s);
    free(s);
    return 0;
}