#include <stdio.h>
#define SIZE 10

int main(){

    int i, j;
    int foundDuplicate;
    int values[SIZE];
    int uniqueCount;

    for (i=0; i<SIZE; i++){
        printf("Enter n.%d/%d: ", i+1, SIZE);
        scanf("%d", &values[i]);
    }

    printf("\nUnique Values: ");

    for (i=0; i<SIZE; i++){

        for (j=0; j<SIZE; j++){
            if (i == j)
                continue;
            if (values[i] == values[j]){
                foundDuplicate=1;
                break;
            }
        }
        if (foundDuplicate!=1){
            printf("%d ", values[i]);
            uniqueCount++;
        }
        foundDuplicate=0;
    }

    printf("\nTotal Unique Nums: %d \n",uniqueCount);

    return(0);
}