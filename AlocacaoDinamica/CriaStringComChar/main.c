#include <stdlib.h>
#include <stdio.h>
char * cria_string(int n, char c){
    char *str = (char *)malloc((n+1) * sizeof(char));
    
    if(str == NULL) return NULL;
    
    int i;
    
    for(i=0; i < n; i++){
        str[i] = c;
    }
    
    str[i] = '\0';
    return str;
}

int main()
{
    char *s = cria_string(3,'A');
    
    if(s != NULL) {
        printf("%s", s);
    }
   
    free(s);
    
    return 0;
}
