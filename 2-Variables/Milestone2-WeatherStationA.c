#include <stdio.h>

int main(){

    /* 1. Formula for Celsius into Fahrenheit conversion T(F)=T(C)*1.8+32 */
    double ctemp, ctof;
    printf("Enter the temperature in Celsius degrees: ");
    scanf("%lf", &ctemp);
    ctof = ctemp*1.8+32;
    printf("The temperature in Fahrenheit is %.2lf \n\n", ctof);

    /* 2. Formula for Fahrenheit into Celsius T(F)=T(C)*1.8+32 */  
    double ftemp, ftoc;
    printf("Enter the temperature in Fahrenheit degrees: ");
    scanf("%lf", &ftemp);   
    ftoc = (ftemp-32)/1.8;
    printf("The temperature in Celsius is %.2lf \n\n", ftoc);

    return 0;
    
}