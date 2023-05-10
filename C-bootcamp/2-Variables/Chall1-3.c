#include <stdio.h>

int main(){
    
    // Chall. #1 - Find your Year of Birth!
    int currentYear;
    int yourAge;
    int yearBirth;

    printf("Current year: ");
    scanf("%d", &currentYear);
    printf("Your age: ");
    scanf("%d", &yourAge);
    yearBirth = currentYear - yourAge;
    
    printf("You were born in %d \n\n", yearBirth);
        // Still needing "months" correction!
    

    // Chall. #2 - Calculate rectangle's area! ('%lf')
    double height, width;
    double area;

    printf("Enter height: ");
    scanf("%lf", &height);
    printf("Enter width: ");
    scanf("%lf", &width);

    area = height*width;
    printf("The rectangle's area is %.3lf \n\n", area);


    // Chall. #3 - Calculate Your Average Grade!
    int grade1, grade2, grade3;
    double average;
    printf("Enter your 3 grades to calculate their average \n");

    printf("Grade 1: ");
    scanf("%d", &grade1);
    printf("Grade 2: ");
    scanf("%d", &grade2);
    printf("Grade 3: ");
    scanf("%d", &grade3);

    // ALT: average = ((double)grade1+grade2+grade3)/3;
    average = (grade1+grade2+grade3)/3.0;
    printf("Your average grade is %.2lf \n\n", average);

    return 0;

}