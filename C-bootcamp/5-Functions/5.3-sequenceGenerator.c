/*
    mind variables
        - 'int' [%d] allows for 9 digits (lenght=9)
        - 'double' [%lf] for 15 
        - 'long' [%ld] for 18
        - TODO: '...' [%Ld] for ...
*/


#include <stdio.h>

long sequenceGenerator(int lenght){
    long sequence;
    int i;
    for (i=1;i<=lenght;i++){
        if (lenght<=9)
            sequence=(sequence*10)+i;
        else 
        sequence=(sequence*10)+9;
    }    
    return sequence;
}

int main(){
    int lenght;
    printf("Enter lenght of sequence: ");
    scanf("%d", &lenght);
    printf("%ld \n", sequenceGenerator(lenght));
    return 0;
}