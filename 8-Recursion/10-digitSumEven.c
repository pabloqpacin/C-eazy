#include <stdio.h>

int actualSum(int n){
    if (9 >= n ) return n;
    return n%10 + actualSum(n/10);
}

int evenSum(int n){
    int sum;
    if (9 >= n) sum = n;
    sum = n%10 + actualSum(n/10);
    if (0 == sum%2) return 1;
    if (0 != sum%2) return 0;
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);   
    printf("- Sum = %d \n", actualSum(n));

    if (evenSum(n))
        printf("- Sum is EVEN! \n");
    else printf("- Sum is ODD! \n");

    return 0;
}

/*
    fun(5) = 5
    fun(156) = 6 + fun(15) = 6 + 5 + fun(1)
*/