#include <stdio.h>
#define SIZE 11

int main(){

    int i, j;
    int matrix[SIZE][SIZE];

    // 1. Fill values to the table
    for (i=1; i<SIZE; i++)
        for (j=1; j<SIZE; j++)
            matrix[i][j] = i*j;
    
    // 2. Print the multiplication table!
    for (i=1; i<SIZE; i++){
        for (j=1; j<SIZE; j++)
            printf("%d " , matrix[i][j]);
        printf("\n");
    }

    return 0;
}
