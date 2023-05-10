/*
    @TWT Challenge — 2023-04-03

    You are playing a number game with SnowballSH. SnowballSH picks one integer, x. You need to pick an integer, y. SnowballSH then rolls a fair n-sided die, labelled 1, 2, ..., n, and obtains the number z.

    You win the game if the following statement is true:
    xyz = xz + yz
    Otherwise, SnowballSH wins.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Let's play a GAME! You win if...\n (yourNumber * adversary's * randomDiceroll) = (yourNumber * randomDiceroll) + (advesary's * randomDiceroll)\n\n");
    
    int x;
    int y;
    int z;
    
    printf("- Choose your number (1-10): ");
    scanf("%d", &x);
    srand(time(NULL)); // Seed the random number generator with the current time
    y = rand() % 10 + 1; // Generate a random number between 1 and 10
    z = rand() % 20 + 1; // Generate a random number between 1 and 20
    // printf("Your number is: %d\n", x);
    printf("- Your adversary's number is: %d\n", y);
    printf("- Random diceroll between 1 and 20: %d\n\n", z);

    int result = (x*y*z == x*z + y*z);
    printf("[yours * adversary's * dice = %d]\n", x*y*z);
    printf("[yours * dice + adversary's * dice = %d]\n\n", x*z + y*z);
    // printf("Result = %d\n", result);

    if (result)
        printf("You WIN!\n");
    else
        printf("You LOSE!\n\n");

    // if (result)
    //     printf("You WIN! \t %d*%d*%d == %d*%d + %d*%d\n", x,y,z,x,z,y,z);
    // else
    //     printf("You LOSE! \t %d*%d*%d != %d*%d + %d*%d\n", x,y,z,x,z,y,z);

    return 0;
}