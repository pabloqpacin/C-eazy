/*  Actual Fibonacci sequence
    F0=0
    F1=1
    Fn=F(n-1)+F(n-2)
        F2=F1+F0=1
        F3=F2+F1=2
        F4=F3+F2=3      
        F5=5
        F6=8
        F7=13
        F8=21
        F9=34
*/

#include <stdio.h>

int fibonacci(int n){
    if ((0 == n) || (1 == n)) return n;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
        printf("Enter INDEX: ");
        scanf("%d", &n);
    
    printf("Fibonacci-seq. VALUE at index n.%d = %d \n\n", n, fibonacci(n));
    return 0;
}


