/*
    j = last num
    k = new num
    if at any time k > j, veryAscending will equal 0
*/

#include <stdio.h>

int main(){

    int size;
    int i, j=1, k;
    int VeryAscending=1;
    // char VeryAscending='T';
    
    printf("Enter 'size' of sequence: ");
    scanf("%d", &size);

    if (size<=0)
        printf("Please, try again.\n");
        
    else{

        printf("Enter sequence: ");

        for (i=1; i<=size; i++){
            j=k;
            scanf("%d", &k);
            if (k<=j)
            VeryAscending=0;
            //VeryAscending='F';
        }

        // printf("Very ascending [T/F]: %c \n", VeryAscending);
        if (VeryAscending)
            printf("Very Ascending sequence \n");
        else
            printf("NOT Very Ascending! \n");

    }

    return 0;
}