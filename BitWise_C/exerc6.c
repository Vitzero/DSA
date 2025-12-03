#include <stdio.h>
void descompacta(unsigned short int c){
    int b = c & 0xFF  ;
    c = c >> 8;
    int a = c & 0xFF;

    printf("\n%c %c\n", a ,b);
    printf("\n%d %d\n", a ,b);

}

int main(){

    char a,b;

    scanf(" %c %c", &a , &b);

    unsigned short int c = a;

    c = (c << 8);

    c += b;

    printf("%04X\n", c);

    descompacta(c);
}