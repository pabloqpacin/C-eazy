#include <stdio.h>

int main(){
    char myChar1 = 'a';
    char myChar2 = 97;
    char myChar3 = 0x61;

    printf("'Char1' == %c, %d, %X\n", myChar1, myChar1, myChar1);
    printf("'Char2' == %c, %d, %X\n", myChar2, myChar2, myChar2);
    printf("'Char3' == %c, %d, %X\n", myChar3, myChar3, myChar3);

    return 0;
}