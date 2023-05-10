#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

    // 9. Distance Between 2 Points
    double x1,y1,x2,y2;
    double squareX, squareY;
        double distance;

    printf("Enter X1: ");
    scanf("%lf", &x1);

    printf("Enter Y1: ");
    scanf("%lf", &y1);

    printf("Enter X2: ");
    scanf("%lf", &x2);

    printf("Enter Y2: ");
    scanf("%lf", &y2);

    squareX = pow((x1-x2), 2);
    squareY = pow((y1-y2), 2);

    // distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    distance = sqrt(squareX + squareY);
    printf("The Distance between the points (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf \n\n", x1,y1,x2,y2,distance);


    // 10. Efficient Calculation Example
    int numberX;
    int power2, power4, power6, power8;

    printf("Enter your number: ");
    scanf("%d", &numberX);
  
    power2 = pow(numberX, 2);
    power4 = pow(numberX, 4);
    power6 = pow(numberX, 6);
    power8 = pow(numberX, 8);
    
    printf("%d to the power of 2 is: %d \n", numberX, power2);
    printf("%d to the power of 4 is: %d \n", numberX, power4);
    printf("%d to the power of 6 is: %d \n", numberX, power6);
    printf("%d to the power of 8 is: %d \n\n", numberX, power8);

    return 0;
}


/* TODO
int numberX, numberY;
int powerNumber;

printf("Enter the X number of [x^y]: ");
scanf("%d", &numberX);

printf("Enter the Y number of [x^y]: ");
scanf("%d", &numberY);

powerNumber = pow(numberX, numberY);
    printf("%d to the power of %d is: %d \n\n", numberX, numberY, powerNumber);*/