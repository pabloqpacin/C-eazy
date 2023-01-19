# 4. Loops - For, While and Do-While

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

### Challenge #6b - Print Right Angle Triangle Pattern [2/2]

### Milestone #2 - 10 Cents Million Dollars!!