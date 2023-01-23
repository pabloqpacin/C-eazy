#include <stdio.h>
#define SIZE 5

int main(){

    int i, j;
    int values[SIZE];
    int nonUniqueCount;
    int foundDuplicate;

    for (i=0; i<SIZE; i++){
        printf("Enter num %d/%d: ", i+1, SIZE);
        scanf("%d", &values[i]);
    }

    printf("\nNon-Unique Values: ");
    for (i=0; i<SIZE; i++){
    
        foundDuplicate=0;

        for (j=0; j<i; j++){
            if (values[i] == values[j]){
                foundDuplicate = 1;
                break;
            }
        }
        if (foundDuplicate)
            break;
        else {
            for (j=i+1; j<SIZE; j++){
                if (values[i] == values[j]){
                    printf("%d ", values[i]);
                    nonUniqueCount++;
                    break;
                }
            }
        }
    }

    printf("\nTotal Non-Unique Values: %d \n", nonUniqueCount);

    return(0);
}
