# 4. Loops - For, While and Do-While

> skip to [practicals #4](#practicals-4)

## Introduction

- iterations VS scripted sequence
- section contents
  1. "Concept of Loops"
  2. Types of loops [While, For]
  3. What is an "iteration"?
  4. Getting out of a loop
  5. "Control Flow" & Conditions
  6. Nested loops (opt.)

Why using Loops?
- Types of Loops
  - *"While"* Loop
  - *"Do-While"* Loop
  - *"For"* Loop
- Choose depending on the task!!


<!-- PROTOTYPE
```c
#include <stdio.h>

int main(){

    int num, pow, result;
    printf("Enter 'a' number [a^b]: ");
    scanf("%d", &num);
    printf("Enter 'b' number [a^b]: ");
    scanf("%d", &pow);

    while (pow != 0)
        pow -= 1;
        result += num * num;

    printf("%d to the power of %d == %d \n", num, pow, result);

    return 0;
}
-->

## **While Loops**

Structure
- `while`
- Condition -- True?
  - Loop Body
- Condition -- False?
  - Break

> The executino of the "loop body", from top to bottom is called an **"iteration"**.

EXAMPLE:

```c
#include <stdio.h>

int main(){

    int count = 0;

    while (count < 10){
        printf("*");
        count += 1;
    }

    printf("\n10 stars printed dawg! \n");

    return 0;
}
```


### Challenge #1 - Printing any number of asterisks

- todo
  - gets number of stars from user
  - print such number of asterisks


```c
#include <stdio.h>

int main(){

    // i = count // i++ = 'i += 1'
    int num, i=0;
    
    printf("Enter the number of asterisks ya want printed: ");
    scanf("%d", &num);

    while (i < num){
        printf("*");
        i++;

        if (i%10==0)
            printf("\n");
    }

    printf("\n%d asterisks printed dawg! \n", i);
    return 0;
}
```

### Challenge #2 - Adding Pow to Calculator!

- todo
  - receive two inputs: number & power
  - print the result of number^power


```c
#include <stdio.h>

int main(){

    int num, pow;
    int i, result=1;   // result 1 for multiplication below // i = tempPow

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a POWER: ");
    scanf("%d", &pow);

    i=pow;

    while (i > 0){
        result = result * num;
        i--;
    }

    printf("%d to the power of %d = %d \n", num, pow, result);
    return 0;
}
```

### Milestone #1 - Coolest Average Grade Calculator

- todo
  - receive grades - until "stopping condition" met <!-- SC: grade = -1 -->
  - calculate & print average grade


```c
#include <stdio.h>

int main(){

    int numGrades, tempNumGrades;
    double gradeN;
    double average;

    printf("Number of grades: ");
    scanf("%d", &numGrades);
    
    tempNumGrades = numGrades;

    while (tempNumGrades > 0){
        printf("Enter grade: ");
        scanf("%lf", &gradeN);
        
        average = (gradeN + average);
        tempNumGrades--;
    }

    average = average / numGrades;
    printf("Your average = %.2lf \n", average);

    return 0;
}
``` 

<details>
<summary>@Vlad's</summary>

```c
#include <stdio.h>

int main()
{
    int grade;
    int totalSum = 0, gradesCount = 0;
    
    printf("Please enter your grades or '-1' to stop : ");
    scanf("%d", &grade);
    
    while (grade != -1)
    {
        totalSum = totalSum + grade;
        gradesCount++;
        printf("Please enter your grades or '-1' to stop: ");
        scanf("%d", &grade);
    }
    
    printf("You've entered %d grades! \n", gradesCount);
    if (gradesCount != 0)
        printf("And your AVERAGE GRADE is %f \n", (float)totalSum / gradesCount);
    
    return 0;
}
```
</details>


## **Do-While Loops**

> use to AVOID DUPLICATION!!
> 
> use Do-While loops if there will commands executed both *before* and *during* the loop

```c
// WHILE LOOP!
#include <stdio.h>

int main(){

    int price, totalPrice=0;

    printf("Please enter a price: ");
    scanf("%d", &price);

    while (price != 0){
        totalPrice = totalPrice + price;
        printf("Please enter a price: ");
        scanf("%d", &price);
    }

    printf("Total Order Price = %d \n", totalPrice);
    return 0;
}
```

```c
// DO-WHILE LOOP!!
#include <stdio.h>

int main()
{
    int price, totalPrice = 0;
    do {
        printf("Please enter a price: ");
        scanf("%d", &price);
        totalPrice = totalPrice + price;
    } while (price != 0);

    printf("Total Order Price = %d \n", totalPrice);
    return 0;
}
```


### Challenge #3 - Enter a legal grade!

- todo
  - read valid input (0-100)
  - return such grade if legal 

```c
#include <stdio.h>

int main(){

    int grade;

    do {
        printf("Enter grade (0-100): ");
        scanf("%d", &grade);
    } while (grade < 0 || grade > 100);

    printf("Yay, %d is valid \n", grade);

    return 0;
}
```

> Bash `until` loops vibes...

## **For Loops** <!--countin loops-->

structure
- specify "For" statement
- specify "For" sections
  - "initialization" statement [1] <!--variables init-->
  - "loop condition" (True OR False)
  - (body)
  - "Update" statement --> end of *iteration*
- Loop body

example breakdown

| phase     | code       |
| ---       | ---        |
| init      | `i= 1`     |
| condition | `i <= num` |
| update    | `i++`      |


```c
/* print all numbers between i and num */

#include <stdio.h>

int main()
{
	int num;
	int i;

	printf("Hello! Enter a number: ");
	scanf("%d", &num);

	for (i = 1; i <= num; i++){
		printf("%d ", i);
	}
	return 0;
}
```

<!-- SUPER AVOID REPETITION DAWG -->


### Challenge #4 - Adding POW (using For Loops)

- todo
  - read two values (num & pow)
  - print num^pow

```c
#include <stdio.h>

int main()
{

    int num, pow;
    int result=1;
    int i;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a POWER: ");
    scanf("%d", &pow);

    for (i = pow; i > 0; i--){
        result*=num;
    }
        printf("%d to the power of %d = %d \n", num, pow, result);
    	return 0;
}
```

<details>
<summary>@Vlad's</summary>

```c
#include <stdio.h>

int main()
{
    int num, pow;
    int result = 1;
    int i;

    printf("Enter num: ");
    scanf("%d", &num);
    printf("Enter power: ");
    scanf("%d", &pow);

    for (i = 1; i <= pow; i++)
    {
        result = result * num;
    }

    printf("%d in the POWER of %d = %d\n", num, pow, result);

    return 0;
}
```

</details>

### Challenge #5 - Punishment!

- todo
  - user input = 100x "Practise!"

```c
#include <stdio.h>

int main()
{

    int i=1;

    // do{
    //     printf("Practise! (%d) \n", i);
    //     i++;
    // } while (i<=100);

    for(i=1;i<=100;i++){
        printf("Practise! (%d) \n", i);
    }

    return 0;
}
```

## **Nested Loops**

### Challenge #6a - Print Right Angle Triangle Pattern [1/2]

- todo
  - receive integer "n"
  - print right angle triangle —as shown below—

```markdown
n=3
1
12
123
```

```c
#include <stdio.h>

int main(){

    int i, j;
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        for(j=1; j<=i; j++)
            printf("%d", j);
        printf("\n");
    }

    return 0;
}
```

<!--
#### prototype 1

```c
#include <stdio.h>

