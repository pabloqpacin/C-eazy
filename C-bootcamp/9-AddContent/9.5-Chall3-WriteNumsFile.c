#include <stdio.h>

int main(){

    FILE* fp;
    int i;

    fp = fopen("supdawg.md","w");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for WRITING-- \n");
        for (i=1; i<=10; i++)
            fprintf(fp, "%d %d \n", i, i*i);

        fclose(fp);
    } 

    return 0;
}
