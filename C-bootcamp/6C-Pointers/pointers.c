#include <stdio.h>

int main(){

    int myInt1=12;
    int myInt2=21;
    float myFloat1=1.2;
    float myFloat2=2.1;
    double myDouble1=12.3;
    double myDouble2=32.1;
    char myChar1='a';
    char myChar2='z';


    printf("%p \n", &myInt1);
    printf("%p \n", &myInt2);
    printf("%p \n", &myFloat1);
    printf("%p \n", &myFloat2);
    printf("%p \n", &myDouble1);
    printf("%p \n", &myDouble2);
    printf("%p \n", &myChar1);
    printf("%p \n", &myChar2);

    return 0;

}