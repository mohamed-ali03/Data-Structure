#include <stdio.h>

int main(void){
    int array[11] = {1,2,3,5,2,5,7,6,1,3,6};
    int i ;
    int res = 0 ;
    for(i = 0 ; i <11 ;i++){
        res ^= array[i];
    }
    printf("Non Repeated Value is %i\n",res);

    return 0 ;
}