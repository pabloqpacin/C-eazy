#include <stdio.h>
#define NUMDAYS 7

int main(){

    float temps[NUMDAYS];
    int i;
    float sum, avgTemp;
    int hotDay, coldDay;    // index
    float hotTemp, coldTemp;    // value

    for (i=0; i<NUMDAYS; i++){
        printf("Enter the temp at day %d: ", i+1);
        scanf("%f", &temps[i]);
    }

    coldTemp=temps[0];
    hotTemp=temps[0];

    for (i=0; i<NUMDAYS; i++){
        sum += temps[i];

        if (temps[hotDay] < temps[i]){
            hotDay = i;
            hotTemp = temps[i];
            continue;
        }
        else if (temps[coldDay] > temps[i]){
            coldDay = i;
            coldTemp = temps[i];
        }
    }

    avgTemp = sum/NUMDAYS;

    printf("The average temp = %f \n", avgTemp);
    printf("Hottest Day n. %d with Temp '%.2f' \n", hotDay+1, hotTemp);
    printf("Coldest Day n. %d with Temp '%.2f' \n", coldDay+1, coldTemp);

    return 0;
}