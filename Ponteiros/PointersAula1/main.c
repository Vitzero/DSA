/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
//scanf passa a memória que tu atribui o valor a ela
//printf pega por cópia o valor da memória

int resto11(int soma1){
    int resto = soma1 % 11;
    if(resto == 0 || resto == 1){
        return 0;
    }
    else{
        return 11 - resto;
    }
}

void calcula_digitos(char cpf[], int *d1, int *d2){
    int i, soma1=0, m1 = 10, soma2=0, m2 = 11;
    int resto;
    
    for(i=0; cpf[i] != '\0'; i++){
        if(cpf[i]>= '0' && cpf[i] <= '9'){
            soma1 += (cpf[i] - '0') * m1--;
            soma2 += (cpf[i] - '0') * m2--;
        }
    }
    
    *d1 = resto11(soma1);
    soma2 += *d1 * 2;
    *d2 = resto11(soma2);
   
}

int main()
{
    char cpf[12] = "316.297.720";
    
    int d1, d2;
    
    calcula_digitos(cpf, &d1, &d2);
    
    printf("D1 = %d D2 = %d\n", d1, d2);
    
    return 0;
}