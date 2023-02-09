# 9. Additional Content...

<details>
<summary>Table of Contents</summary>

- [9. Additional Content...](#9-additional-content)
  - [9.1 Structs](#91-structs)
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
  - [9.2 Unions](#92-unions)
    - [General Introduction](#general-introduction)
    - [Unions - Variables](#unions---variables)
    - [Usage, Practice, Examples](#usage-practice-examples)
      - [Example 01](#example-01)
      - [Example 02](#example-02)
    - [Additional Explanations and Examples (Pointers, Arrays...)](#additional-explanations-and-examples-pointers-arrays)
  - [9.3 Constants](#93-constants)
    - [Constants VS Variables](#constants-vs-variables)
    - [Syntax and usage of Constants](#syntax-and-usage-of-constants)
    - [Exclusive TIPS](#exclusive-tips)
    - [3 main reasons for using constants](#3-main-reasons-for-using-constants)
  - [9.4 Counting Arrays](#94-counting-arrays)
    - [Intro - Counting with Separated Counter Variables](#intro---counting-with-separated-counter-variables)
    - [Working with Counter Arrays](#working-with-counter-arrays)
      - [Counting Array - Learning the Concept](#counting-array---learning-the-concept)
    - [Basic Exercise #1 - Set 0-5](#basic-exercise-1---set-0-5)
    - [Basic Exercise #2 - Find Max Appearances (Set 0-9)](#basic-exercise-2---find-max-appearances-set-0-9)
    - [Moving forward with the Mapping](#moving-forward-with-the-mapping)
    - [Basic Exercise #3 - Find Max Appearances (Set 5-10)](#basic-exercise-3---find-max-appearances-set-5-10)
    - [Chall. #1 - Finding the lowercase letter that appears the most](#chall-1---finding-the-lowercase-letter-that-appears-the-most)
    - [Chall. #2 - Finding the uppercase letter that appears the most](#chall-2---finding-the-uppercase-letter-that-appears-the-most)
    - [Chall. #3 - Finding the letter that appears the most](#chall-3---finding-the-letter-that-appears-the-most)
  - [9.5 Working with Files](#95-working-with-files)
    - [What is a file \[as a stream of bytes\]](#what-is-a-file-as-a-stream-of-bytes)
    - [Examples of Stream already used (Input/Output/Error)](#examples-of-stream-already-used-inputoutputerror)
    - [Start with Files - Steps and Syntax in C](#start-with-files---steps-and-syntax-in-c)
    - [Creating and Reading from a File](#creating-and-reading-from-a-file)
    - [Intro to 6 basic functions for working with textual files](#intro-to-6-basic-functions-for-working-with-textual-files)
      - [`fgetc` (`r`)](#fgetc-r)
      - [`fputc` (`w`)](#fputc-w)
      - [`fprintf` (`w`) \& `fscanf` (`r`)](#fprintf-w--fscanf-r)
      - [`fputs` (`w`)](#fputs-w)
      - [`fgets` (`r`)](#fgets-r)
    - [Introducing EOF](#introducing-eof)
    - [Challenges](#challenges)
      - [Chall #1 - Number of Characters in a file](#chall-1---number-of-characters-in-a-file)
      - [Chall #2 - Number of Lines in a file](#chall-2---number-of-lines-in-a-file)
      - [Chall #3 - Writing Numbers and their Powers to a file](#chall-3---writing-numbers-and-their-powers-to-a-file)
      - [Chall #4 - Reading Numbers from a file](#chall-4---reading-numbers-from-a-file)
      - [Chall #5 - Calculate character appearances in a file](#chall-5---calculate-character-appearances-in-a-file)
      - [Chall #6 - lowerFrequencyAppearances for Lowercase letters](#chall-6---lowerfrequencyappearances-for-lowercase-letters)
      - [Chall #7 - Print Max Appearances Lowercase Letter in file](#chall-7---print-max-appearances-lowercase-letter-in-file)
  - [9.6 Linked Lists](#96-linked-lists)
    - [Creating a Linked List](#creating-a-linked-list)
    - [Count of Nodes in a List](#count-of-nodes-in-a-list)
    - [How to use bool Data Types?](#how-to-use-bool-data-types)
    - [Finding an Element within a List](#finding-an-element-within-a-list)
    - [Count the number of values in a List](#count-the-number-of-values-in-a-list)

</details>

## 9.1 Structs

<details>
<summary>Details</summary>

### Creating a Structure Template

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

### Structure Variables

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

### Challenge #1 - Initialize & Print Date Variable (Struct)

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

### Typedef & Structures

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

### Chall.#2 - General FunctionZ to use Input & Print of a struct

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


### Chall.#3 - Find the Next Date

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

### Initializing a Struct in C (Variables)

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


### Chall.#4 - Input Point & Print Point

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


### Static Array of Structs

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


### Writing Associate Logical Functions

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
### Comprehensive Exercise - Rational Numbers Struct

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

### Composing struct inside another struct

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

### Structs as the BASIS for more Advanced Topics

- Structs as BASIS for Data Structures (Linked Lists, Trees, etc.)

</details>

## 9.2 Unions

<details>
<summary>Details</summary>

### General Introduction

- Useful for embedded devices (memory map registers to communicate with peripherals)
- == User Defined Data Type (as Structs)
- Collection of elements/variables of different types **stored in the same memory region**

### Unions - Variables

```c
union <union-name> {
    datatype1 field1;
    datatype2 field2;
};
```

```c
union info{
    char firstName[20];
    int age;
};

union minMax{
    int min;
    int max;
    double average;
};
```

### Usage, Practice, Examples

Difference with *Sructs* & COMPLETE examples

```markdown
STRUCT --> Separate block of memory for each variable
UNION ---> One memory region SHARED (size == max datatype size) // data overlaps
```

#### Example 01

```c
#include <stdio.h>
#include <string.h>

struct info_struct{       // 24 BYTES!!
    char firstName[20];     // 20 bytes
    int age;                // 4 bytes
};  

union info_union{         // 20 BYTES!!
    char firstName[20];     // 20 bytes
    int age;                // ~~4 bytes~~
};


int main(){

    union info_union myVar1;

    myVar1.age = 30;
    printf("Age: %d \n", myVar1.age);

    strcpy(myVar1.firstName, "supdawg!");
    printf("Name: %s \n", myVar1.firstName);

    printf("Age: %d (OVERLAPPED) \n", myVar1.age);

    return 0;
}
```
#### Example 02

```c
#include <stdio.h>

struct point_struct{
    int x;
    int y;
};

union point_union{
    int x;
    int y;
};

int main(){

    struct point_struct p1; // 8 bytes!!
    p1.x = 5;   // 4 bytes
    p1.y = 7;   // 4 bytes
    printf("p1_struct: x=%d y=%d \n", p1.x, p1.y);
    
    union point_union p2;   // 4 bytes!!
    p2.x = 4;   // ~~4 bytes~~
    printf("p2_union: x=%d y=%d \n", p2.x, p2.y);
    p2.y = 6;   // 4 bytes
    printf("p2_union: x=%d y=%d \n", p2.x, p2.y);

    return 0;
}
```


### Additional Explanations and Examples (Pointers, Arrays...)

```c
#include <stdio.h>
#define SIZE 3

/*
struct Student_struct{      // 16 bytes (??)
    int ID;                   // 4 bytes
    double GPA;               // 8 bytes
};
*/


typedef union student{      // 8 bytes  --> Store capacity for either ID or GPA!
    int ID;                   // ~~4 bytes~~
    double GPA;               // 8 bytes
}Student;


int main(){

    Student s1;
    Student *ptrS2;

    printf("Size of s1 union = %lu \n", sizeof(s1));
    printf("Size of ptrS2 union = %lu \n", sizeof(ptrS2));

    s1.ID = 5;
    printf("s1.ID = %d \n", s1.ID);

    ptrS2 = &s1;
    ptrS2->ID = 10;
    printf("s1.ID = %d \n", s1.ID);



    Student sArr[SIZE];
    int i;

    for (i=0; i<SIZE; i++){
        printf("Enter ID for s%d: ", i+1);
        scanf("%d", &sArr[i].ID);
    }

    for (i=0; i<SIZE; i++){
        printf("Student #%d ID = %d \n", i+1, sArr[i].ID);
    }


    /*
    struct Student_struct s1_s;
    printf("Size of s1 struct = %lu \n", sizeof(s1_s));
    */


    return 0;
}
```

</details>

## 9.3 Constants

<details>
<summary>Details</summary>

### Constants VS Variables

- Variables (`int`, `float`, `char`...) may change over time
- Constants DON'T!

### Syntax and usage of Constants

```c
// Add 'const' to the var declaration
const int year = 2000;
```

<!-- - Any attempt to change the value of `const` will lead to Compilation Error! -->

### Exclusive TIPS

1. "Default" usage of constants in C Language

```c
// Datatype 'int' is ASSUMED
const age = 35;
```

2. A pointer to a constant! == `const int *ptr;`
   - Value we're pointing to CAN'T BE CHANGED.
   - Pointer itself CAN BE CHANGED.


3. Constant pointer to var == `int *const ptr;`
   -  Value we're pointing to CAN BE CHANGED
   -  Pointer itself CAN'T BE CHANGED


```c
#include <stdio.h>

int main(){

    // Create constant vars
    const int age1 = 20;
    const int age2 = 25;

    // Create constant pointer that points to var 'age1'
    int *const ptr1 = &age1;
    printf("var1=%d var2=%d\n", age1, age2);
    

    // Modify var 'age1' value, not the actual pointer!
    *ptr1 = 30;
    printf("var1=%d var2=%d\n", age1, age2);
    

    // // To-fail attempt to change the pointer itself
    // ptr = &age2;

    printf("var1=%d var2=%d\n", age1, age2);
}
```

<!--
```c
#include <stdio.h>


int main(){

    // Create vars n1, n2 + constant vars n3, n4
    int n1 = 10;
    int n2 = 15;
    const int n3 = 20;
    const int n4 = 25;
    printf("Vars = %d %d %d %d\n", n1, n2, n3, n4);

    // Create pointers and constant pointers!
    const int *ptr1 = &n1;
    int *const ptr2 = &n2;
    const int *ptr3 = &n3;
    int *const ptr4 = &n4;  // Compiler Warning: initialization discards 'constant' qualifier from pointer target type 
    printf("Ptrs = %d %d %d %d\n", *ptr1, *ptr2, *ptr3, *ptr4);


    /*
    // Create constant pointer that points to var 'age1'
    int *const ptr1 = &age1;
    printf("var1=%d var2=%d\n", age1, age2);
    

    // Modify var 'age1' value, not the actual pointer!
    *ptr1 = 30;
    printf("var1=%d var2=%d\n", age1, age2);
    

    // // To-fail attempt to change the pointer itself
    // ptr = &age2;

    printf("var1=%d var2=%d\n", age1, age2);
    */
    

    return 0;
}
```
-->

4. Constant pointer pointing to constant integer. Neither the Pointer nor the Value can be changed. BOTH ARE CONSTANTS! == `const int *const ptr;`


### 3 main reasons for using constants

1. Performance! == Easier compiling if large program
2. Defense! == Ensure values may not change 
3. Code Readability

</details>


## 9.4 Counting Arrays

<details>
<summary>Details</summary>

### Intro - Counting with Separated Counter Variables

<details>
<summary>Intro</summary>


- Counting Appearances of Array with values {0,1}
  1. Given an array of a given size... The array consists only of values {0,1}. Eg. `0,1,0,1,0,0,1,0`
  2. We would like to know number of appearances of value 0 and value 1 in the array.
  3. Create two variables `count0` and `count1` and iterate 

- Counting with values {0,1,2}

```c
#include <stdio.h>
#define SIZE 8

int main(){

    int arr[SIZE] = {0,2,0,1,0,0,2,0};
    int count0, count1, count2;
    int i;

    for (i=0; i<SIZE; i++){
        if (0 == arr[i]) count0++;
        else if (1 == arr[i]) count1++;
        else if (1 == arr[i]) count1++;
        else if (2 == arr[i]) count2++;
    }

    printf("Number of '0' = %d \n", count0);
    printf("Number of '1' = %d \n", count1);
    printf("Number of '2' = %d \n", count2);

    return 0;
}
```

- What if the possibilities are now 5? What if 10? 100??

</details>

### Working with Counter Arrays

<details>
<summary>Transition</summary>

- Counting Array for values {0,1,2}
  1. We know the values can be {0,1,2}... Hence we need 3 'counting variables'.
  2. Let's create a sequence/array for counting. A sequence of 3 'counting variables' == `countArr={0,1,2}`
  3. Similarly, 3 variables to count.

```c
#include <stdio.h>
#define SIZE 8

int main(){

    int arr[SIZE] = {0,2,0,1,0,0,2,0};
    int countArr[3];
    int i;

    for (i=0; i<SIZE; i++){
        if (0 == arr[i]) countArr[0]++;
        else if (1 == arr[i]) countArr[1]++;
        else if (2 == arr[i]) countArr[2]++;
    }

    printf("Number of '0' = %d \n", countArr[0]);
    printf("Number of '1' = %d \n", countArr[1]);
    printf("Number of '2' = %d \n", countArr[2]);

    return 0;
}
```

> Still too many dependencies!!

#### Counting Array - Learning the Concept

- What value can each of the elements in the `sourceArr` have? -> {0,1,2}
- Mapping `sourceArr` values to the `countArr` indexes -> (if ... foo++)

```c
#include <stdio.h>
#define SIZE 8

int main(){

    int sourceArr[SIZE] = {0,2,0,1,0,0,2,0};
    int countArr[3] = {0};
    int i;

    for (i=0; i<SIZE; i++){
        countArr[sourceArr[i]]++;
    }

    printf("Number of '0' = %d \n", countArr[0]);
    printf("Number of '1' = %d \n", countArr[1]);
    printf("Number of '2' = %d \n", countArr[2]);

    return 0;
}
```

<!-- > It works because values == indexes! -->

</details>

### Basic Exercise #1 - Set 0-5

```c
#include <stdio.h>
#define SIZE 8

int main(){

    int sourceArr[SIZE] = {0,5,2,4,3,4,2,0};
    int countArr[6] = {0};
    int i;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]]++;

    for (i=0; i<6; i++)
        printf("Number of '%d' = %d \n", i, countArr[i]);

    return 0;
}
```

### Basic Exercise #2 - Find Max Appearances (Set 0-9)

- Write a program that initializes an array with 20 elements. Each element can be a number with only 1 digit ({0-9}).
- Using 'Counting Array', find which value appears the most in the 'Source Array'. Print this value and the number of its appearances.

<details>
<summary>Snippet</summary>

```c
#include <stdio.h>
#define SIZE 20
#define VALUES 10

int main(){

    int mostValue, mostTimes;
    int sourceArr[SIZE] = {0,5,4,9,5,8,2,3,1,5,4,9,5,5,2,7,6,5,4,1};
    int countArr[VALUES] = {0};
    int i;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]]++;

    for (i=0; i<VALUES; i++){
        if (countArr[i] > mostTimes){
            mostValue=i;
            mostTimes=countArr[i];
        } 
    }

    printf("The value of %d appeared most of the times. Total of %d appearances \n", mostValue, mostTimes);

    return 0;
}
```
</details>

<details>
<summary>@Vlad's</summary>

```c
#include <stdio.h>
#define SIZE 20
#define VALUES 10

int main(){

    int maxIndex;
    int sourceArr[SIZE] = {0,5,4,9,5,8,2,3,1,5,4,9,5,5,2,7,6,5,4,1};
    int countArr[VALUES] = {0};
    int i;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]]++;

    for (i=0; i<VALUES; i++)
        if (countArr[i] > maxIndex)
            maxIndex = i;

    printf("The value of %d appeared most of the times. Total of %d appearances \n", maxIndex, countArr[maxIndex]);

    return 0;
}
```

</details>


### Moving forward with the Mapping

- Now what if `sourceArr` values were only {5-10}?
  - Still 5 possible values but not CORRESPONDING with the indexes.
  - We can't map DIRECTLY now...
  - But can still do: src.value5 = count.index0, 6 = 1, etc etc
  - Therefore `countArr[sourceArr[i-5]]`


### Basic Exercise #3 - Find Max Appearances (Set 5-10)

- Write a program that initializes an array with 8 elements. Each element can have a value in the range of {5-10}
- Using 'Counting Array' and 'Appropiate Mapping', find which value appears the most in the 'Source Array'. Also, print this value and the number of its appearances.


```c
#include <stdio.h>
#define SIZE 8
#define VALUES 6

int main(){

    int sourceArr[SIZE] = {7,5,6,9,6,7,10,7};
    int countArr[VALUES];
    int i, maxIndex;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]-5]++;

    for (i=0; i<VALUES; i++)
        if (countArr[i] > countArr[maxIndex])
            maxIndex=i;

    printf("The value of %d appeared most of the times. Total of %d appearances \n", \
    maxIndex+5, countArr[maxIndex]);

    return 0;
}
```

### Chall. #1 - Finding the lowercase letter that appears the most

- Write a program that initializes an array of lowercase letters {a-z}
- Using 'Counting Array' and 'Appropiate Mapping', find which lowercase letter appears the most in the 'Source Array'.
  - Also, print its value and the number of its appearances.
- Example: `sourceArray = {k,i,b,r,c,k,z,m};` // The letter 'k' appeared most of the times. Total of '2' appearances.

<!--ASCII??-->

<details>
<summary>Snippet</summary>

```c
/* ASCII
    a = 97
    z = 122
    '-97'
*/

#include <stdio.h>
#define SIZE 8
#define VALUES 26

int main(){

    char sourceArr[SIZE] = {'k','i','b','r','c','k','z','m'};
    int countArr[VALUES];
    int i, maxIndex;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]-'a']++;

    for (i=0; i<VALUES; i++)
        if (countArr[i] > countArr[maxIndex])
            maxIndex = i;

    printf("Letter %c appeared the most (%d times) \n", maxIndex+'a', countArr[maxIndex]);

    return 0;
}
```

</details>

### Chall. #2 - Finding the uppercase letter that appears the most

<details>
<summary>Snippet</summary>

```c
/* ASCII
    a = 65
    z = 90
    '-65'
*/

#include <stdio.h>
#define SIZE 8
#define VALUES 26

int main(){

    char sourceArr[SIZE] = {'K','I','B','R','C','K','Z','M'};
    int countArr[VALUES];
    int i, maxIndex;

    for (i=0; i<SIZE; i++)
        countArr[sourceArr[i]-'A']++;

    for (i=0; i<VALUES; i++)
        if (countArr[i] > countArr[maxIndex])
            maxIndex = i;

    printf("Letter %c appeared the most (%d times) \n", maxIndex+'A', countArr[maxIndex]);

    return 0;
}
```

</details>

### Chall. #3 - Finding the letter that appears the most

- Write a program that initializes an array of lowercase, uppercase and space character { a-z | A-Z | ' ' }
  - `sourceArr[8] = {'K','O','c','R','C',' ','K','r'};`
- Using 'Counting Array' and 'Appropiate Mapping', find which **letter** appears the most in the 'Source Array'. Also, print its value and the number of its appearances.

```c
/* ASCII
    ' ' = 32    // we don't care
    'A' = 65
    'Z' = 90
    'a' = 97
    'z' = 122
*/

#include <stdio.h>
#define SIZE 8
#define VALUES 52

int main(){

    char arr[8] = {'K','O','c','R','C',' ','K','r'};
    int countArr[VALUES];   // 0-25=a-z, 26-51=A-Z;
    int i, maxIndex;


    for (i=0; i<SIZE; i++){
        if (arr[i] >= 'a' && arr[i] <= 'z')
            countArr[arr[i] - 'a']++;
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            countArr[arr[i] - 'A' + 26]++;
    }


    for (i=0; i<VALUES; i++)
        if (countArr[i] > countArr[maxIndex])
            maxIndex = i;


    if (maxIndex < 26)
        printf("Letter %c appeared the most (%d times) \n", maxIndex + 'a', countArr[maxIndex]);
    else printf("Letter %c appeared the most (%d times) \n", maxIndex + 'A' - 26, countArr[maxIndex]);

    return 0;
}
```

<!-- SILLY PROTOTYPE
```c
/* ASCII
    ' ' = 32
    'A' = 65
    'Z' = 90
    'a' = 97
    'z' = 122
*/

#include <stdio.h>
#define SIZE 8
#define VALUES 53

int main(){

    char sourceArr[8] = {'K','O','c','R','C',' ','K','r'};
    int countArr[VALUES];
    int i, maxIndex;


    for (i=0; i<SIZE; i++){
        if (sourceArr[i] == ' ')
            countArr[0]++;
        if (sourceArr[i] >= 'A' && sourceArr[i] <= 'Z')
            countArr[sourceArr[i]-'A']++;
        if (sourceArr[i] >= 'a' && sourceArr[i] <= 'z')
            countArr[sourceArr[i]-'a']++;
    }


    for (i=0; i<VALUES; i++){
        if (countArr[i] > countArr[maxIndex])
            maxIndex = i;
    }

    printf("Letter %c appeared the most (%d times) \n", maxIndex+'A', countArr[maxIndex]);

    return 0;
}
```
-->


</details>

## 9.5 Working with Files

<details>
<summary>Details</summary>

### What is a file [as a stream of bytes]

- Two types
  - Textual files
  - Binary files
- Communication between files, programs, devices...

### Examples of Stream already used (Input/Output/Error)

- Keyboard -> Input stream -> Queue structure -> Standard input (Stdin) -> Program (`scanf`)
- Program -> Output structure -> Standard Output / Standard Error -> Screen
- **NOW**: read from file && write to file

### Start with Files - Steps and Syntax in C

<details>
<summary>Explanation</summary>

```c
#include <stdio.h>

int main(){

    // int* p;
    // double* p2;

    // 1. Creating a Pointer that points to a FILE type
    FILE* fp;

    /*  2. Open/access a file
    fp = fopen(<filename> <typeOfOperation>);
    Types of operation:
        - w = writing
        - r = reading
        - a = appending
    */
    fp = fopen();


    // 3. Make sure the open operation was successful
    if (fp!=NULL)

    // 4. After operations, close the file!
    fclose(fp);


    return 0;
}
```

</details>

### Creating and Reading from a File

```c
#include <stdio.h>

int main(){

    FILE* fp;

    fp = fopen("supdawg.md","w");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("File Opened for Writing!");
        fclose(fp);
    } 

    return 0;
}
```

### Intro to 6 basic functions for working with textual files

```markdown
r) fgetc(<ptr_to_file>)
w) fputc(<char>, <ptr>)
w) fprintf(<ptr>, <placeholder>, <parameters>)
r) fscanf(<ptr>, <placeholder>, <parameters>)
w) fputs(<string>,<ptr>)
r) fgets(<string>, <int/length_limit>, <ptr>)
```

<details>
<summary>One by one</summary>

#### `fgetc` (`r`)

```c
/*
    File 'supdawg.md' already exists.
    Contents = 'Hiya!'
*/

#include <stdio.h>

int main(){

    FILE* fp;
    char myChar1, myChar2;

    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("File Opened for READING");
        myChar1 = fgetc(fp);
        printf("First character read = %c \n", myChar1);    // 'H'
        myChar2 = fgetc(fp);
        printf("Second character read = %c \n", myChar2);   // 'i'
        // fgetc(stdin); // ...
        fclose(fp);
    } 

    return 0;
}

/*
    NOTE: loops can be coded for a more complete program!
*/
```

#### `fputc` (`w`)

- Takes a char and a pointer to an file, writes it in
- NOTE: single quotes for chars, double quotes for strings!!

```c
#include <stdio.h>

int main(){

    FILE* fp;

    fp = fopen("supdawg.md","w");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for WRITING--");
        fputc('H', fp);
        fputc('e', fp);
        fputc('y', fp);
        fclose(fp);
    } 

    return 0;
}
```

> Honorable mention to `putchar('a', stdout);`

#### `fprintf` (`w`) & `fscanf` (`r`)

- `fprintf` print [code variables] to file!!
  - returns number of bytes written!! <!--SOO-->
- it can also print to terminal if `fprintf(STDOUT, ...);`

```c
#include <stdio.h>

int main(){

    FILE* fp;
    int num = 6;
    int num2;

    fp = fopen("supdawg.md","w");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for WRITING--");        
        fprintf(fp, "%d^2 = %d", num, num*num);
        fclose(fp);
    } 

    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING--");        
        fscanf(fp, "%d", &num2);
        printf("Num from file = %d \n", num2);
        fclose(fp);
    }

    return 0;
}

```

#### `fputs` (`w`)

- MIND: **no 'newline'** (`\n`)!!

```c
#include <stdio.h>

int main(){

    FILE* fp;

    fp = fopen("supdawg.md","w");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for WRITING--");
        fputs("Supdawg? \n", fp);
        fputs("C iz eazy don't ye see?", fp);
        fclose(fp);
    } 

    return 0;
}
```

#### `fgets` (`r`)

```c
#include <stdio.h>

int main(){

    FILE* fp;
    char myString[9];
    int count;

    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING--");
        while (fgets(myString, 9, fp))
            printf("String #%d read: %s \n", ++count, myString);

        fclose(fp);
    } 

    return 0;
}
```

- [ ] REVIEW!

</details>

### Introducing EOF

- Remember `\0` represents end of string
  - Store *within* the string
- For **EOF**, generally `-1`
  - Not stored at the end of file!!
  - Specifier/indicator to the lower-level system
- NOTE: function `feof(fp);` 

```c
while (!(feof(fp)))
    // do smth before EOF
```


### Challenges

#### Chall #1 - Number of Characters in a file

- Write a program that opens a file for Reading and calculates number of characters (use `fgetc` to print each char)


```c
#include <stdio.h>

int main(){

    FILE* fp;
    char fileChar;
    int numChars;


    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        while ((fileChar = fgetc(fp)) != EOF){
            printf("%c %d \n", fileChar, fileChar);
            numChars++;
        }

        fclose(fp);
    } 

    printf("\nTotal num of chars = %d \n", numChars);
    return 0;
}
```

<!-- un-optimized

while (!(feof(fp))){
            fileChar = fgetc(fp);
            if (fileChar != -1){
                printf("%c %d \n", fileChar, fileChar);
                numChars++;
            }
-->


#### Chall #2 - Number of Lines in a file

- Write a program that returns number of lines in file

```c
#include <stdio.h>

int main(){

    FILE* fp;
    char fileChar;
    int numLines = 1;

    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        while ((fileChar = fgetc(fp)) != EOF)
            if (fileChar == 10)     // == '\n'
                numLines++;

        fclose(fp);
    } 

    printf("Total num of lines = %d \n", numLines);
    return 0;
}
```

<!--
while (!(feof(fp))){
    fileChar = fgetc(fp);
    if (fileChar == 10 || fileChar == -1)
        numLines++;
}
-->

#### Chall #3 - Writing Numbers and their Powers to a file

- Write program that will save into a file 10 natural numbers {1-10} and their powers.

```c
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
```

#### Chall #4 - Reading Numbers from a file

- Read numbers from previous files and print them to the terminal!

```c
/* APPROACH
    1. Take numbers two by two
    2. Take strings line by line
*/

#include <stdio.h>

int main(){

    FILE* fp;
    int i;
    int numFile, powerFile;
    char lineFile[10];

    fp = fopen("supdawg.md","r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        
        // 1. Numbers two by two (as per lines)
        for (i=1; i<=10; i++){
            fscanf(fp, "%d %d", &numFile, &powerFile);
            printf("%d %d \n", numFile, powerFile);
        }
        
        // 2. Strings line by line
        /*  while (!(feof(fp))){
            printf("%s \n", lineFile);
            fgets(lineFile, 10, fp);
        } */

        fclose(fp);
    } 

    return 0;
}
```

#### Chall #5 - Calculate character appearances in a file

- Write a program that reads a 'filename' and a certain 'character' from the user.
- The program should calculate and print the total appearances of the character in the file.

> Filename: 'aptShowGcc.log'

```c
/* NOTE
    Filename == "aptShowGcc.log"
    'Assume file is in the same workspace as src-code,
    so we don't need to specify PATH!
*/

/* TROUBLESHOOTING
    - 'scanf("%s", filename);'
    - 'scanf(" %c", &charSearch);' 
    Mind lack of '&' and ' ' respectively!
*/

#include <stdio.h>

int main(){

    FILE* fp;
    char filename[40] = {0};
    char charSearch;
    int charNum;

    // User input
    puts("This program will search a character in a file and print its number of appearances");
    printf("Enter filename: ");     // Extension, PATH...
    scanf("%s", filename);
    printf("Enter character: ");
    scanf(" %c", &charSearch);

    // Retrieve file data
    fp = fopen(filename, "r");

    if (fp==NULL) puts("Failed to Open File");
    else{
        puts("--File Opened for READING-- \n");
        
        while (!feof(fp))
            if (fgetc(fp) == charSearch)
                charNum++;

        fclose(fp);
    } 

    printf("Char '%c' appeared '%d' times in file '%s' \n\n", charSearch, charNum, filename);

    return 0;
}
```

<!-- ALT
while ((charCurrent = fgetc(fp)) != EOF)
    if (charCurrent == charSearch)
        charNum++;
-->

#### Chall #6 - lowerFrequencyAppearances for Lowercase letters

- Write a program that
  - reads a 'filename' from the user
  - creates a 'frequencyAppearances' array for lowercase letters {a-z}
  - prints the number of times each lowercase letter appears in the file.

```c
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
```

<!-- prototype OK
currentChar = 'a';
puts("Alphabetical order");
for (i=0; i<VALUES; i++)
    printf("Letter '%c' appeared '%d' times \n", currentChar++, frequencyAppearances[i]);
-->

#### Chall #7 - Print Max Appearances Lowercase Letter in file

- Write a program that
  - reads a filename from the user
  - creates a 'frequencyAppearances' array for lowercase letters {a-z}
  - prints the (first) character that appeared most of the times.


```c
#include <stdio.h>
#define VALUES 26

int main(){

    FILE* fp;
    char filename[40] = {0};
    int frequencyAppearances[VALUES] = {0}; // 0-a 1-b ... 25-z
    char currentChar;
    int i;
    int maxValue;
    char maxChar;
    
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

    for (i=0; i<VALUES; i++){
        if (frequencyAppearances[i] > maxValue){
            maxValue = frequencyAppearances[i];
            maxChar = i + 'a';
        }
    }

    printf("Letter '%c' appeared the most ('%d' times) \n", maxChar, maxValue);

    return 0;
}
```

<details>
<summary>@Vlad's</summary>

```c
#include <stdio.h>
#define VALUES 26

int main(){

    FILE* fp;
    char filename[40] = {0};
    int frequencyAppearances[VALUES] = {0}; // 0-a 1-b ... 25-z
    char currentChar;
    int i;
    int maxIndex;
    
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

    for (i=0; i<VALUES; i++)
        if (frequencyAppearances[i] > frequencyAppearances[maxIndex])
            maxIndex = i;

    printf("Letter '%c' appeared the most ('%d' times) \n", maxIndex + 'a', frequencyAppearances[maxIndex]);

    return 0;
}
```
</details>


</details>


## 9.6 Linked Lists

<details>
<summary>Details</summary>

### Creating a Linked List
### Count of Nodes in a List
### How to use bool Data Types?
### Finding an Element within a List
### Count the number of values in a List

</details>