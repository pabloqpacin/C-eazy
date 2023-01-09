/* Milestone #1: First Calculator

Write a program that will print on the screen the
results of 5 mathematical operations:

    Addition (+)
    Substraction (-)
    Multiplication (*)
    Division (/)
    Remainder (%)

(Stick to the integers '5' & '2')
*/

#include <stdio.h>

int main()
{

    printf(" %d + %d = %d = %.2d \n\n", 5, 2, 5+2, 7);
    printf(" %d - %d = %d = %.2d \n\n", 5, 2, 5-2, 3);
    printf(" %d * %d = %d = %.2d \n\n", 5, 2, 5*2, 10);

    /* notice '5/2' equals integer '2'
    as per correction, we take the FULL part of the division */
    printf(" %d - %d = %d = %.3f \n\n", 5, 2, 5/2, 2.5);
    printf(" %d %% %d = %d \n\n", 5, 2, 5%2);

    return 0;
}
