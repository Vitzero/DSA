#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
    char s[N];
    char sEspac[N];
    
    gets(s);
    
    int i,j = 0;
    
    for(i = 0; s[i] != '\0';i++){
        if(s[i] == ' '){
            continue;
        }else{
            sEspac[j++] = s[i];
            sEspac[j++] = ' ';
        }
        
    }
    
    puts(sEspac);
    
    return 0;
}
