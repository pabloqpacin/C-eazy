/* 
    Chall. #6a - Print Right Angle Triangle Pattern
    6A. n=3   // 6B. n=3
    1           // 1
    12          // 22
    123         // 333
*/

#include <stdio.h>

int main(){

    int i, j;
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        for(j=1; j<=i; j++)
            printf("%d", j);        // 6A
            // printf("%d", i);     // 6B
        printf("\n");
    }


    return 0;
}