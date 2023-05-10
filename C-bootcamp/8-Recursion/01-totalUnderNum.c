#include <stdio.h>

int totalUnderNum(int num){
    int seq;
        printf("New number in sequence (-1 to end): ");
        scanf("%d", &seq);
    if (seq == -1)
        return 0;
    if (seq < num)
        return 1 + totalUnderNum(num);
    return totalUnderNum(num);
}

int main(){
    
    int num;
        printf("Enter 'num' to verify smaller values: ");
        scanf("%d", &num);

    printf("Total of numbers in sequence smaller than num '%d' = %d \n\n", num, totalUnderNum(num));

    return 0;
}