#include <stdio.h>

int main(){

    double num1, num2, result;
    char sign;

    printf("Enter the two numbers: \n");
    scanf("%lf", &num1);
    scanf("%lf", &num2);
    printf("Operation sign: \n");
    scanf("%c", &sign);
    scanf("%c", &sign);
    // why does my program need two lines?
        // one only gets skipped

    switch (sign){
        case '+':
            result = num1 + num2; break;
        case '-':
            result = num1 - num2; break;
        case '*':
            result = num1 * num2; break;
        case '/':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");
            result = num1 / num2; break;
        case '%':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");

            result = (int)num1 % (int)num2; break;
        default:
            printf("Operation not accepted. Please try again. \n"); break;
    }

    // if (result==True) // how to denote results are ok thus operation completed
    printf("%.1lf %c %.1lf = %.2lf \n\n", num1, sign, num2, result);

    return 0;
}