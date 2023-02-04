#include <stdio.h>
#include <string.h>
#define SIZE 100

/*  
    Solution: number of spaces in string +1
    Need to know ASCII: space char (' ') is 32 in decimal!
*/


int main() {

    char str[SIZE];
    int nWords=1;
    int i=0;

    printf("Enter your string dawg: ");
    fgets(str,SIZE, stdin);

    for (i=0; i<strlen(str);i++){
        if (str[i]==32)
            nWords++;
    }

    printf("Number of words = %d \n", nWords);
    // printf("Number of characters = %lu \n", strlen(str));

    return 0;
}

