#include <stdio.h>

typedef struct date{
    int day;
    int month;
    int year;
}Date;

void printDate(Date dt){
    printf("Date = %d-%d-%d \n\n", dt.year, dt.month, dt.day);
}

Date inputDate(){
    Date dt;
    printf("- Enter day: ");
    scanf("%d", &dt.day);
    printf("- Enter month: ");
    scanf("%d", &dt.month);
    printf("- Enter year: ");
    scanf("%d", &dt.year);
    return dt;
}

int main(){
    Date birthday, today;
    puts("When's your birthday?");
    birthday = inputDate();
    printDate(birthday);
    puts("Today is ...?");
    today = inputDate();
    printDate(today);
    return 0;
}