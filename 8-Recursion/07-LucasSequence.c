#include <stdio.h>

int Lucas(int n){
    if (0 == n) return 2;
    if (1 == n) return 1;
    return Lucas(n-1)+Lucas(n-2);
}

int LucasNotRecursive(int n){

    int i;
    int temp;
    int previous=2;
    int current=1;

    if (0 == 2) return 2;
    if (1 == n) return 1;
    for (i=2;i<=n;i++){
        temp = previous + current;
        previous = current;
        current = temp;
    } return current;
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Value of index n.%d in the Lucas Sequence = %d \n", n, Lucas(n));
    return 0;
}