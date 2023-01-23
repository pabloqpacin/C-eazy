#include <stdio.h>

int main(){

    /* Good Neighbors x2 = {2,6,3,9,3}; */
    int door[5];
    int i;
    int hasGoodNeighbors;

    printf("Enter five integers: \n");

    for (i=0; i<5; i++){
        printf("Int %d: ", i+1);
        scanf("%d", &door[i]);
    }

    // awkward sums to demonstrate how 1st and last iteration shouldn't be accounted for
    for (i=0+1; i<5-1; i++){
        if (door[i]==door[i-1]*door[i+1]){
            hasGoodNeighbors += 1;
            printf("Yay! i%d (%d) has Good Neighbors (%d*%d) \n", i, door[i], door[i-1], door[i+1]);
            // return 0; --- if I wanted to STOP iterating!
        }
    }

    if (hasGoodNeighbors)
        printf("Congrats dawg yer arr had gud niebors! \n");
    else printf("Sux dawg, da arr didnt have no gud niebors! \n");

    return 0;
}
