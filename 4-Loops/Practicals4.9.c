#include <stdio.h>

int main(){

    int num;
    int evenSum, oddSum;
    int digit;

    printf("Enter num: ");
    scanf("%d", &num);

    while (num>0){
        digit=num%10;
        if (digit%2==0)
            evenSum+=digit;
        else
            oddSum+=digit;
        num/=10;
    }

    printf("EVEN minus ODD digits = %d \n", evenSum-oddSum);

    return 0;
}