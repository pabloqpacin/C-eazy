/*
    EXAMPLE
    - sumOfDigits(213) = 3 + sumOfDigits(21) = 3 + 1 + sumOfDigits(2)
*/

#include <stdio.h>

int totalDigits(int num){
    if (num<=9)
        return 1;
    return 1 + totalDigits(num/10);
}

int main(){
    int num;
        printf("Enter num: ");
        scanf("%d", &num);   
    printf("Number of Digits in '%d' = %d \n\n", num, totalDigits(num));
    return 0;
}