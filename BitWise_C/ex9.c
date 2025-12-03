#include <stdio.h>
int compactaHora(int hora, int minuto, int segundos){ // exerc9
    int horacodificada = hora;
    horacodificada = hora;
    horacodificada = horacodificada << 8;
    horacodificada += minuto;
    horacodificada = horacodificada << 8;
    horacodificada += segundos;
    
    return horacodificada;
}
void descompactaHora(int horaCompacta, int *hora, int *min, int *seg){ // exerc 10
    *hora = (horaCompacta >> 16) & 0xFF;
    *min = (horaCompacta >> 8 ) & 0xFF;
    *seg = horaCompacta & 0xFF;
}
int main(){
    
    int hora = 14, minuto = 35, segundo = 25;
    int hora_result = compactaHora(hora, minuto, segundo);

    hora = 0; // só conferindo
    minuto = 0; // só conferindo
    segundo = 0;// só conferindo

    descompactaHora(hora_result, &hora ,&minuto , &segundo);

    printf("\n%d : %d : %d\n", hora, minuto, segundo);

}

