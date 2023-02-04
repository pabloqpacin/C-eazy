/*  Eazy Digits
        int digit1, digit2, digit3, sum;
            digit1=num%10;
            digit2=num/10%10;
            digit3=num/100%10;
        sum = digit1+digit2+digit3;
        printf("%d --> %d + %d + %d = %d \n", num, digit1, digit2, digit3, sum);
*/

#include <stdio.h>

int sumDigitsNum(int num){
    if (num==0)
        return 0;
    /*
        if (num<=9)
            return num; ---> by @Vlad
    */
    return num%10 + sumDigitsNum(num/10);
}

int main(){
    int num;
        printf("Enter num: ");
        scanf("%d", &num);   
    printf("Sum of Digits in '%d' = %d \n\n", num, sumDigitsNum(num));
    return 0;
}