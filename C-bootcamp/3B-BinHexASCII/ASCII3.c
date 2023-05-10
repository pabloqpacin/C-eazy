#include <stdio.h>

int main(){

    int day, month, year;

    printf("Enter DATE [day-month-year]: ");
    scanf("%d%d%d", &day, &month, &year);
    
    printf("Your date in HEX will be: (0x) %X-%X-%X \n", day, month, year);

    return 0;
}