/*
    - Write a program that initializes an array of lowercase,
    uppercase and space character { a-z | A-Z | ' ' }
    - Using 'Counting Array' and 'Appropiate Mapping',
    find which letter appears the most in the 'Source Array'.
    - Also, print its value and the number of its appearances!
*/

/* ASCII
    ' ' = 32    // we don't care
    'A' = 65
    'Z' = 90
    'a' = 97
    'z' = 122
*/


#include <stdio.h>
#define SIZE 8
#define VALUES 52

int main(){

    char arr[8] = {'K','O','c','R','C',' ','K','r'};
    int countArr[VALUES];   // 0-25=a-z, 26-51=A-Z;
    int i, maxIndex;


    for (i=0; i<SIZE; i++){
        if (arr[i] >= 'a' && arr[i] <= 'z')
            countArr[arr[i] - 'a']++;
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            countArr[arr[i] - 'A' + 26]++;
    }


    for (i=0; i<VALUES; i++)
        if (countArr[i] > countArr[maxIndex])
            maxIndex = i;


    if (maxIndex < 26)
        printf("Letter %c appeared the most (%d times) \n", maxIndex + 'a', countArr[maxIndex]);
    else printf("Letter %c appeared the most (%d times) \n", maxIndex + 'A' - 26, countArr[maxIndex]);

    return 0;
}