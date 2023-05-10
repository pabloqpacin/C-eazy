/*  TO-DO
    - read string from user
    - check if string is palindrome <!--either Even or Odd-->
    - example
        - string: n-o-o-n-\0
        - index(n): 0-1-2-3-4
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100


int main(){

    char str[SIZE];
    int isPalindrome=1;
    int i, j;

    puts("Enter your string dawg: ");
    fgets(str, SIZE, stdin);
        printf("String = %s", str);

    j = strlen(str)-2;
    printf("strlen before NULL = %lu (j=%d) \n", strlen(str)-2, j);

    for (i=0; i<=strlen(str)-2;i++){
        printf("  i=%d - str[i]=%c \n", i, str[i]);
        printf("  j=%d - str[j]=%c \n", j, str[j]);
        if (str[i] != str[j]){
            isPalindrome=0;
            break;
        }
        j--;
    }

    if (isPalindrome)
        puts("String is Palindrome!");
    else
        puts("String is NOT Palindrome");

    return 0;
}