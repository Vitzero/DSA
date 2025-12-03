#include <stdio.h>
#include <stdlib.h>

int compactaHora(int hora, int minuto, int segundos){ 
    int horacodificada = hora;
    horacodificada = hora;
    horacodificada = horacodificada << 8;
    horacodificada += minuto;
    horacodificada = horacodificada << 8;
    horacodificada += segundos;
    
    return horacodificada;
}

int soma1sectobin(int compacta){
    int analise = (compacta & 0xFF);
    if(analise == 0xFF){
        compacta = (compacta & ~0xFF);

        if(compacta == 0x173B3B){
            return compacta = 0;
        }

        return compacta;
    }
    else{
        compacta += 1;
        return compacta;
    }
}

int main(){

    int hora = 13;
    int minutos = 45;
    int segundos = 30;

    int compacta = compactaHora(hora,minutos,segundos);

    compacta = soma1sectobin(compacta);    

    printf("%x", compacta);

}