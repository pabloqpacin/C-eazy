# 3. Conditions 

> [SKIP TO THE PRACTICALS #3](#practicals-3)

## Conditions and Control Flow

### Introduction + Congratulations in C

- RECAP
  - we have learned
    1. Different types of numbers (integers, floating-point)
    2. Printing to screen
    3. Variables
    4. Read input from user
  - So far with our code, the program has run **sequencially** according with our commands
  - Need **control-flow** for programs (eg. videogame movement); need *conditions*

<details>
<summary>Example</summary>

```c
#include <stdio.h>


int main(){

    double grade;
    printf("Enter your grade: ");
    scanf("%lf", &grade);

    if (grade >= 60)
        printf("Congratulations! \n");
    else
        printf("Failed! \n");
    
    return 0;
}
```

</details>

### Finding Maximum between 2 numbers

```c
#include <stdio.h>


int main(){

    double num1, num2;
    
    printf("Enter two numbers: \n");
    scanf("%lf", &num1);
    scanf("%lf", &num2);
    
    if (num1 > num2)
        printf("MAX (1): %.2lf \n", num1);
    else
        printf("MAX (2): %.2lf \n", num2);
    
    return 0;
}
```

> notice how *(2)* is printed if the input is the same (eg. 5>5)

### Control Flow - Relational Operators

- **Relational Operators**: used in conditions for "question format"

> see [wiki](/docs/wiki.md)


### Challenge #1 - Find if number is Odd or Even

```c
#include <stdio.h>

int main(){

    int number;
    printf("Enter you number: ");
    scanf("%d", &number);

    if (number%2==0)
        printf("%d is an EVEN number! \n", number);
    else
        printf("%d is an ODD number! \n", number);
        
    return 0;
}
```


### Challenge #2 - print MIN and MAX

```c
#include <stdio.h>

int main(){

    double num1, num2;
    printf("Enter two numbers: \n");
    scanf("%lf", &num1);
    scanf("%lf", &num2);

    if (num1>num2)
        printf("MAX = %.2lf \nMIN: %.2lf \n", num1, num2);
    else
        printf("MAX = %.2lf \nMIN = %.2lf \n", num2, num1);

    return 0;
}

/* what if they're equal tho */
```

### Challenge #3 - min & max among 3 numbers (!)

<!-- strong logic... math game -->

```c
#include <stdio.h>

int main(){

    double a, b, c;
    double max, min;

    printf("Enter three numbers: \n");
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    // we assume these values
    max = a;
    min = b;    // but...
    
    if (a < b) {
        max = b;
        min = a;
    }       // now...

    if (max < c)
        max = c;
    if (c < min)
        min = c;

    printf("MAX = %.2lf \nMIN = %.2lf \n", max, min);

    return 0;
}
```

### Control Flow - Moving Forward! (`else if`)

<!-- RECAP
basic `if` and implied True or False, therefore execute command 1 or 2 -->

```c
#include <stdio.h>

int main(){

    int grade;
        printf("Enter your grade: ");
        scanf("%d", &grade);

    if (grade >= 80)
        printf("Yay! \n");
    else if (grade >= 60)
        printf("Keep it up! \n");
    else
        printf("Failed fool! \n");

    return 0;
}
```

> so how about curleys, when do we use them? only for blocks right?

### Logical Operators in C

- "AND", "OR", "NOT"
- operate with conditions (**1** AND **2**)
- form a *logical-end operator* ie. a new condition
- True or False? Truth Table! ([wiki](/docs/wiki.md))

in other words, we may have
- couple of operands
- couple of logical operators
- final result can be TRUE or FALSE

### Switch Case + FULL Example

- nested if VS case
- add `default` case for 'no-matches'

```c
#include <stdio.h>

int main()
{
    char grade;
    printf("Choose [a/b] : ");
    scanf("%c", &grade);
    
    switch(grade){
        case 'a':
            printf("Hello World! \n"); break;
        case 'b':
            printf("Sup Dawg! \n"); break;
        default:
            printf("Choose wisely... \n"); break;
    }

    return 0;
}
```

> command `break` added at the end of everycase so that, **if case is met**, `switch` will stop and move on!


### Milestone - Intermediate Calculator (using Switch Case)

- remember from [milestone1](/1-C_Basics/Milestone1-Calculator.c)
- todo
  - read 2 numbers from user
  - read 1 char (+, -, *, /, %)
  - print operation result
  - USE SWITCH CASES!
  - careful with 0 divisions

```c
#include <stdio.h>

int main(){

    double num1, num2, result;
    char sign;

    printf("Enter the two numbers: \n");
    scanf("%lf", &num1);
    scanf("%lf", &num2);
    printf("Operation sign: \n");
    scanf("%c", &sign);
    scanf("%c", &sign);
    // why does my program need two lines?
        // one only gets skipped

    switch (sign){
        case '+':
            result = num1 + num2; break;
        case '-':
            result = num1 - num2; break;
        case '*':
            result = num1 * num2; break;
        case '/':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");
            result = num1 / num2; break;
        case '%':
            if (num2 == 0)
                printf("You cannot divide by 0! \n");

            result = (int)num1 % (int)num2; break;
        default:
            printf("Operation not accepted. Please try again. \n"); break;
    }

    // if (result==True) // how to denote results are ok thus operation completed
    printf("%.1lf %c %.1lf = %.2lf \n\n", num1, sign, num2, result);

    return 0;
}
```

> fairly different than Vlad's

### Conditions Assignment (!)

1. Write a program that reads from the user 2 values of an "integer" type. The program should print "EQUAL" if both the values are equal. Otherwise, the program should print "NOT EQUAL".

```c
#include <stdio.h>

int main(){

    int num1, num2;

    printf("Enter two numbers: \n");
    scanf("%d", &num1);
    scanf("%d", &num2);

    if (num1 == num2)
        printf("EQUAL \n");
    else
        printf("NOT EQUAL \n");

    return 0;
}
```

2. Write a program that reads from the user 3 values of an "integer" type. The program should print "EQUAL" if all the values are equal. Otherwise, the program should print "NOT EQUAL".

Note: There's more than just 1 "correct" solution for this question.


```c
#include <stdio.h>

int main()
{
	int a, b, c;
	printf("Enter the first value: ");
	scanf("%d", &a);
	printf("Enter the second value: ");
	scanf("%d", &b);
	printf("Enter the third value: ");
	scanf("%d", &c);

	if (a == b && b == c)
		printf("EQUAL\n");
	else
		printf("NOT EQUAL\n");

	return 0;
}
```


3. Write a program that reads from the user a "three-digit" integer value. The program should print "ASCENDING" if the three digits of the number are in ascending order (from left to right). If not, the program should print "NOT ASCENDING".

For example:
- Input: 137 --> ASCENDING (1<3<7)
-  Input: 143 --> NOT ASCENDING.

```c
#include <stdio.h>

int main(){

    int number;
    int units, tens, hundreds;
    printf("Enter a 3-digit number: \n");
    scanf("%d", &number);

    units = number % 10;
    tens = (number / 10) % 10;
    hundreds = number / 100;

    if (hundreds < tens && tens < units)
        printf("ASCENDING! (%d < %d < %d) \n", hundreds, tens, units);
    else
        printf("NOT ASCENDING... \n");

    return 0;
}
```


4. Write a program that reads an input number from the user. The program should print "1" if the value is positive, "-1" if it's negative, and "0" if it equals to zero.


```c
#include <stdio.h>

int main(){

    int number;
    printf("Enter your fave number: \n");
    scanf("%d", &number);

    if (number>0)
        printf("1 \n");
    else if (number<0)
        printf("-1 \n");
    else    // num == 0
        printf("0 \n");

    return 0;
}
```

## Practicals #3

