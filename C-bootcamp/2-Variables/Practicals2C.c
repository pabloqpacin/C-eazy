#include <stdio.h>

int main(){

    // 7. Sum of Triple Digits
    int userNumber;
        printf("Enter a 3-digit number: ");
        scanf("%d", &userNumber);

    int units = userNumber % 10;
    int tens = (userNumber/10) % 10;
    int hundreds = userNumber / 100;

    int sumDigits = units+tens+hundreds;
    printf("The sum of the given digits is: %d \n\n", sumDigits);


    // 8. Print Reversed Number
    int userNum;
        printf("Enter a 3-digit number: ");
        scanf("%d", &userNum);

    int un = userNum % 10;
    int ten = (userNum/10) % 10;
    int hun = userNum / 100;

    int reversedNum = un*100 + ten*10 + hun;

    printf("The reversed number is: %d \n\n", reversedNum);
    // printf("The reversed number is: %d%d%d \n\n", un, ten, hun);


    return 0;
}