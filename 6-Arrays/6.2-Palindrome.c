#include <stdio.h>
#define SIZE 5

int main(){

    int arr[SIZE]={3,4,7,5,3};
    int i;
    int isPalindrome;
    int currentVal, matchingVal;    // innecessary, added for clarity

    for (i=0; i<SIZE/2; i++){

        currentVal = arr[i];
        matchingVal = arr[SIZE-(i+1)];
        printf("Current val = %d \n", currentVal);
        printf("Matching val = %d \n", matchingVal);

        if (currentVal==matchingVal){
            isPalindrome = 1;
        } else {
            isPalindrome = 0;
            break;
        }
    }

    printf("\nPalindrome candidate: ");
    for (i=0; i<SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    if (isPalindrome)
        printf("  SUCCESS! That is a Palindrome indeed! \n");
    else printf("  FAIL! Not a Palindrome because %d and %d fail to match! \n", currentVal, matchingVal);

    return 0;
}
