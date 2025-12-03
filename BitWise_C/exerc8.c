#include <stdio.h>
int crossover(int a, int b)
{
    int cross;

    cross = a;
    cross = (a & 0xFFFF0000) | (b & 0x0000FFFF);

    return cross;
}
void printarBinario(int n){
    int i = 32;
    printf("\n X=");
    for(i = 31; i >= 0; i--){
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf(" : BINARIO\n");
}
int main()
{
    int a, b;
    scanf("%d %d", &a , &b);
    int x = crossover(a,b);

    printf("\na = %d : Decimal\n%x : Hexadecimal\n",a,a);
    printf("\nb = %d : Decimal\n%x : Hexadecimal\n",b,b);
    printf("\nX = %d : Decimal\n%x : Hexadecimal\n",x,x);

    printarBinario(x);
}