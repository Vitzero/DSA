/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>


void num2str(int n, char bin[33]){
    int i, r = 0;
    i = 0;

    char aux = 0;

    while(n > 0) {
        r = n % 2; 37 % 2 == 1
        bin[i] = r + '0'; 
        n /= 2;
        i++;
    }
    
    int f=i-1;
    i=0;

    for(i = 0; i < f; i++, f--){
        aux = bin[i];
        bin[i] = bin[f];
        bin[f] = aux;
    }

}

int main()
{
    int n = 0;
    char s[33];

    scanf("%d", &n);

    num2str(n, s);
    
    printf("Binario: %s\n", s);

    return 0;
}
