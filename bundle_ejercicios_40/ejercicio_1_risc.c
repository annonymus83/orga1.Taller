#include <stdio.h>
#include <stdint.h>

#define N 12

int main ()
{
    int32_t arr[N] = {
        0xffffffff , 0x95555555 , 0xf4444444 , 0xf1111111 ,
        0xffffff00 , 0xf5005555 , 0x95444444 , 0xf1113311 ,
        0xff00ffff , 0xf5550055 , 0xa4444433 , 0xa1551111
    };
    
    int32_t suma = 0xffffffff;
    int32_t i = 0;
    int32_t n = 12;
    for(i = 0; i <n ; i++){
        if( ( i & 0x1 ) == 0x1 )
            suma &= arr[ i ] ;
    }
    
    printf( "Suma %08x" , suma );
    
    return 0;

}