int main(){

    int n;
    int i, pattern;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    for (i=1, pattern=1; i < n; i++, pattern+=(i*10)+1 ){
        printf("%d \n", pattern);
    }


    return 0;
}
```
-->

### Challenge #6b - Print Right Angle Triangle Pattern [2/2]

- todo
  - receive integer n
  - print triangle like:

```markdown
n=3
1
22
333
```

```c
#include <stdio.h>

int main(){

    int i, j;
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for (i=1; i<=n; i++){
        for(j=1; j<=i; j++)
            printf("%d", i);
        printf("\n");
    }

    return 0;
}
```


### Milestone #2 - 1 Cent VS 1 Million Dollars!!

```c
/* 
    Milestone #2 - 1 Cent VS 1 Million Dollars!!

    What is better?
    a) 1 Million dollars, right now
    b) 1 cent, doubles every day for 30 days

*/

#include <stdio.h>

int main(){

    int i;
    double total=0.01;

    for (i=1;i<=30;i++){
        printf("Day %.2d = %.2lf $ \n", i, total);
        total*=2;
    }

    return 0;
}
```


<!-- PROTOTYPE
```c
#include <stdio.h>

int main(){

    int total=1, i;

    for (i=1;i<=30;i++){
        printf("Day %.2d = %.2lf $ \n", i, (double)total/100);
        total*=2;
    }

    return 0;
}
```
-->


## Practicals #4

### 1. Print from 1 to num and viceversa

- todo
  - receive "num" from user
  - print all integers from 1 to "num" and viceversa

```c
#include <stdio.h>

int main(){

    int num;
    int i;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i=1; i<=num; i++)
        printf("%d ", i);
    printf("\n");

    for (i=num; i>=1; i--)
        printf("%d ", i);
    printf("\n");

    return 0;
}
```

### 2. Print the sum of all numbers from 1 to num

- todo
  - receive "num" from user
  - print the SUM of all integers from 1 to "num"

```c
#include <stdio.h>

