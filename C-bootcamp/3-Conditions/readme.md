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

### 1. Check if Numbers are the same

- todo
  - receive 2 numbers
  - if they are the same print True
  - otherwise print False

```c
#include <stdio.h>

int main(){

    double a, b;
    printf("Enter two numbers: \n");
    scanf("%lf", &a);
    scanf("%lf", &b);

    if (a == b)
        printf("True \n");
    else
        printf("False \n");

    return 0;
}
```

### 2. Check if a number is double-digit or triple-digit

```c
#include <stdio.h>

/* todo: tweak for negative numbers
(btw number variable CAN'T be 'double' if 'switch' ??) */

int main(){

    int number;
    printf("Enter your number: ");
    scanf("%d", &number);

    if (number >= 10 && number < 100)
        printf("%d = double-digit \n", number);
    else if (number >= 100 && number < 1000)
        printf("%d = triple-digit \n", number);
    else    //  (number < 10 OR number >= 1000)
        printf("%d = neither double/triple-digit \n", number);

    return 0;
}
```

### 3. Print the Absolute Number

```c
#include <stdio.h>

int main(){

    int num;
    printf("Enter your number: ");
    scanf("%d", &num);

    if (num>=0)
        printf("|%d| \n", num);
    else if (num<0)
        printf("|%d| \n", (-1)*num);
    
    return 0;
}
```

### 4. Quadrant of a Point

- todo
  - receive coordinate point in XY system [ie. 1(X,Y), 2(-X,Y), 3(-X,-Y), 4(X,-Y)]
  - print quadrant

```c
#include <stdio.h>

/* THIS WON'T WORK:
    switch(quadrant){
        case (x>0 && y>0):
            quadrant="1";
*/

int main(){

    int x, y;
    int quadrant;

    printf("Enter the X coordinate: ");
    scanf("%d", &x);
    printf("Enter the Y coordinate: ");
    scanf("%d", &y);

    if (x>0 && y>0)
        quadrant=1;
    else if (x<0 && y>0)
        quadrant=2;
    else if (x<0 && y<0)
        quadrant=3;
    else if (x>0 && y<0)
        quadrant=4;

    printf("Your point (X=%d, Y=%d) is in... quadrant %d! \n", x, y, quadrant);

    return 0;
}
```

### 5. Month Number to Month Name

- todo
  - receive number representing month
  - print month name

```c
#include <stdio.h>

// DO WITH 'month string' to follow 2.4 structure

int main(){

    int num;
    printf("Enter the number of month [1-12]: ");
    scanf("%d", &num);

    switch(num){
        case 1:
            printf("Month %d = January \n", num); break;
        case 2:
            printf("Month %d = February \n", num); break;
        case 3:
            printf("Month %d = March \n", num); break;
        case 4:
            printf("Month %d = April \n", num); break;
        case 5:
            printf("Month %d = May \n", num); break;
        case 6:
            printf("Month %d = June \n", num); break;
        case 7:
            printf("Month %d = July \n", num); break;
        case 8:
            printf("Month %d = August \n", num); break;
        case 9:
            printf("Month %d = September \n", num); break;
        case 10:
            printf("Month %d = October \n", num); break;
        case 11:
            printf("Month %d = November \n", num); break;
        case 12:
            printf("Month %d = December \n", num); break;
        default: // num<1 || num>12
            printf("Pleease try again...");
    }

    return 0;
}
```

### 6. Unique Clock Representation

- todo
  - receive int for seconds
  - convert seconds into
    - total hours
    - total minutes
    - remaining seconds
  - format: HH:MM:SS

```c
#include <stdio.h>

int main(){

    int seconds;
    int hours, minutes, remainingSeconds;

    printf("Enter the total seconds: ");
    scanf("%d", &seconds);

    hours = seconds/3600;
    minutes = (seconds - (hours*3600)) / 60;
    remainingSeconds = (seconds - (hours*3600)) % 60;

    printf("%.2d:%.2d:%.2d \n", hours, minutes, remainingSeconds);

    return 0;
}
```

