#include <stdio.h>

int main(){

    char myChar1 = 'a';
    printf("Select a character: ");
    scanf("%c", &myChar1);
        // what if we scan for %X or alike...

    printf("- Character: %c \n", myChar1);
    printf("- Decimal ASCII Code: %d \n", myChar1);
    printf("- Hexadecimal ASCII Code: %X \n\n", myChar1);
        // And the binary?

    return 0;
}