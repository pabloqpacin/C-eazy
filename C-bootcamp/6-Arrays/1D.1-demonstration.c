#include <stdio.h>


int main(){

    int grades[5];
    int i;
    int lowest_grade;


    for (i=0; i<5; i++){
        printf("Enter grade no. %.2d: ", i+1);
        scanf("%d", &grades[i]);
    }


    lowest_grade = grades[0];       // A Must step...

    for (i=1; i<5; i++){
        if (grades[i] < lowest_grade)
            lowest_grade = grades[i];
    }


    printf("Your lowest grade is: %d \n", lowest_grade);
    
    for (i=0; i<5; i++){
        printf("grades[%d] = %d \n", i, grades[i]);
    }
    
    return 0;

}