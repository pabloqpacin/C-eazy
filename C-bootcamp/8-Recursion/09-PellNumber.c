#include <stdio.h>

int pellValue(int n){
    if ((0 == n) || (1 == n)) return n;
    return 2 * pellValue(n-1) + pellValue(n-2);
}

int pellNotRecursive(int n){
    int previous, current=1, next, i;
    if ((0 == n) || (1 == n)) return n;
    for (i=2; i<=n; i++){
        next = 2 * current + previous;
        previous = current;
        current = next;
    } return current;
}

int main(){
    int n;
    printf("Enter Pell sequence index: ");
    scanf("%d", &n);
    printf("Value of Pell number(%d) = %d \n", n, pellValue(n));

    printf("Not recursive result: %d \n", pellNotRecursive(n));
    return 0;
}