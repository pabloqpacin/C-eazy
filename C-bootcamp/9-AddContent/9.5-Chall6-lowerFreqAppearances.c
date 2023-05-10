#include <stdio.h>
#define VALUES 26

int main(){

    FILE* fp;
    char filename[40] = {0};
    int frequencyAppearances[VALUES] = {0}; // 0-a 1-b ... 25-z
    char currentChar;
    int i;
    
    printf("Enter filename: ");     // Extension, PATH...
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        
        while ((currentChar = fgetc(fp)) != EOF)
            if (currentChar >= 'a' && currentChar <= 'z')
                frequencyAppearances[currentChar-'a']++;

        fclose(fp);
    } 

    puts("Alphabetical order");
    for (i=0; i<VALUES; i++)
        printf("Letter '%c' appeared '%d' times \n", i+'a', frequencyAppearances[i]);

    // puts("Frequency order");

    return 0;
}
