#include <stdio.h>

int findMax(int num){

    int seq, max;
    printf("Enter new number: ");
    scanf("%d", &seq);

    if (1 < num){
        max = findMax(num-1);
        if (seq > max) return seq;
        else return max;
    }
}

int main(){
    int num;
    printf("Enter length of sequence: ");
    scanf("%d", &num);
    printf("Max value in sequence = %d \n", findMax(num));
    return 0;
}


/*  prototype

int findMaxValue(int num){

    int seq, max;
    
    printf("Enter new number: ");
    scanf("%d", &seq);
    if (seq > max) max = seq;
    printf("- seq = %d \n", seq);
    printf("- max = %d \n", max);
    
    if (1 == num) return max;

    return findMaxValue(num-1);
}
*/