#include <stdio.h>

void findMinMax(int a, int b, int *pMax, int *pMin){

    if (a > b){
        *pMax = a;  // modify values directly on their address
        *pMin = b;
    } else {
        *pMax = b;
        *pMin = a;
    }   // No need for any return
}

int main(){
    int a=5, b=7;
    int max, min;
    // int *pMax, *pMin; -- DON'T!

    findMinMax(a,b, &max, &min);    // send address of vars
    printf("For %d and %d, \n- MAX = %d \n- MIN = %d \n", a, b, max, min);
        // fetch value directly from addresses!

    return 0;
}