# 9. Structs

<details>
<summary>Table of Contents</summary>

- [9. Structs](#9-structs)
  - [Creating a Structure Template](#creating-a-structure-template)
  - [Structure Variables](#structure-variables)
  - [Challenge #1 - Initialize \& Print Date Variable (Struct)](#challenge-1---initialize--print-date-variable-struct)
  - [Typedef \& Structures](#typedef--structures)
  - [Chall.#2 - General FunctionZ to use Input \& Print of a struct](#chall2---general-functionz-to-use-input--print-of-a-struct)
  - [Chall.#3 - Find the Next Date](#chall3---find-the-next-date)
  - [Initializing a Struct in C (Variables)](#initializing-a-struct-in-c-variables)
  - [Chall.#4 - Input Point \& Print Point](#chall4---input-point--print-point)
  - [Static Array of Structs](#static-array-of-structs)
  - [Writing Associate Logical Functions](#writing-associate-logical-functions)
  - [Composing struct inside another struct](#composing-struct-inside-another-struct)
  - [Structs as the BASIS for more Advanced Topics](#structs-as-the-basis-for-more-advanced-topics)

</details>

## Creating a Structure Template

```c
struct <struct-name>{
    <type><field-name>;
    <type><field-name>;
    ...
    <type><field-name>;
};
```

<details>
<summary>More examples</summary>

```c
// Date struct
struct date{
    int day;
    int month;
    int year;
};

// Point struct
struct point{
    int x;
    int y;
};

// Address struct
struct address{
    char state[20];
    char city[10];
    char street[15];
    int number;
};
```

> It's like a big variable: a big box for small boxes

</details>

## Structure Variables

<details>
<summary>Explanation</summary>

Declaring a variable of some structure type

```c
struct <name> <variable>
struct date myDate1, myDate2;
```

Access to variable's fields (**dot-notation**)

```c
<variable>.<field>

myDate1.day = 6;
myDate1.month = 2;
myDate1.year = 2023;
scanf("%d", &myDate.month);
printf("%d", myDate.year);
```
</details>

## Challenge #1 - Initialize & Print Date Variable (Struct)

```c
#include <stdio.h>

struct point{
    int x;
    int y;
};

struct date{
    int day;
    int month;
    int year;
};

int main(){

    struct point p1;
        printf("Enter x coordinate: ");
        scanf("%d", &p1.x);
        printf("Enter y coordinate: ");
        scanf("%d", &p1.y);
    printf("The point is (%d,%d) \n", p1.x, p1.y);

    struct date birthday;
        printf("Enter your birthday (day): ");
        scanf("%d", &birthday.day);
        printf("Enter your birthday (month): ");
        scanf("%d", &birthday.month);
        printf("Enter your birthday (year): ");
        scanf("%d", &birthday.year);
    printf("Your birthday is %d-%d-%d \n", birthday.day, birthday.month, birthday.year);

    return 0;
}
```

## Typedef & Structures

<details>
<summary>Explanation</summary>

```c
// How to name variables?

// 1. Classic
int grade_math, grade_physics;

// 2. New mechanism
typedef int GRADE;
GRADE math;
GRADE physics;
```

```c
// How to apply 'typedef' to Structs

// 1. Classic
struct date{
    int day;
    int month;
    int year;
};

struct date myDate1, myDate2;

// 2. New mechanism
typedef struct date{
    int day;
    int month;
    int year
}Date;

Date myDate1, myDate2;
```

```c
// 'typedef' wonders

// 1. Example 01 
void printDate(Date dt){
    printf("Date = %d-%d-%d ", dt.year, dt.month, dt.day);
}

// 2. Exammple 02
Date inputDate(){
    Date dt;
    printf("Enter day (1-31): ");
    scanf("%d", &dt.day);
        // initialize Month and Year
    return dt;
}
```

</details>

## Chall.#2 - General FunctionZ to use Input & Print of a struct

```c
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
```


## Chall.#3 - Find the Next Date

- Write a function that
  - Receives a 'date' variable
  - Find and print the NEXT day on the calendar

```c
#include <stdio.h>

typedef struct date{
    int day;
    int month;
    int year;
}Date;

void printNextDay(Date dt){

    printf("Given date = %d-%.2d-%.2d \n", dt.year, dt.month, dt.day);

    if ((dt.month == 2) && (dt.day == 28)){
        dt.month++;
        dt.day=1;
    } else if ((dt.month == 1 || 3 || 5 || 7 || 8 || 10) && (dt.day == 31)){
        dt.month++;
        dt.day=1;
    } else if ((dt.month == 4 || 6 || 9 || 11) && (dt.day == 30)){
        dt.month++;
        dt.day=1;
    } else if ((dt.month == 12) && (dt.day == 31)){
        dt.month = 1;
        dt.day = 1;
        dt.year++;
    } else dt.day++;

    printf("Next day = %d-%.2d-%.2d \n", dt.year, dt.month, dt.day);
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
    Date userDate;
    puts("Provide a date to calculate its next day!");
    userDate = inputDate();
    if ((userDate.day < 1) || (userDate.day > 31) || (userDate.month < 1) || (userDate.month > 12))
        puts("Wrong date, please try again");
    else printNextDay(userDate);
    return 0;
}
```

## Initializing a Struct in C (Variables)

<details>
<summary>Explanation</summary>

Different ways to initialize Struct Variables:

```c
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

int main(){

    // Declare a 'Point' var (without initialization)
    Point p1;

    // Initializing a 'Point' var (fields in order)
    Point p2 = {5,7};

    // Using Designated Initializer
    Point p3 = {.x = 3, .y = 4};

    // Using Designated Initializer (not in order)
    Point p4 = {.y = 10, .x = 2};

    // Designated Initializer (other fields initialized with 0)
    Point p5 = {.x = 1};


    // PRINT 'EM ALL
    printf("p1) x=%d y=%d \n", p1.x, p1.y);
    printf("p2) x=%d y=%d \n", p2.x, p2.y);
    printf("p3) x=%d y=%d \n", p3.x, p3.y);
    printf("p4) x=%d y=%d \n", p4.x, p4.y);
    printf("p5) x=%d y=%d \n", p5.x, p5.y);

    return 0;
}
```

> Mind data types!

</details>


## Chall.#4 - Input Point & Print Point

- Write 2 functions:
  - #1: Gets a point variable and prints its information
  - #2: responsible for getting a point input from the user and then return it

```c
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

void printPoint(Point p){
    printf("x=%d y=%d \n", p.x, p.y);
}

Point inputPoint(){
    Point p;
    printf("- Enter x: ");
    scanf("%d", &p.x);
    printf("- Enter y: ");
    scanf("%d", &p.y);
    return p;
}

int main(){

    puts("Provide coordinates for a Point");
    Point p = inputPoint();
    printPoint(p);
    return 0;
}
```


## Static Array of Structs

```c
#include <stdio.h>
#define SIZE 5

typedef struct point{
    int x;
    int y;
}Point;


int main(){

    // Creating a 'Static Array of Points'
    Point pointsArr[SIZE];
    int i;

    // // Reading Input to the first point element in array
    // printf("- Enter x: ");
    // scanf("%d", &pointsArr[0].x);
    // printf("- Enter y: ");
    // scanf("%d", &pointsArr[0].y);

    // Iterating over all elements (reading input for each)
    for (i=0; i<SIZE; i++){
        printf("Enter x for point %d: ", i+1);
        scanf("%d", &pointsArr[i].x);
        printf("Enter y for point %d: ", i+1);
        scanf("%d", &pointsArr[i].y);
    }

    // Accessing and printing all elements in array
    for (i=0; i<SIZE; i++){
        printf("point %d: x=%d y=%d \n", i+1, pointsArr[i].x, pointsArr[i].y);
    }

    return 0;
}
```

> Can `main` be broken into different functions? Mind *struct* and *array* features...

<details>
<summary>@ChatGPT's</summary>

```c
#include <stdio.h>
#define SIZE 5

typedef struct point{
    int x;
    int y;
}Point;

void input_points(Point arr[], int size){
    int i;
    for (i=0; i<size; i++){
        printf("Enter x for point %d: ", i+1);
        scanf("%d", &arr[i].x);
        printf("Enter y for point %d: ", i+1);
        scanf("%d", &arr[i].y);
    }
}

void print_points(Point arr[], int size){
    int i;
    for (i=0; i<size; i++){
        printf("point %d: x=%d y=%d \n", i+1, arr[i].x, arr[i].y);
    }
}

int main(){

    Point pointsArr[SIZE];

    input_points(pointsArr, SIZE);
    print_points(pointsArr, SIZE);

    return 0;
}
```

</details>

<!--
```c
#include <stdio.h>
#define SIZE 5

typedef struct point{
    int x;
    int y;
}Point;


void printPointsArr(Point pointsArr[SIZE]){
    int i;
    for (i=0; i<SIZE; i++){
        printf("point %d: x=%d y=%d", i+1, pointsArr[i].x, pointsArr[i].y);
    }
}

Point inputPoint(){
    Point pointsArr[SIZE];
    int i;
    for (i=0; i<SIZE; i++){
        printf("Enter x for point %d: ", i+1);
        scanf("%d", &pointsArr[i].x);
        printf("Enter y for point %d: ", i+1);
        scanf("%d", &pointsArr[i].y);
    }
    return pointsArr[SIZE];
}


int main(){
    puts("Provide data for 5 Points!");
    Point pointsArr[SIZE] = inputPoint();
    printPointsArr(pointsArr[SIZE]);
    return 0;
}
```
-->


## Writing Associate Logical Functions

> Relational Operators: `<, >, <=, >=, !=, ==`

```c
#include <stdio.h>

typedef struct point{
    int x;
    int y;
}Point;

int equalPoint(Point p1, Point p2){   
    return (p1.x == p2.x && p1.y == p2.y) ? 1:0;
}

int main(){

    Point p1={4,4}, p2={4,4};

    if (equalPoint(p1,p2))
        puts("Points are the samey!");
    else puts("Points not equal dawg");

    return 0;
}
```

<!--ALSO used for emp1 age, id, etck-->

<!--
## Comprehensive Exercise - Rational Numbers Struct

<details>
<summary>Request</summary>

- Design and develop a rational number struct called Rational.
  - A rational number consists of two parts: numerator + denominator (eg. 1/3, 2/5, 7/3)
- Provide increment, decrement, addition, substraction, multiplication, division, smaller, bigger, equal and not equal functions to make relational/mathematical operatations on variables of a rational type.
- Write a main function to check out the correctness of your functions. Print the results before and after any operation that you do.

</details>


```c
#include <stdio.h>

typedef struct rational{
    int nume;   // numerator
    int deno;   // denominator
}Rational;

void increment(Rational *rPtr){
    (*rPtr).nume += (*rPtr).deno;
}

void decrement(Rational *rPtr){
    (*rPtr).nume -= (*rPtr).deno;
}

Rational addition(Rational rn1, Rational rn2){
    Rational result;
    result.deno = rn1.deno*rn2.deno;
    result.nume = rn1.nume*rn2.deno + rn2.nume*rn1.deno;
    return result;
}

Rational subtraction(Rational rn1, Rational rn2){
    Rational result;
    result.deno = rn1.deno*rn2.deno;
    result.nume = rn1.nume*rn2.deno - rn2.nume*rn1.deno;
    return result;
}

Rational multiplication(Rational rn1, Rational rn2){
    Rational result;
    result.deno = rn1.deno*rn2.deno;
    result.nume = rn1.nume*rn2.nume;
    return result;
}

Rational division(Rational rn1, Rational rn2){
    Rational result;
    result.deno = rn1.deno*rn2.nume;
    result.nume = rn1.nume*rn2.deno;
    return result;
}

int smaller(Rational rn1, Rational rn2){
    rn1.deno *= rn2.deno;
    rn2.deno *= rn1.deno;
    rn1.nume *= rn2.deno;
    rn2.nume *= rn1.deno;
    printf("%d VS %d \n", rn1.nume, rn2.nume);
    return (rn1.nume < rn2.nume) ? 0:1;
}


int main(){

    Rational rn1={3,4}, rn2={2,5};

    // printf("rn1) nume=%d deno=%d", rn1.nume, rn1.deno);
    // increment(rn1);
    // printf("rn1)  nume=%d deno=%d", rn1.nume, rn1.deno);

    Rational addResult = addition(rn1, rn2);
    printf("%d/%d \n", addResult.nume, addResult.deno);

    Rational subResult = subtraction(rn1, rn2);
    printf("%d/%d \n", subResult.nume, subResult.deno);

    Rational mulResult = multiplication(rn1, rn2);
    printf("%d/%d \n", mulResult.nume, mulResult.deno);

    Rational divResult = division(rn1, rn2);
    printf("%d/%d \n", divResult.nume, divResult.deno);


    if (smaller(rn1, rn2)) printf("'%d/%d' < '%d/%d' \n", rn1.nume, rn1.deno, rn2.nume, rn2.deno);

    return 0;
}
```
-->

## Composing struct inside another struct

```c
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
```

## Structs as the BASIS for more Advanced Topics

- Structs as BASIS for Data Structures (Linked Lists, Trees, etc.)