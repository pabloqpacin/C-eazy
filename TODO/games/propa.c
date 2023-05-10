#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("Let's play a GAME! You win if...\n your_number * adversary's * dice = yours * dice + advesary's * dice\n\n");
    int x;
    int y;
    int z; // random_number
    srand(time(NULL)); // Seed the random number generator with the current time
    printf("- Choose your number (1-10): ");
    scanf("%d", &x);
    y = rand() % 10 + 1; // Generate a random number between 1 and 10
    z = rand() % 20 + 1; // Generate a random number between 1 and 20
    // printf("Your number is: %d\n", x);
    printf("- Your adversary's number is: %d\n", y);
    printf("- Random dice number between 1 and 20: %d\n\n", z);

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