int main(){

    int num, sum;   // int temp not to lose num in while loop
    int i;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Arithmetic Formula
    // sum = (1+num) * num / 2;

    // while (num>=1){
        // sum+=num;
        // num--;
    // }

    for (i=1;i<=num;i++)
        sum+=i;
    
    printf("Sum dawg: %d \n", sum);

    return 0;
}
```

### 3. Print the Multiplication Table of a number

- todo
  - receive num & limit
  - print multiplication table UNTIL limit


```c
#include <stdio.h>

int main(){

    int num, limit;
    int i;

    printf("Enter number: ");
    scanf("%d", &num);
    printf("Enter limit: ");
    scanf("%d", &limit);

    for (i=1;i<=limit;i++)
        printf("%d x %d = %d \n", num, i, (num*i));

    return 0;
}
```

### 4. Print n even natural numbers

- todo
  - receive num
  - print num times even numbers

```c
#include <stdio.h>

int main(){

    int num;
    int i;

    printf("Enter number: ");
    scanf("%d", &num);

    for (i=1;i<=num;i++)
        printf("%d ", i*2);

    printf("\n");
    return 0;
}
```

### 5. Print Pyramid Numbers Pattern

- todo
  - receive integer "n"
  - print pyramid with following pattern

```markdown
n=3
  1  
 3 2
4 5 6
```

```c
#include <stdio.h>

int main(){

    int n;
    int i, j, k;
    int blankSpaces;
    int currentValue=1;

    printf("Enter 'n' (number of rows in pyramid): ");
    scanf("%d", &n);

    blankSpaces=n-1;
   
    // Iterate over all of the rows
    for (i=1;i<=n;i++){
        
        // Add row spacez
        for (k=blankSpaces; k>=1; k--)
            printf(" ");

        // Add row numberz
        for (j=1;j<=i;j++){
            printf("%d ", currentValue);
            currentValue++;
        }
        
        // Change rowz
        printf("\n");
        blankSpaces--;

    }
    return 0;
}

/* in row 5 and beyond, should have one less num printed dawg */
```

### 6. Print Sum of Values Divisible by 3 AND 5

- todo 
  - efficient program receive "num" from user
  - print the SUM of all numbers from "1" to "num" that can be divided by 3 AND by 5


```c
#include <stdio.h>

int main(){

    int num, sum;
    int i;

    printf("Enter your number: ");
    scanf("%d", &num);

    /* Trivial
    for (i=1;i<=num;i++){
        if (i%3==0 && i%5==0){
            sum+=i;
            printf("i%d:Sum%d ", i, sum);   // control-print
        }
    }
    */

   // Efficient
    for (i=15;i<=num;i+=15)
        sum+=i;

    printf("\n SUM = %d \n", sum);

    return 0;
}
```

> "Efficient" = few iterations!


### 7. Print Sum of Values Divisible by 3 OR 5


```c
#include <stdio.h>

int main(){

    int num, sum;
    int i;

    printf("Enter your number: ");
    scanf("%d", &num);

    /* Trivial
    for (i=1;i<=num;i++){
        if (i%3==0 || i%5==0)
            sum+=i;
        printf("%d ", sum);     // control-print
    }
    */

    // Efficient
    for (i=3; i<=num; i+=3)
        sum+=i;

    for (i=5; i<=num; i+=5){
        if (i%3!=0)
        sum+=i;
    }

    printf("\nSUM = %d \n", sum);

    return 0;
}
```

### 8. Very Ascending or Not

- todo
  - receive "size" value from user
  - read sequence of "numbers" (sequence lenght = "size")
  - determine whether numbers in sequence are "Very Ascending"
  - example: size=7: 1,9,14,15,18,21,26: Very Ascending
  - example: size=3: 2,1,10: NOT Very Ascending


```c
/*
    j = last num
    k = new num
    if at any time k > j, veryAscending will equal 0
*/

#include <stdio.h>

int main(){

    int size;
    int i, j=1, k;
    int VeryAscending=1;
    // char VeryAscending='T';
    
    printf("Enter 'size' of sequence: ");
    scanf("%d", &size);

    if (size<=0)
        printf("Please, try again.\n");
        
    else{

        printf("Enter sequence: ");

        for (i=1; i<=size; i++){
            j=k;
            scanf("%d", &k);
            if (k<=j)
            VeryAscending=0;
            //VeryAscending='F';
        }

        // printf("Very ascending [T/F]: %c \n", VeryAscending);
        if (VeryAscending)
            printf("Very Ascending sequence \n");
        else
            printf("NOT Very Ascending! \n");

    }

    return 0;
}
```

<details>
<summary>@Vlad's</summary>

```c
/*
    j = last value
    k = current value
*/

#include <stdio.h>