<!-- remember exercise from Section 2
Here the guy wanted an if-statement where if num<10 then printf0 before the printf num-->

### 7. Divisible 3 Numbers (Example)

- todo
  - receive 3 integers
  - print "Divisible" if 'in each pair between the 3 numbers there is at least one number that can be divided by the other - without a remainder' (eg. [2,4,7]=NonDivisible)

```c
#include <stdio.h>

int main(){

    int a, b, c;
    printf("Enter a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);
    
    if (a==0 || b==0 || c==0)
        printf("Cannot divide by 0! Try again. \n");
    else if ((a%b==0 || b%a==0) && (a%c==0 || c%a==0) && (b%c==0 || c%b==0))
        printf("Divisable Numbers! \n");
    else
        printf("Non Divisable Numbers! \n");

    return 0;
}
```

<details>
<summary>ChatGPT</summary>

#### ChatGPT on `if` statements

> Here is an example of a C program that takes in 3 integers from the user and checks if they are divisible by each other:

```c
#include <stdio.h>

int main() {
    int num1, num2, num3;
    printf("Enter three integers: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    int divisible = 0;
    if (num1 % num2 == 0 || num1 % num3 == 0) divisible = 1;
    if (num2 % num1 == 0 || num2 % num3 == 0) divisible = 1;
    if (num3 % num1 == 0 || num3 % num2 == 0) divisible = 1;

    if (divisible) printf("DIVISIBLE\n");
    else printf("NON-DIVISIBLE\n");

    return 0;
}
```

<!--
Could you explain why `if (divisible) printf("DIVISIBLE\n");` is considered correct C syntax?
-->

>The `if` statement in C is used to control the flow of execution in a program. The basic syntax for an `if` statement is:

```c
if (condition) {
    // code to be executed if condition is true
}
```

> In this case, the `condition` is `divisible`, which is a variable that is set to 1 if any of the three numbers entered by the user is divisible by any of the other two numbers. If `divisible` is **true (i.e., if it has a non-zero value)**, the code inside the curly braces `{}` will be executed. In this case, the code inside the curly braces is `printf("DIVISIBLE\n");` which prints the string "DIVISIBLE" to the screen, followed by a new line.
> 
> It's also possible to use the shorthand for if statement in C which is:

```c
if (condition) statement;
```

> In this case, `printf("DIVISIBLE\n");` is the statement that will be executed if the condition is true.
> 
> The `if` statement is a fundamental control structure in C, and it's used in many different types of programs. It allows you to make decisions based on the current state of your program and take appropriate action based on those decisions.



</details>

<!--

#### prototypez

```c
#include <stdio.h>

int main(){

    int a, b, c;
    printf("Enter 3 integers: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    if (((a%b)==0) && ((a%c)==0));
    else if (((b%a)==0) && ((b%c)==0));
    else if (((c%a)==0) && ((c%b)==0))
        printf("DIVISIBLE \n");
    else
        printf("NON-DIVISIBLE \n");

    return 0;
}
```


```c
#include <stdio.h>

int main(){

    int a, b, c;
    printf("Enter 3 integers: \n");
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int aRem, bRem, cRem, totalRem;
    aRem = a%b + a%c;
    bRem = b%a + b%c;
    cRem = c%a + c%b;
    totalRem= aRem+bRem+cRem;

    if (aRem==0)
        printf("DIVISIBLE \n");
    else
        printf("NON-DIVISIBLE \n");

    return 0;
}
```
-->

### 8. Is Leap Year

- todo
  - determine given year is Leap or nay
  - conditions
    - if year%4==0 probably Leap
    - if year%100==0 not Leap
    - if year%400==0 then Leap

