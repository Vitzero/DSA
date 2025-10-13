#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *numeros;
    int n;
    int i = 0;

    printf("digite a quantidade de numeros que quer inserir: ");
    scanf("%d", &n);

    numeros = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

}