int main(){

    int size;
    int j, k;
    int OK=1;

    do {
        printf("Enter sequence size (must be greater than 0): ");
        scanf("%d", &size);
    } while (size<=0);


    do {
        printf("Insert value: ");
        scanf("%d", &k);
        if (k<0)
            printf("Number must be positive! \n");
        else{
            if (k<=j){
                OK=0;
                break;
            }
            j=k;
            size--;
        }
    } while (size>0);

    if (OK)
        printf("Very Ascending sequence \n");
    else
        printf("NOT Very Ascending! \n");

    return 0;
}
```

</details>


> (only positive values in this case)
>
> notice:
> - **safety-guard** if-statement
> - @Vlad's **safety-guard** do-while loop!!
> - @Vlad's **break** do-while loop within if-statement


<!-- LAST PROTOTYPE
```C
/*
    j = last num
    k = new num
    if at any time k > j, veryAscending will equal 0
*/

#include <stdio.h>

int main(){

    int size;
    int i, j=1, k;
    int VeryAscending=1;
    // char VeryAscending='T';

    do{
    printf("Enter 'size' of sequence: ");
    scanf("%d", &size);
        if (size<=1)
            printf("Please, try again.\n");
    } while (size<=1);


    // printf("Enter 'size' of sequence: ");
    // scanf("%d", &size);

    // if (size<=0)
    //     printf("Please, try again.\n");
        
    // else{

        printf("Enter sequence: ");

        for (i=1; i<=size; i++){
            j=k;
            scanf("%d", &k);
            if (k<=j)
            VeryAscending=0;
            //VeryAscending='F';
        }

        // printf("Very ascending [T/F]: %c \n", VeryAscending);
        if (VeryAscending)
            printf("Very Ascending sequence \n");
        else
            printf("NOT Very Ascending! \n");

    // }

    return 0;
}
```
-->


### *9*. Subtracting EvenDigitSum and OddDigitSum

- todo
  - receive num; mind digits
  - find difference between (a) sum of all even digits and (b) sum of all odd numbers

```c
#include <stdio.h>

int main(){

    int num;
    int evenSum, oddSum;
    int digit;

    printf("Enter num: ");
    scanf("%d", &num);

    while (num>0){
        digit=num%10;
        if (digit%2==0)
            evenSum+=digit;
        else
            oddSum+=digit;
        num/=10;
    }

    printf("EVEN minus ODD digits = %d \n", evenSum-oddSum);

    return 0;
}
```


<!--
#### prototype 2

```c
#include <stdio.h>

int main(){

    int num=124, evenSum, oddSum;
    int i, digit, tempNum;

    /* // let's start with fixed num=12
    printf("Enter your number: ");
    scanf("%d", &num);
    */


    for (tempNum=num;tempNum>=1;tempNum/10){
        digit=tempNum%10;
        printf("%d ", digit);


        if (digit%2==0)
            evenSum+=digit;
        else if (digit%2!=0)
            oddSum+=digit;
        else
            printf("Bugz \n");
    }


    printf("DIFF = %d \n", evenSum-oddSum);




/*
    do{
        
        tempNum/10;
    } while (tempNum/10>10);
    

    /*  PROTOTYPE 1
    for (tempNum=num;tempNum/10>10;tempNum/10){
        digit=tempNum;
        printf("%d", tempNum);
        printf("%d", digit);
        if (digit%2==0)
            evenSum+=digit;
        else if (digit%2!=0)
            oddSum+=digit;
        else
            printf("Bugz \n");
    }
    */


    return 0;
}
```

#### protoype 1

```c
#include <stdio.h>

int main(){

    int num=124, evenSum, oddSum;
    int i, digit, tempNum;

    /* // let's start with fixed num=12
    printf("Enter your number: ");
    scanf("%d", &num);
    */

    /*
    tempNum=num;
    do{
        tempNum/10
    } while (tempNum/10>10)
    */

    for (tempNum=num;tempNum/10>10;tempNum/10){
        digit=tempNum;
        printf("%d", tempNum);
        printf("%d", digit);
        if (digit%2==0)
            evenSum+=digit;
        else if (digit%2!=0)
            oddSum+=digit;
        else
            printf("Bugz \n");
    }

    printf("DIFF = %d \n", evenSum-oddSum);
    printf("digit = %d \n", digit);

    return 0;
}
```
-->

### *10*. Sum of Odd Numbers Sequence

- todo
  - receive "n" number from user
  - receive "n" integers
  - printf sum of all ODD given numbers 

```c
#include <stdio.h>

int main(){

    int n;
    int num, oddSum;
    int i;

    printf("Enter the 'n' number of integers: ");
    scanf("%d", &n);

    for (i=1;i<=n;i++){
        printf("Enter integer n.%d: ", i);
        scanf("%d", &num);
        if (num%2!=0)
            oddSum+=num;
    }

    printf("Sum of ODD numbers provided: %d \n", oddSum);
    return 0;
}
```