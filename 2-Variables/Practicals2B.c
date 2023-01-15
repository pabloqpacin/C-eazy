#include <stdio.h>


int main(){

    // 4. Finding a Driving Time...
    int distance, speed;
        printf("Enter distance [km]: ");
        scanf("%d", &distance);  
        printf("Enter speed [km/h]: ");
        scanf("%d", &speed);

    double speedInMinutes = speed / 60.0;
    int hours = distance / speed;
    int remainingMinutes = (distance % speed) / speedInMinutes;

    printf("The time from A to B will take %d hours and %d minutes \n\n", hours, remainingMinutes);


    // 5. Convert Seconds Into Hours, Minutes and Seconds
    int totalSeconds;
    printf("Enter the number of seconds: ");
    scanf("%d", &totalSeconds);

    int totalHours = totalSeconds/3600;
    int totalMinutes = (totalSeconds-(totalHours*3600))/60;
    int remainingSeconds = (totalSeconds-(totalHours*3600)) % 60;

    printf("Conversion: %.2d:%.2d:%.2d \n\n", totalHours, totalMinutes, remainingSeconds);


    // 6. Removing Decimal Part from an Integer
    float data;
    printf("Enter a decimal number: ");
    scanf("%f", &data);

    float dataDecimal = data - (int)data;
    printf("This is the decimal part of your number: %.3f \n", dataDecimal);
    printf("This is your number without its decimals: %d \n", (int)data);


    return 0;

}