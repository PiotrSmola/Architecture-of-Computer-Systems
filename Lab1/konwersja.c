#include<stdio.h>
#include<stdlib.h>

/*
 jak¹ maksymaln¹ liczbê binarn¹ mo¿na zapisaæ przy pomocy typu int?

UNIT_MAX =  4294967295
UBIN_MAX =  1111111111

- jaka jest wartoœæ dziesiêtna maksymalnej liczby binarnej, jak¹ mo¿na zapisaæ przy pomocy typu int?

            9876543210
UBIN_MAX =  1111111111 = 2^10 - 1 = 1023

*/

/*
11 / 2 = 5   r0 = 1
5 / 2 = 2    r1 = 1
2 / 2 = 1    r3 = 0
1 / 2 = 0    r4 = 1

11 = 1011 = 1*2^0 + 1*2^1 + 0*2^2 + 1*2^3  
*/
int dex2bin(int x){
    int sum = 0;
    int pow = 1;
    
    while (x > 0){
        
        sum = sum + x % 2 * pow;
        
        x /= 2;
        
        pow = pow * 10;
    }
    
    return sum;
}
int main(){
    printf("konwersja.c\n\n");
    
   int dec1 = 1023;
   
   printf("dec2bin(%u) = %u\n\n",dec1,dex2bin(dec1));
    
    return 0;
}
