/* ASCII
- uppercase: A=65d // Z=90
- lowercase: a=97 // z=122
    - therefore (letter-A+a = letter+32)
    - (Run Bash command 'ascii -o' )
- Should 'toLower' be 'int' to return '-1'?
*/

#include <stdio.h>

char toUpper (char letter){
    if (letter >= 97 && letter <= 122)
        return letter - 32;
    return -1;
}

char toLower(char letter){
    if (letter >= 65 && letter <= 90)
        return letter + 32;
    return -1;
    // return 'F';
    // return (toUpper(letter));
}

int main(){
    char letter;
    printf("Enter a char: ");
    scanf("%c", &letter);
    printf("To Lower: %c \nTo Upper: %c \n\n", \
                toLower(letter), toUpper(letter));
    return 0;
}