# 6. Arrays

> [Skip to 1-D PRACTICALS!](#practicals-6)

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

intro
- 'standard variables': `int num;`, `double b;`, `char my_char;`, ...
- '1-D Arrays': `int grade[5];`, ...

2D Arrays
- "Not a single row of elements but rather a GRID of rows and columns"
- Need to specify size of ROWS and COLUMNS
- TYPE+NAME+[ ]
- Example: `int mat[3][4];` = 3 ROWS, 4 COLUMNS!
  - positions would be 0,1,2 for ROWS, 0,1,2,3 for COLUMNS!

### 2D Arrays Initialization ( + tips/tricks)

intro
- 'standard variable¡: `int num = 5;`
- '1-D Array': `int grades[5] = {8,9,8,10,9};`

2D Arrays
- **Standard Way**: `int mat[2][3] = { {1,2,3}, {4,5,6} };`
- *Incomplete Values in the Internal Curly Brackets*: `int mat[4][3] = {{1,2}, {4,5,8}, {}, {10}};`
  - empty values become `0` (ie. A:1,2,0 B:4,5,8 C:0,0,0 D:10,0,0)
- *Excessive values in the Internal Curly Brackets*:  `int mat[2][3] = {5,2,1,6,5};`
  - (ie. A:5,2,1 B:6,5,0)


### Element Accessing

intro
- 1D-Arrays (ROWS)
```c
int arr[3] = {1,2,3};
    arr[0] == 1
    arr[1] == 2
```

- 2D-Array (ROWS + COLUMNS)
```c
int mat[2][3] = {{1,2,3}, {4,5,6}};
    int mat[0][0] == 1;
    int mat[0][1] == 2;
    int mat[0][2] == 3;
    int mat[1][0] == 4;
    int mat[1][1] == 5;
    int mat[1][2] == 6;

// CHANGE VALUES:
    int mat[1][2] = 7;
    printf("%d", mat[1][2]);
        // != 6
        // == 7
```


### Exercise 1. Initializing & Printing 2D Array

- todo
  - declare & initialize a 2-D Array
  - print all of its values!

```c
#include <stdio.h>

int main(){

    int matrix[3][3];
    int i,j;

        // 1. Write the matrix
    for (i=0; i<3; i++){
        
        printf("Write ROW n.%d \n", i+1);
        for (j=0; j<3; j++){
            printf("- Write value n.%d: ", j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

        // 2. Print the matrix
    for (i=0; i<3; i++){

        for (j=0; j<3; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}
```


### Exercise 2. Multiplication Table

- todo
  - write code responsible for printing the multiplication table (1 to 10)
  - use a 2-D Array!

```c
#include <stdio.h>
#define SIZE 11

int main(){

    int i, j;
    int matrix[SIZE][SIZE];

    // 1. Fill values to the table
    for (i=1; i<SIZE; i++)
        for (j=1; j<SIZE; j++)
            matrix[i][j] = i*j;
    
    // 2. Print the multiplication table!
    for (i=1; i<SIZE; i++){
        for (j=1; j<SIZE; j++)
            printf("%d " , matrix[i][j]);
        printf("\n");
    }

    return 0;
}
```

> Change `SIZE` to extend table!


### Input to Element in a 2D Array

> See already done above in [2-D Excercise 1](#exercise-1-initializing--printing-2d-array)

### Physical Representation in Memory!

- elements' address in memory
- example
  - `printf("Element1 Address = %lu \n", &arr[1]);`
    - [ ] Research`%lu`!! // [wiki](/docs/wiki.md)
      - `%lu` == print memory address!!
- for 1-D Arrays, elements are stored sequentially "one after the other"

#### `%lu` for 1-D Arrays

```c
#include <stdio.h>

int main(){
    long arr[3]={1,2,3};
    int i;
    for (i=0; i<3; i++)
        printf("Element %d address = %lu \n", i+1, &arr[i]);
    return 0;
}
```
```markdown
Element 1 address = 140737488347232 
Element 2 address = 140737488347240 
Element 3 address = 140737488347248

8-bit/byte diff right?!

(ERROR: format '%lu' expects argument of type 'long unsigned int', but argument 3 has type 'long int *')
```
#### `%lu` for 2-D Arrays

```c
#include <stdio.h>

int main(){

    int mat[2][3]={{1,3,5}, {2,4,6}};
    int i, j;

    for (i=0; i<2; i++){
        for (j=0; j<3; j++){
        printf("Address of mat[%d][%d] = %lu \n", i, j, &mat[i][j]);
        }
    }

    return 0;
}
```
```markdown
Address of mat[0][0] = 140737488347232 
Address of mat[0][1] = 140737488347236 
Address of mat[0][2] = 140737488347240 
Address of mat[1][0] = 140737488347244 
Address of mat[1][1] = 140737488347248 
Address of mat[1][2] = 140737488347252

Still sequentually dawg!
```

> - [ ] Why diff ~8 VS ~4


#### conclusion

- Still sequentually ROW after ROW!


## Practicals #6

## 1. Copying an Array

- todo
  - write program to init array with 3 values
  - values = date: day+month+year (1,2,2000)
  - program creates 2nd array with same values!
  - print both arrays

```c
#include <stdio.h>

int main(){

    int arrA[3] = {24,1,2023};
    int arrZ[3];
    int i;

    for (i=0; i<3; i++){
        arrZ[i] = arrA[i];
        printf("arrA position %d = %d \n", i, arrA[i]);
        printf("arrZ position %d = %d \n", i, arrZ[i]);
    }

    return 0;
}
```


## 2. Palindrome Exercise

- todo
  - write program that checks and prints whether a given array is a palindrome

```c
#include <stdio.h>
#define SIZE 5

int main(){

    int arr[SIZE]={3,4,7,5,3};
    int i;
    int isPalindrome;
    int currentVal, matchingVal;    // innecessary, added for clarity

    for (i=0; i<SIZE/2; i++){

        currentVal = arr[i];
        matchingVal = arr[SIZE-(i+1)];
        printf("Current val = %d \n", currentVal);
        printf("Matching val = %d \n", matchingVal);

        if (currentVal==matchingVal){
            isPalindrome = 1;
        } else {
            isPalindrome = 0;
            break;
        }
    }

    printf("\nPalindrome candidate: ");
    for (i=0; i<SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    if (isPalindrome)
        printf("  SUCCESS! That is a Palindrome indeed! \n");
    else printf("  FAIL! Not a Palindrome because %d and %d fail to match! \n", currentVal, matchingVal);

    return 0;
}
```



## 3. Largest Neighbors Sum

- todo
  - write a program to calculate and print the largest sum of any two adjacent elements in an array
- example
  - 1,4,3,7,1: 10
  - 5,7,1,5,2: 12

```c
#include <stdio.h>
#define SIZE 5

int main(){

    int arr[SIZE]={3,6,9,2,5};
    int i;
    int currentSum, maxSum;

    for (i=0; i<SIZE; i++){
        currentSum = arr[i]+arr[i+1];
        // printf("Current sum = %d \n", currentSum); // TEST!!
        if (currentSum>maxSum)
            maxSum=currentSum;
    }

    printf("Max sum = %d \n", maxSum);

    return 0;
}
```

<details>
<summary>@Vlads</summary>

```c
#include <stdio.h>
#define SIZE 5

int main(){

    int arr[SIZE]={1,4,3,7,1};
    int i;
    int maxSum = arr[0]+arr[1];

    for (i=1; i<SIZE-1; i++){
        if (maxSum < arr[i]+arr[i+1])
            maxSum = arr[i]+arr[i+1];
    }

    printf("Max sum = %d \n", maxSum);

    return 0;
}
```
</details>


## 4. A Program to find if an Array is sorted

- todo
  - program that creates array of ints based on user input
  - check and print whether the array is sorted (increasing)
    - really sorted --> all increasing Left to Right
    - sorted --> all equal or increasing
    - not sorted --> any number not increasing Left to Right

```c
#include <stdio.h>
#define SIZE 5

int main(){

    int i;
    int arr[SIZE];
    int flag=2;     // 2=ReallySorted, 1=Sorted, 0=NotSorted

    for (i=0; i<SIZE; i++){
        printf("Enter n.%d/%d: ", i+1, SIZE);
        scanf("%d", &arr[i]);
    }

    for (i=1; i<SIZE; i++){
        if (arr[i-1] > arr[i]){
            flag = 0;
            break;
        } else if (arr[i-1] == arr[i])
            flag = 1;
    }

    if (flag==2)
        printf("Really sorted! \n");
    else if (flag==1)
        printf("Kinda sorted! \n");
    else if (flag==0)
        printf("Not sorted! \n");

    return 0;
}
```

<!--
### prototype 2
```c
#include <stdio.h>
#define SIZE 5

int main(){

    int i;
    int arr[SIZE];
    int isSorted, isReallySorted;

    for (i=0; i<SIZE; i++){
        printf("Enter n.%d/%d: ", i+1, SIZE);
        scanf("%d", &arr[i]);
    }

    for (i=0; i<SIZE; i++){

        if (arr[i] < arr[i-1]){
            printf("Array not sorted! \n");
            break;
        } else if (arr[i] > arr[i-1]) {
            isReallySorted = 1;
            isSorted = 0;
        } else if (arr[i] >= arr[i-1]) {
            isSorted = 1;
            isReallySorted = 0;
        }
    }

    if (isReallySorted)
        printf("Array is really sorted, always increasing! \n");
    else if (isSorted)
        printf("Array is sorted, never decreasing. \n");


    return 0;
}
```
-->



## 5. A Program to print and count all unique elements in an array

- todo
  - two programs
    - 1. Print all Unique Elements in an Array
    - 2. Count the number of Unique Elements in Array

```c
#include <stdio.h>
#define SIZE 10

int main(){

    int i, j;
    int foundDuplicate;
    int values[SIZE];
    int uniqueCount;

    for (i=0; i<SIZE; i++){
        printf("Enter n.%d/%d: ", i+1, SIZE);
        scanf("%d", &values[i]);
    }

    printf("\nUnique Values: ");

    for (i=0; i<SIZE; i++){

        for (j=0; j<SIZE; j++){
            if (i == j)
                continue;
            if (values[i] == values[j]){
                foundDuplicate=1;
                break;
            }
        }
        if (foundDuplicate!=1){
            printf("%d ", values[i]);
            uniqueCount++;
        }
        foundDuplicate=0;
    }

    printf("\nTotal Unique Nums: %d \n",uniqueCount);

    return(0);
}
```

<!--
### last prototype before Vlads
```c
#include <stdio.h>
#define SIZE 7

/*
    NOTA IMPORTANTE: j+1 ~~y luego tb j+1 para evitar "verse a sí mismo"~~
    - j+1 primera vez consigue que el 3 no se vea a sí mismo. Pero y luego el 6?
*/

int main(){

    int i, j;
    int arr[SIZE] = {2,3,4,2,5,6,7};
    int uniqueElement, notUnique;

    /*  USER INPUT - AFTER TEST OK
        for (i=0; i<SIZE; i++){
            printf("Enter n.%d/%d: ", i+1, SIZE);
            scanf("%d", &arr[i]);
        }
    */
    

    for (i=1; i<SIZE; i++){

        for (j=1; j<SIZE; j++){
            if (arr[i] == arr[j]){
            notUnique=1;
            break;
            } else if (arr[i]!=arr[SIZE-1]) {
                uniqueElement=1;
            }
        }

        if (uniqueElement)
            printf("%d is unique \n", arr[i]);
        else if (notUnique)
            printf("%d is NOT unique \n", arr[i]);
        
        uniqueElement=0;
        notUnique=0;
    
    }   



    printf("\n");
    return 0;
}
```

### Sample of correct approach

```c
// #define SIZE 6

int i, j;
int arr[SIZE] = {3,6,5,6,7,8};

for (i=0; i<SIZE; i++){
    printf("Running arr[i] %d against arr[j]: \n", arr[i]);
    for (j=0; j<SIZE; j++){
        printf(" arr[j] = %d \n", arr[j]);
    }
}
```
-->


## 6. A Program to count a total number of "non-unique" values in an array

- todo
  - Count the total values that are 'not unique' in a given array


```c
#include <stdio.h>
#define SIZE 5

int main(){

    int i, j;
    int values[SIZE];
    int nonUniqueCount;
    int foundDuplicate;

    for (i=0; i<SIZE; i++){
        printf("Enter num %d/%d: ", i+1, SIZE);
        scanf("%d", &values[i]);
    }

    printf("\nNon-Unique Values: ");
    for (i=0; i<SIZE; i++){
    
        foundDuplicate=0;

        for (j=0; j<i; j++){
            if (values[i] == values[j]){
                foundDuplicate = 1;
                break;
            }
        }
        if (foundDuplicate)
            break;
        else {
            for (j=i+1; j<SIZE; j++){
                if (values[i] == values[j]){
                    printf("%d ", values[i]);
                    nonUniqueCount++;
                    break;
                }
            }
        }
    }

    printf("\nTotal Non-Unique Values: %d \n", nonUniqueCount);

    return(0);
}
```



## 7. Rotate Elements in an Array
### 7.1 A Program to Rotate Left a given array by 1 position
### 7.2 A Program to Rotate Left a given array by N position
### 7.3 A Program to Rotate RIGHT a given array by N position
## 8. A Program to Find Two elements whose Sum is Closest to Zero
## 9. A Function to Calculate Any Array Sum [Intermediate]
## 10. A Function to Reset All Elements of An Array to 0 [Intermediate]
