# 6. Arrays

## 6A. Concept & 1D Arrays

<details>
<summary>explanation</summary>

### theory

RECAP
- so far, 'single variables' <!--also limited variable types aye... -->
- much repetition which is bad
- poor scalability/safety
- arrays: "collection, bag" > one name, well organized & access to all elements (**indexed within, self-specified**)
- drill:
  1. Create 'unique bag'
  2. Put inside 'some elements' (in **strict order**)
  3. "Unique bag" has **size** (!) 

Arrays in a nutshell:
1. Declare what we're going to work with — as with variables
2. Do different types of operations
   - accessing different elements of the array
   - assigning values to elements
   - input 
   - output


#### Array Declaration

Syntax!
1. Specify the "TYPE of the elements" --> `int`, `double`, `char`, ...
   - all elements within will 'carry' such TYPE
2. Specify the "NAME" --> appropiate unique name
3. Specify the "LENGHT of the Array" --> in square brackets!
   - size of the Array **must be CONSTANT**, it won't *compile* otherwise!
   - Must be known so that compiler will allocate the right size of memory to the sequence of elements in program (ie array dawg)!!

Examples
- `int grades[5];`
- `double salaries[10];`
- `char myArray[100];`

<!-- > - [ ] why tho: [wiki](/docs/wiki.md) -->

> note **declaration** != **initialization**

#### Array Initialization <!--Curleyz-->

How to declare and assign content to the Array?
- for 'single variables', we'd do `int num = 5;`
- now we may do...
  - `int arr[3] = {5,7,10};`
  - `float bArr[3] = {1.2,5.3,2.6};`
  - `char name[4] = {'M','i','k','e'};`

Another way...
- 'Autocompletion' & *counter arrayz*
- EG.
  - `int arr[5] = {0};` will assign 0 to all 5 instances
  - `int arr[4] = {1,2}` will assign 0 to all 2 remaining instances



#### Element Accessing

> array in-memory representation — `char Hello[5];`

| 0   | 1   | 2   | 3   | 4   |
| --- | --- | --- | --- | --- |
| H   | e   | l   | l   | o   |

Introduction
- Array Declared OK
- Array Initialized OK
- Array Access
  - according to 'location', 'address', ie. **INDEX** (ALWAYS INTEGERS!)
    - [x] first element: *INDEX 0*
    - [x] last element: *INDEX SIZE-1* <!--4 hereo-->

> IMPORTANT: DO NOT EXCEED ARRAY SIZE (!!)
>
> Program may crush cuz it can't work with ghost values [*violation error*]


##### Access | Modify | Print

| action               | c code                            |
| ---                  | ---                               |
| array initialization | `int testArray[] = {2,5,3,7,10};`   |
| access an element    | \<Array-Name> [\<index>]          |
| modifying            | `testArray[2]=9` (3 becomes 9)    |
| printing             | `printf("%d", testArray[0]);` (2) |
| printing             | `printf("%d", testArray[1]);` (5) |

</details>

#### DEMONSTRATION — Find lowest grade

> notice `i=0`... me no likey cuz `i` IS ALREADY 0!
>
> although notice `&grades[i]`... !!

```c
#include <stdio.h>


int main(){

    int grades[5];
    int i;
    int lowest_grade;


    for (i=0; i<5; i++){
        printf("Enter grade no. %.2d: ", i+1);
        scanf("%d", &grades[i]);
    }


    lowest_grade = grades[0];       // A Must step...

    for (i=1; i<5; i++){
        if (grades[i] < lowest_grade)
            lowest_grade = grades[i];
    }


    printf("Your lowest grade is: %d \n", lowest_grade);
    
    for (i=0; i<5; i++){
        printf("grades[%d] = %d \n", i, grades[i]);
    }


    return 0;
}
```
<details>
<summary>draftey-notes</summary>

> if `printf()` has like array errors, it may print the actual **memory address**  (...)
>
> LASTLY, notice how `[ ]` may contain either the size or the iteration value (`i`)
>
> regarding **memory addresses** they jump from 4 to for (if array contents are integers), cuz every *array index* may take **4 bytes** IF dealing with *integers* :D

</details>


### Challenge #1 - Finding Maximum Value in Array

- todo
  - write program that inits an array of digits...
    - integers representing me phone number!
  - find and print maximum value in the array!

```c
#include <stdio.h>

int main(){

    int phoneNum[9]={6,1,8,2,5,4,8,9,0};
    int i, maxValue=phoneNum[0];

    for (i=1;i<9;i++){
        if (phoneNum[i] > maxValue)
            maxValue = phoneNum[i];
    }

    printf("Max digit in your phone number is: %d \n", maxValue);

    return 0;
}
```

> - [ ] do nicely adding purposeful functions!

### Challenge #2 - Finding Maximum Index in Array

- todo
  - same as before but now:
    - read digits from user!
    - print the **index** number, not the value 


