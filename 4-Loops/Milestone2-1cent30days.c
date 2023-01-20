/* 
    Milestone #2 - 1 Cent VS 1 Million Dollars!!

    What is better?
    a) 1 Million dollars, right now
    b) 1 cent, doubles every day for 30 days

*/

#include <stdio.h>

int main(){

    int i;
    double total=0.01;

    for (i=1;i<=30;i++){
        printf("Day %.2d = %.2lf $ \n", i, total);
        total*=2;
    }

    return 0;
}