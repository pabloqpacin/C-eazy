#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int random_number;
    srand(time(NULL)); // Seed the random number generator with the current time
    random_number = rand() % 20 + 1; // Generate a random number between 1 and 20
    printf("Random number between 1 and 20: %d\n", random_number);
    return 0;
}