```c
#include <stdio.h>

int main(){

    int phoneNum[9];
    int i, maxIndex=phoneNum[0];

    for (i=0;i<9;i++){
        printf("Enter digit n.%d: ", i+1);
        scanf("%d", &phoneNum[i]);
    }

    for (i=1;i<9;i++){
        if (phoneNum[i] > maxIndex)
            maxIndex = i;
    }

    printf("Max digit in your phone number is in INDEX: %d \n", maxIndex);

    return 0;
}
```


### Using a `#define` <!--IMPORTANT MENTION TO ***10x*** TOPICS-->

- Allows to **resize the array** 'globally', without the need to go line-by-line

<details>
<summary>demonstration with previous Challenge</summary>

```c
#include <stdio.h>
#define SIZE 9

int main(){

    int phoneNum[SIZE];
    int i, maxIndex=phoneNum[0];

    for (i=0;i<SIZE;i++){
        printf("Enter digit n.%d: ", i+1);
        scanf("%d", &phoneNum[i]);
    }

    for (i=1;i<SIZE;i++){
        if (phoneNum[i] > maxIndex)
            maxIndex = i;
    }

    printf("Max digit in your phone number is in INDEX: %d \n", maxIndex);

    return 0;
}
```

</details>



### Milestone#1 - Sensors System (Advanced Sensors Weather Station)

- todo (weather station)
  - collect "temperature" for last 7 days (C/F doesnt matter)
  - provide statistics // calculate & print
    - avg temperature thru week
    - hottest day
    - coldest day


```c
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
```


<details>
<summary>Modular Approach</summary>

```c
/*
    Section 6: Arrays; Milestone #1: Weather Station
    - Modular apprach; every statistic has its own function
    - Variables 'Day' and 'Temp' in functions stand for either
        - Day = index
        - Temp = value
    - TODO: allow for multiple days with max values.
    - TODO: allow for proper negative values
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
```

</details>


<details>
<summary>@Vlads</summary>

```c
#include <stdio.h>
#define SIZE 7

int main(){

    float temperature[SIZE];
    int i;
    float sum=0.0, avgTemp;
    int hottestDay=0, coldestDay=0;

    for (i=0; i<SIZE; i++){
        printf("Enter the temp at day %d: ", i+1);
        scanf("%f", &temperature[i]);
    }

    for (i=0; i<SIZE; i++){
        sum+=temperature[i];

        if (temperature[hottestDay]<temperature[i]){
            hottestDay=i;
            continue;
        }
        if (temperature[coldestDay]>temperature[i]){
            coldestDay=i;
        }
    }

    avgTemp = sum/SIZE;

    printf("The average temp = %f \n", avgTemp);
    printf("The hottest day was day %d \n", hottestDay+1);
    printf("The coldest day was day %d \n", coldestDay+1);

    return 0;
}
```

</details>


> NOTE:

```c
// Most 10x syntax yet (arrays)
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
```


### Good Multiplication Neighbors

- todo
  - create array of integers
  - check and print if array has **any element with 'good neighbours'**
    - IE element equals the multiplication of the next element to the right and to the right


```c
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
```

<!-- PROTOTYPE
#include <stdio.h>

int main(){

    /* Good Neighbors x2 = {2,6,3,9,3}; */
    int door[5];
    int i;
    // int good;

    printf("Enter five integers: \n");

    for (i=0; i<5; i++){
        printf("Int %d: ", i+1);
        scanf("%d", &door[i]);
    }


    for (i=0; i<5; i++){
        if (door[i]==door[i-1]*door[i+1]){
            // good = door[i];
            printf("Yay! i%d (%d) has Good Neighbors (%d*%d) \n", i, door[i], door[i-1], door[i+1]);
        }
    }

    // if (good)
    //     printf("Good neighbors dawg! \n");
    // else printf("Nay dawg... \n ");

    return 0;
}



/*
    PROTOTYPE 1

int main(){
    int good;
    int i;

    int prev, curr, next;
        prev = arr[i+1];
        curr = arr[i];
        next = arr[i-1];

    printf("%d", prev);
    printf("%d", curr);
    printf("%d", next);

    for (i=0; i<5; i++){

        if (prev*next==curr){
            good=1;
            printf("%d", i);
        }
    }

}

*/


/**/
-->


### Challenge #3 - Display array values in reverse order

- todo
  - create array of size 10 to represent some workout routines 'pullUpsArray' or sumthin
  - print array values in reverse order!


```c
#include <stdio.h>

int main(){

    int pullUpsArr[10];
    int i;

    for (i=0; i<10; i++){
        printf("Enter number of pull-aps on day n.%d: ", i+1);
        scanf("%d", &pullUpsArr[i]);
    }


    printf("\nSee your history below: \n");
    for (i=9; i>=0 ; i--)
        printf("You did %d pull-ups %d days ago \n", pullUpsArr[i], i);

    return 0;
}
```



## 6B. Matrix & 2D Arrays


### 2D Arrays Declaration
### 2D Arrays Initialization ( + tips/tricks)
### Element Accessing
### 1. Initializting & Printing 2D Array
### 2. Multiplication Table
### Input to Element in a 2D Array
### Physical Representation in Memory!
