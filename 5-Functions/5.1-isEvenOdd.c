#include <stdio.h>

int isEven(int n){
    if (n%2==0)
        return 1;
    return 0;
}

int isOdd(int n){
    if (isEven(n))
        return 0;
    return 1;
}


int main(){
    int n;
    printf("Enter num: ");
    scanf("%d", &n);
    if (isEven(n))
        printf("%d is even \n", n);
    else if (isOdd(n))
        printf("%d is odd \n", n);
    return 0;
}