#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x;

    int y;
    int z; // random_number
    srand(time(NULL)); // Seed the random number generator with the current time
    printf("Choose your number [1-10]: ");
    scanf("%d", &x);
    y = rand() % 10 + 1; // Generate a random number between 1 and 20
    z = rand() % 20 + 1; // Generate a random number between 1 and 20
    printf("Your number is: %d\n", x);
    printf("Your adversary's number is: %d\n", y);
    printf("Random number between 1 and 20: %d\n", z);
    return 0;
}