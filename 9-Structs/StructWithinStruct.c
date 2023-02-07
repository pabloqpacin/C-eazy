#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

typedef struct circle{
    Point center;
    double radius;
}Circle;


int main(){

    Point p1 = {3,5};
    Circle c1;
    Circle c2 = {2,6,8.8};

    c1.radius = 4.4;
    c1.center = p1;

    printf("C1: center=(x=%d y=%d) radius=%.2f \n", \
    p1.x, p1.x, c1.radius);
    printf("C2: center=(x=%d y=%d) radius=%.2f \n", \
    c2.center.x, c2.center.y, c2.radius);

    return 0;
}