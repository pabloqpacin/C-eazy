#include <stdio.h>

// ASCII5.c
// HEX to BIN conversion (not ASCII related)
// NOTICE '0', '7'... NOT 0, 7

int main(){

    char myChar;
    printf("Enter a HEX Digit dawg [0-F]: ");
    scanf("%c", &myChar);

    switch(myChar){
        case '0': printf("0x%c == 0000 \n", myChar); break;
        case '1': printf("0x%c == 0001 \n", myChar); break;
        case '2': printf("0x%c == 0010 \n", myChar); break;
        case '3': printf("0x%c == 0011 \n", myChar); break;
        case '4': printf("0x%c == 0100 \n", myChar); break;
        case '5': printf("0x%c == 0101 \n", myChar); break;
        case '6': printf("0x%c == 0110 \n", myChar); break;
        case '7': printf("0x%c == 0111 \n", myChar); break;
        case '8': printf("0x%c == 1000 \n", myChar); break;
        case '9': printf("0x%c == 1001 \n", myChar); break;
        case 'A': printf("0x%c == 1010 \n", myChar); break;
        case 'B': printf("0x%c == 1011 \n", myChar); break;
        case 'C': printf("0x%c == 1100 \n", myChar); break;
        case 'D': printf("0x%c == 1101 \n", myChar); break;
        case 'E': printf("0x%c == 1110 \n", myChar); break;
        case 'F': printf("0x%c == 1111 \n", myChar); break;
        default: printf("Please try again dawg..."); break;
    }

    return 0;
}