#include <stdio.h>

void pinta(unsigned char * m){
    int i, j;

    for(i = 0; i < 7; i++){    
        for(j = 7; j >= 0; j--){
            
            int b = (m[i] >> j) & 1;

            if(b){
                printf("#");
            }
            else{
                printf(" ");
            }

        }
        printf("\n");
    }

}

int main(){
        
   unsigned char m[8] = {
        0xE7, // 11100111
        0xE7, // 11100111
        0xE7, // 11100111
        0x7E, // 01111110
        0x3C, // 00111100
        0x3C, // 00111100
        0x7E, // 01111110
        0xFF  // 11111111
    };

    pinta(m);

}