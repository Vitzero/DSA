#include <stdio.h>
#include <stdlib.h>
int * fazFibonacciMalloc(int n){
    
    int * vetor = (int *)malloc(n * sizeof(int));
    
    int n1 = 0, n2 = 1, n3, i = 2;
    
    if (n > 0) vetor[0] = n1;
    if (n > 1) vetor[1] = n2;
    
    while( n3 < n){
        n1 = n2 + n3;
        vetor[i++] = n1;
        
        n3 = n2;
        n2 = n1;
    }
    
    return vetor;
    
}
    

int main()
{
    int n, returno;
    scanf("%d", &n);
    
    int * p = fazFibonacciMalloc(n);
    int i = 0;
    
    for(i = 0; i < n; i++){
        printf("%d\n", p[i]);
    }
    
    free(p);
    
    return 0;
}
