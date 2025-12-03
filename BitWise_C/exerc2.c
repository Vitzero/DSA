#include <stdio.h>
#include <stdlib.h>
int inverteVariaveis(int * a, int * b){

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;

}

int main(){
    
    int a, b;

    scanf("%d %d",&a,&b);

    inverteVariaveis(&a,&b);

    printf("a = %d b= %d\n", a, b);

}