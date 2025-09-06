#include <stdio.h>
#include <string.h>
#define N 100
int main()
{
    char s[N];
    char sDup[N];
    
    gets(s);
    
    int i,j = 0;
    
    for(i = 0; s[i] != '\0'; i++){
        sDup[j++] = s[i];
        sDup[j++] = s[i];
    }
    
    puts(sDup);
}