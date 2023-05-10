/*  RECURSIONS:
    'printNto1': prints n and calls itself(n-1) until n=0
    'print1toN': now it calls itself(n-1) until n=0, then it will print "outwards"
        from the last recursion to the first!
*/

#include <stdio.h>

void printNto1(int n){
    if (n >= 1){
        printf("%d ", n);
        printNto1(n - 1);
    } 
}

void print1toN(int n){
    if (n >= 1){
        print1toN(n - 1);
        printf("%d ", n);
    } 
}

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("All the values from %d to 1 are: \n", n);
        printNto1(n);
    printf("\nAll the values from 1 to %d are: \n", n);
        print1toN(n);
    
    printf("\n");
    return 0;
}