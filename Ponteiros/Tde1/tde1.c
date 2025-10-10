
#include <stdio.h>
int calculaDigito(int soma){
    int resto = 0;
    
    resto = soma % 11;
    
    //se resto for 11 ou
    
    if(resto == 10){
        return 0;
    }else{
        return resto;
    }
}
void titulo_de_eleitor(char *titulo, int *dv1, int *dv2){
    int i,soma=0,resto, multiplicador = 2, multiplicador2 = 7,soma2 = 0;
    
    for(i = 0; titulo[i] != '\0'; i++){
        soma+= (titulo[i] - '0') *multiplicador++;
    }
    *dv1 = calculaDigito(soma);
    
    soma2 += multiplicador2++ * *dv1;
    for(i = 9; titulo[i] != '\0'; i++){
        soma2 += multiplicador2 * (titulo[i] - '0');
    }
    
    *dv2 = calculaDigito(soma2);
    
}
int main()
{
    char titulo[] = {'0','0','4','3','5','6','8','7','0','9'};
    int digito1, digito2;
    titulo_de_eleitor(titulo,&digito1,&digito2);
    
    printf("%s d1(%d) d2(%d)", titulo, digito1, digito2);

    return 0;
}