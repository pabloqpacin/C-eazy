#include <stdio.h>

int main(){

    int a=5, b=7;
    int *ptrA=&a, *ptrB=&b;

    printf("a = %d \n", a);     // 5
    printf("b = %d \n", b);     // 7

    *ptrA = *ptrA + 1;      // == a+=1 !!
    *ptrB =*ptrB + 3;       // == b+=3 !!
        /* SEGMENTATION FAULT
        *ptrB = &b + 3;  == SEGMENTATION FAULT!!
        ptrB = &b + 3; == STILL 7!! // WRONG ARITHMETIC    */
    
    printf("a = %d \n", a);     // 6
    printf("b = %d \n", b);     // 10

    ptrA = ptrB;        // ptrA -> b, ptrB -> b
    ptrB = ptrA;        // ptrB -> b, ptrA -> b
    /* MEANING: a has NO pointer, b has 2 POINTERS */

    printf("a=%d, b=%d \n", a, b);                  // 6, 10
    printf("*ptrA=%d, *ptrB=%d \n", *ptrA, *ptrB);  // 10, 10

    a = *ptrB;      // 10
    b = a - 3;      // 7
    /* MEANING: a = (b) thru pointer; b = b-3 which was original b LMAO */

    printf("a=%d, b=%d \n", a, b);      // 10, 7

    return 0;
}