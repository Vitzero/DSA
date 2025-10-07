#include <stdio.h>
#include <string.h>
#define QTLIN 10
#define QTCOL 15

void copiaString(char m[QTLIN][QTCOL], int lin, int col, int N, char s[50]){
    int l = lin; 
    int c = col;
    int counter = 0;

    while (counter < N && l < QTLIN){
        s[counter++] = m[l][c];
        c++;
        if (c >= QTCOL) {
            c = 0;
            l++;
        }
    }

    s[counter] = '\0'; 
}


int main()
{
    
    char matriz[10][15] = {
        {'a', 'c', 'p', 'p', 'r', 'o', 'v', 'a', 'y', 'z', 'b', 'c', 'd', 'e', 'f'},
        {'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u'},
        {'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
        {'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y'},
        {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n'},
        {'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c'},
        {'d', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r'},
        {'s', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g'},
        {'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v'},
        {'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k'}
    };
    
    int linha = 0, coluna = 4, N = 5;
    char s[50];
    char s1[50];
    char s2[50];
    
    
    copiaString(matriz, linha, coluna, N, s);
   
    copiaString(matriz, linha+8, coluna+4, N+8, s1);
   
    puts(s);
    puts(s1);
   
    return 0;
}
