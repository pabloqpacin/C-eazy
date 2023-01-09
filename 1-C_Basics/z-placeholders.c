#include <stdio.h>


int main(){
    
    printf("Year: %d \nWeek: %.2d \nDay: %c \n\n", 2023, 2, 'W');

    // (https://stackoverflow.com/questions/10947965/why-is-c-used-in-c)
    // Because %d will print the numeric character code of the char,
    printf("%d \n", 'a');       //prints 97 (on an ASCII system), while
    printf("%c \n\n", 'a');       // prints a.

    return 0;

}
