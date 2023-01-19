/*
    4. Milestone #1 -- CUSTOM

*/

#include <stdio.h>

int main(){

    int numGrades, tempNumGrades;
    int i=1;
    double gradeN;
    double average;

    printf("Number of grades: ");
    scanf("%d", &numGrades);
    

    tempNumGrades = numGrades;

    while (tempNumGrades > 0){
        printf("Enter grade n.%d: ", i);
        scanf("%lf", &gradeN);
        
        i++;
        average = (gradeN + average);
        tempNumGrades--;
    }

    average = average / numGrades;
    printf("\nYour average = %.2lf \n", average);

    return 0;
}

