/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int hex2dec(char hex[9]){
    int i, num = 0, m = 1;
    for(i=strlen(hex)-1; i>=0; i--){
        if(hex[i] >= '0' && hex[i]<='9'){
            num = num + (hex[i] - '0') * m;    
        }
        else{
            num = num + ((toupper(hex[i])-55)*m);
        }
        m*=16;
        
    }
    return num;
}
int main()
{
    char hex[9] = "Caf8";
    
    printf("Decimal: %d\n", hex2dec(hex));
    
    return 0;
}