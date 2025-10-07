/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

struct data{
   int d,m,a;
};
typedef struct data DATA;

//ou
/*
typedef struct data{
    int d, m, a;
};
*/

DATA menor_data(DATA d1, DATA d2){
    if(d1.a < d2.a){
        return d1;
    }else if(d1.a == d2.a && d1.m < d2.m ){
        return d1;
    }else if( d1.a == d2.a && d1.m == d2.m && d1.d < d2.d){
        return d1;
    }else{
        return d2;
    }
}
//ou
DATA menor_dataSomando(Data d1, DATA d2){
    if(d1.a*100000+d1.m*100+d1.d < d2.a*10000 + d2.m * 100 + d2.d){
        return d1;
    }else{
        return d2;
    }
}

int main()
{
   DATA d1;
   
   printf("Digite 2 data no formato xx/xx/xx:\n");
   scanf("%d/%d/%d", &d1.d, &d1.m, &d1.a);
   scanf("%d/%d/%d", &d2.d, &d2.m, &d2.a);
   
   DATA m = menor_data(d1,d2);
   DATA mm = menor_dataSomando(d1,d2);
   
   printf("menor: %d/%d/%d\n",m.d,m.m,m.a);
   printf("menor: %d/%d/%d\n",mm.d,mm.m,mm.a);

    return 0;
}