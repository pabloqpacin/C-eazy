/*
    Section 6: Arrays; Milestone #1: Weather Station
    - Modular apprach; every statistic has its own function
    - Variables 'Day' and 'Temp' in functions stand for either
        - Day = index
        - Temp = value
    - TODO: allow for multiple days with max values.
    - TODO: WHY must hotDay=1 & coldDay=1 ??? (otherwise no workie-workie)
*/

#include <stdio.h>
#define SIZE 7


void highTemp(double weekTemps[SIZE]){
    int i, hotDay=1;
    double hotTemp=weekTemps[0];

    for (i=0;i<SIZE;i++){
        if (weekTemps[i] > hotTemp){
            hotTemp = weekTemps[i];
            hotDay = i+1;
        }
    }
    printf("Hottest Temp '%.2lf' = Day n.%d \n", hotTemp, hotDay);
}

void lowTemp(double weekTemps[SIZE]){
    int i, coldDay=1;
    double coldTemp=weekTemps[0];

    for (i=0;i<SIZE;i++){
        if (weekTemps[i] < coldTemp){
            coldTemp = weekTemps[i];
            coldDay = i+1;
        }
    }
    printf("Coldest Temp '%.2lf' = Day n.%d \n", coldTemp, coldDay);
}

void avgTemp(double weekTemps[SIZE]){
    int i;
    double sumTemps;
    double avgTemp;

    for (i=0;i<SIZE;i++){
        sumTemps+=weekTemps[i];
    }

    avgTemp=sumTemps/SIZE;
    printf("Average Temp thru week = %.2lf \n", avgTemp);
}


int main(){

    double weekTemps[SIZE];
    int i;

    for (i=0;i<SIZE;i++){
        printf("Enter day n.%d temperature: ", i+1);
        scanf("%lf", &weekTemps[i]);
    }


    highTemp(weekTemps);
    lowTemp(weekTemps);
    avgTemp(weekTemps);

    return 0;
}
