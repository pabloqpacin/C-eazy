/* NOTE
    Filename == "aptShowGcc.log"
    'Assume file is in the same workspace as src-code,
    so we don't need to specify PATH!
*/

/* TROUBLESHOOTING
    - 'scanf("%s", filename);'
    - 'scanf(" %c", &charSearch);' 
    Mind lack of '&' and ' ' respectively!
*/

#include <stdio.h>

int main(){

    FILE* fp;
    char filename[40] = {0};
    char charSearch;
    int charNum;

    // User input
    puts("This program will search a character in a file and print its number of appearances");
    printf("Enter filename: ");     // Extension, PATH...
    scanf("%s", filename);
    printf("Enter character: ");
    scanf(" %c", &charSearch);

    // Retrieve file data
    fp = fopen(filename, "r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        
        while (!feof(fp))
            if (fgetc(fp) == charSearch)
                charNum++;

        fclose(fp);
    } 

    printf("Char '%c' appeared '%d' times in file '%s' \n\n", charSearch, charNum, filename);

    return 0;
}