> documentation: @Microsoft: [Method to determine whether a year is a leap year](https://learn.microsoft.com/en-us/office/troubleshoot/excel/determine-a-leap-year)

```c
#include <stdio.h>

int main()
{
    int year; 
    printf("Enter a year: ");
    scanf("%d", &year);

    if (year % 400 == 0)
        printf("%d is a leap year\n", year);
    else if (year % 100 == 0)
        printf("%d is NOT a leap year\n", year);
    else if (year % 4 == 0)
        printf("%d is a leap year\n", year);
    else
        printf("%d is NOT a leap year\n", year);
    return 0;
}
```

<!--
#### prototypez

```c
#include <stdio.h>

int main(){

    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    if ((year%4==0) && (year%100!=0) && (year%400==0))
        printf("%d is a Leap Year! \n", year);
    else
        printf("%d is NOT a Leap Year! \n", year);

    return 0;
}
```

```c
#include <stdio.h>

int main(){

    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    if ((year%4==0) && (year%400==0))
        printf("%d is a Leap Year! \n", year);
    else if (year%100==0)
        printf("%d is NOT a Leap Year! \n", year);
    else
        printf("Something went wronk... \n");

    return 0;
}
```
-->

### 9. Find the next day on Calendar!

- todo
  - receive day, month and year
  - find and print the next day on the calendar
    - mind month-changes


```c
#include <stdio.h>

int main (){

    int day, month, year;
    int leapYear = 0;
    
    printf("Enter DAY number: ");
    scanf("%d", &day);
    printf("Enter MONTH number: ");
    scanf("%d", &month);
    printf("Enter YEAR number: ");
    scanf("%d", &year);

    if (month == 2)
        if (year%4==0 && year%100!=0 || year%400==0){
            leapYear = 1;}

    day += 1;

    switch (month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (day<=31) break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (day<=30) break;
        case 2:
            if (day <= 29 && leapYear == 1) break;
            else if (day <= 28) break;
        default:
            day = 1;
            month += 1;
            if (month > 12){
                month = 1;
                year += 1;
            }
    }

    printf("Next day is: %.2d/%.2d/%d \n\n", day, month, year);

    return 0;
}
```

<!--
> Protoypez:
>
> - Initial focus of getting either `nextEvenYear` or `nextOddYear`


#### prototypez

##### 1.

```c
#include <stdio.h>

// 3.9. Find the next day on Calendar!

int main()
{
    int day, month, year;
    int nextDay, nextMonth, nextYear;
    int leap; // 0 means no, 1 yes // mind february

    printf("Enter (date) 3 numbers  [day, month, year]: ");
    scanf("%d%d%d", &day, &month, &year);

    if day
    nextDay=day+1


    if (nextDay==1);
        else if (month<12)
            nextMonth=month+1;
        else if (month==12)
            nextMonth=1;
        else if ();
    
    printf("Next day will be %d %d %d: ", day, month, year);


    return 0;
}

```

##### 2.
```c
#include <stdio.h>

// 3.9. Find the next day on Calendar!

int main()
{
    int day, month, year;
    int nextDay, nextMonth, nextEvenYear, nextLeapYear;
    int leap; // 0 means no, 1 yes // mind february

    printf("Enter (date) 3 numbers [day, month, year]: ");
    scanf("%d%d%d", &day, &month, &year);

    /* activate implicit Leap variable, ie.
    nextYear will be either Even or Odd:
      if Even, only nextEvenYear will have
      a value other than 0 so will be called */
    if ((year % 400 == 0) && (year % 4 == 0))
        nextLeapYear=year+1;
    else
        nextEvenYear=year+1;
      
    if (nextLeapYear)
        printf("Next day will be %d %d %d: \n\n", nextDay, nextMonth, nextLeapYear);
    if (nextEvenYear)
        printf("supdawg \n");

    return 0;
}
```

##### 3.

```c
#include <stdio.h>

// 3.9. Find the next day on Calendar!

int main()
{
    int day, month, year;
    int nextDay, nextMonth, nextYear, nextLeapYear;
    int JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC;

    printf("Enter (date) 3 numbers [day, month, year]: ");
    scanf("%d%d%d", &day, &month, &year);


    // Determine whether 'year' will turn into 'nextYear' or 'nextLeapYear'
    if ((year % 400 == 0) && (year % 4 == 0))
        nextLeapYear=year+1;
    else
        nextYear=year+1;

    // Determine what 'month' will become
    switch(month){
        case 1:



    }




    
    if (nextLeapYear && (month==2) && (day==28))



    if (nextYear)




    if (nextLeapYear)
        printf("Next day will be %d %d %d: \n\n", nextDay, nextMonth, nextLeapYear);
    if (nextYear)
        printf("supdawg \n");

    return 0;
}
```


##### 4. (!)


```c
#include <stdio.h>

// 3.9. Find the next day on Calendar!

int main()
{
    int day, month, year;
    int nextDay, nextMonth, nextYear, nextLeapYear;
    // int JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC;

    printf("Enter (date) 3 numbers [day, month, year]: ");
    scanf("%d%d%d", &day, &month, &year);


    // Determine whether 'year' will turn into 'nextYear' or 'nextLeapYear'
    if ((year % 400 == 0) && (year % 4 == 0))
        nextLeapYear = year + 1;
    else
        nextYear = year + 1;

    // Determine 'nextMonth'
    switch (month){
        case 1:
            nextMonth = month+1; break;
        case 2:
            nextMonth = month+1; break;
        case 3:
            nextMonth = month+1; break;
        case 4:
            nextMonth = month+1; break;
        case 5:
            nextMonth = month+1; break;
        case 6:
            nextMonth = month+1; break;
        case 7:
            nextMonth = month+1; break;
        case 8:
            nextMonth = month+1; break;
        case 9:
            nextMonth = month+1; break;
        case 10:
            nextMonth = month+1; break;
        case 11:
            nextMonth = month+1; break;
        case 12:
            nextMonth = 1; break;
        default:
            printf("Buggey \n");
    }

    // // DAYZ
    // switch (nextMonth){
    //     case 1:
    //         if ((day >= 1) && (day < 31)) // ensure day can only be between 1 and 31... otherwise see 'default'
    //             nextDay = day + 1;
    //         else //
    //             nextDay = 1;
    //     default: printf("BUGZ. Please try again \n");
    // }

  
    // if (nextLeapYear && (month==2) && (day==28))

    // if (nextYear)

    if (nextYear)
        printf("Next day will be %d %d %d: \n\n", nextDay, nextMonth, nextYear);
    if (nextLeapYear)
        printf("Next day will be %d %d %d: \n\n", nextDay, nextMonth, nextLeapYear);

    return 0;
}
``` 


#### step-by-step

##### days A

1. basic `day+1` if OK, `Bugz` if not OK
2. 

```c
int day;
int nextDay;

printf("Enter day number: ");
scanf("%d", &day);

if ((day >= 1) && (day < 31))
    nextDay = day + 1;
else printf("Bugz \n");

if (nextDay) printf("%d \n", nextDay);
```

##### months ~~A~~ B

```c
#include <stdio.h>

int main(){

    int day, month;
    int nextDay, nextMonth31, nextMonth30, nextMonthFEB, nextMonthFEBleap;

    printf("Enter DAY number: ");
    scanf("%d", &day);
    printf("Enter MONTH number: ");
    scanf("%d", &month);

    switch(month){
        case 1:
            nextMonth31 = month; break;
        case 2:
            nextMonthFEB = month; break;
        case 3:
            nextMonth31 = month; break;
        case 4:
            nextMonth30 = month; break;
        case 5:
            nextMonth31 = month; break;
        case 6:
            nextMonth30 = month; break;
        case 7:
            nextMonth31 = month; break;
        case 8:
            nextMonth31 = month; break;
        case 9:
            nextMonth30 = month; break;
        case 10:
            nextMonth31 = month; break;
        case 11:
            nextMonth30 = month; break;
        case 12:
            nextMonth31 = month; break;
        default: printf("switch bugz \n"); break;
    }

    // if (nextMonthFEB)
    // if (nextMonthFEBleap)
    // if (nextMonth30)

    if ((nextMonth31) && (day >= 1) && (day < 31)){
        nextDay = day + 1;

    }
    else if ((nextMonth31) && (day == 31)){
        nextDay = 1;
        nextMonth31 = month + 1;
    }
    else printf("Bugz \n");


    if (nextMonth31) printf("%.2d.%.2d \n", nextDay, nextMonth31);

    return 0;
}
```

-->