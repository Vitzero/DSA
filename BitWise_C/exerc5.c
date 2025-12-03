#include <stdio.h>
void escreveBits(int n)
{
    int i = 0;
    for (i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        printf("%d", bit);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    escreveBits(n);
}