#include <stdio.h>

// NOTICE WE USE '0', 'A' NOTATTION!!

int main(){

    char myChar;

    printf("Enter a character: ");
    scanf("%c", &myChar);
        // printf("You entered: %c - %d - %X \n", myChar, myChar, myChar);

    if (myChar >= '0' && myChar <= '9')
        printf("'%c' is a DIGIT! \n", myChar);
    else if (myChar >= 'a' && myChar <= 'z')
        printf("'%c' is a Lowercase letter! \n", myChar);
    else if (myChar >= 'A' && myChar <= 'Z')
        printf("'%c' is an Uppercase letter! \n", myChar);
    else printf("'%c' is neither a Digit, \
    a Lowercase or an Uppercase Letter! \n", myChar);

    return 0;
}