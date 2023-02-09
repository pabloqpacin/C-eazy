/* NOTE:
    Change 'printf()' line within while-loop to '%c'
        only to print the text as it is.
    We leave '%d \n' to display the ASCII decimal values.
*/

#include <stdio.h>

int main(){

    FILE* fp;
    char fileChar;
    int numChars;


    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        while ((fileChar = fgetc(fp)) != EOF){
            printf("%c %d \n", fileChar, fileChar);
            numChars++;
        }

        fclose(fp);
    }

    printf("\nTotal num of chars = %d \n", numChars);
    return 0;
}
