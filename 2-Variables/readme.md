# 2. Variables

## Variables & Data Types

Variables can be compared with boxes. Importantly, both boxes and variables have all:
- Type (integers, real numbers, characters, strings...)
- Name
- Content/Value
- Adress


### Variables in C Programming

1. Variable Declaration ("Creation")
   1. Variable "Creation"
   2. Structure: `<type> <name>;`
      1. Example for Integers: `int age;`
      2. Example for Floating Point Numbers: `double temp;`
2. Assignment
   1. Put some value in a Variable
   2. Value should match type, examples:

```c
int age;
age = 30;

double temp; // both 'int' and 'floatin'
temp = 26.5;
```

3. Reading Input from User <!--"Variable as Input"-->
   1. Reading data from the user
   2. Structure in C Language (using Assignment)
   3. Structure in C Language (using `Scanf`)

<details>
<summary>Snippets</summary>

```c
// NO INPUT == STATIC DATA; IRRELEVANT FOR USERS!
int grade1;
int grade2;
grade1 = 80;
grade2 = 100;
printf("Average = %d\n", (grade1+grade2)/2);
```

```c
/* READING INPUT FROM USER (CONSOLE)
'&gradeX' == '%d' value to be placed in the given memory address */
int grade1;
int grade2;
scanf("%d", &grade1);
scanf("%d", &grade2);
printf("Average = %d\n", (grade1+grade2)/2);
```
</details>

4. Input Variables Examples

```c
// ONLY ASSIGNMENT
#include <stdio.h>

int main(){
    int num;
    num = 10;
    printf("num is %d \n", num);
    return 0;
}
```

```c
// USER SETS VALUE
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    printf("num is %d \n", num);
    return 0;
}
```


### Casting

<details>
<summary>Notes</summary>

- intro
  - we know we can create different variables with different types, names, content and adresses
  - (math operations) the sum of two integers is expected to be an integer; the division of two FPN (doubles) is expected to be the same
  - therefore a "math operation [+, -, *, /, %...]" is expected to work with the same **variable type**... but that's not correct!!
- so
  - `5/2=int/int=2(int)`
  - `5/2=int/int=2.5(double)`

- casting in C programming language
  - examples below
  - Rule #1: "whenever math operations with same-type numbers (int, etc.), default result with be same-type"
    - meaning it doesn't matter we use `int` or `double` for `result` if we do `int/int`!!
  - Rule #2: "implicit casting = whenever math with integers+floating will always be treated as between floating IE int/double=double; int/int=~~double~~ int
  - Rule #3: **casting == `(double)`**; now the `int` remain 'int', they were casted as 'double' for the operation only
  - EXTRA: cast FPN as Integer like `(int)5.1` or `(int)7.95` (= 5 & 7 ...)
  <!-- - superextra: extra-depth we won't get into D: -->

```c
#include <stdio.h>

int main(){
    // 5/2=2.5
    double num1=5, num2=2;
    double result;
    result = num1/num2;
    printf("result = %.2lf \n\n", result);

    // CASTING; 5/2=2.5
    int num1=5, num2=2;
    double result;
    result = num1/(double)num2;
    printf("result = %.2lf \n\n", result);

    return 0;
}
```

</details>

### Challenge #1 - Find your Year of Birth!

### Challenge #2 - Calculate Rectangle's Area

### Challenge #3 - Calculating your Average Grade

```c
#include <stdio.h>

int main(){
    
    // Chall. #1 - Find your Year of Birth!
    int currentYear;
    int yourAge;
    int yearBirth;

    printf("Current year: ");
    scanf("%d", &currentYear);
    printf("Your age: ");
    scanf("%d", &yourAge);
    yearBirth = currentYear - yourAge;
    
    printf("You were born in %d \n\n", yearBirth);
        // Still needing "months" correction!
    

    // Chall. #2 - Calculate rectangle's area! ('%lf')
    double height, width;
    double area;

    printf("Enter height: ");
    scanf("%lf", &height);
    printf("Enter width: ");
    scanf("%lf", &width);

    area = height*width;
    printf("The rectangle's area is %.3lf \n\n", area);


    // Chall. #3 - Calculate Your Average Grade!
    int grade1, grade2, grade3;
    double average;
    printf("Enter your 3 grades to calculate their average \n");

    printf("Grade 1: ");
    scanf("%d", &grade1);
    printf("Grade 2: ");
    scanf("%d", &grade2);
    printf("Grade 3: ");
    scanf("%d", &grade3);

    // ALT: average = ((double)grade1+grade2+grade3)/3;
    average = (grade1+grade2+grade3)/3.0;
    printf("Your average grade is %.2lf \n\n", average);

    return 0;

}
```

<!--
```c
// TAREA PERIMETRO
#include <stdio.h>

int main(){
    // Chall. #2 - Calculate rectangle's area! ('%lf')
    double height, width;
    double perimeter;

    printf("Enter height: ");
    scanf("%lf", &height);
    printf("Enter width: ");
    scanf("%lf", &width);
    perimeter = 2*(height+width);

    printf("The rectangle's perimeter is %.3lf \n\n", perimeter);
    
    return 0;
}
```
-->

### Milestone #2 - Weather Station A

```c
#include <stdio.h>

int main(){

    /* 1. Formula for Celsius into Fahrenheit conversion T(F)=T(C)*1.8+32 */
    double ctemp, ctof;
    printf("Enter the temperature in Celsius degrees: ");
    scanf("%lf", &ctemp);
    ctof = ctemp*1.8+32;
    printf("The temperature in Fahrenheit is %.2lf \n\n", ctof);

    /* 2. Formula for Fahrenheit into Celsius T(F)=T(C)*1.8+32 */  
    double ftemp, ftoc;
    printf("Enter the temperature in Fahrenheit degrees: ");
    scanf("%lf", &ftemp);   
    ftoc = (ftemp-32)/1.8;
    printf("The temperature in Celsius is %.2lf \n\n", ftoc);

    return 0;
    
}
```

### SWAP in C Programming

- General SWAP in Programming
  - example: var1=10, var2=20; how to SWAP? Can't be simultaneous in-and-out so...
    - varTemp=10 (from var1), var1=20 (from var2), var2=10 (from varTemp)

- SWAP in C Language:

```c
// SWAP INTEGER VARIABLES
#include <stdio.h>

int main(){

    int a=10;
    int b=20;
    int temp;

    printf("a = %d \n", a);
    printf("b = %d \n\n", b);

    temp = a;
    a = b;
    b = temp;

    printf("a = %d \n", a);
    printf("b = %d \n\n", b);

    return 0;
}
```

<details>
<summary>Swap Floiting Point Variables</summary>

```c
// SWAP FLOATING POINT VARIABLES
#include <stdio.h>

int main(){

    double a=10.01;
    double b=20.02;
    double temp;

    printf("a = %.2lf \n", a);
    printf("b = %.2lf \n\n", b);

    temp = a;
    a = b;
    b = temp;

    printf("a = %.2lf \n", a);
    printf("b = %.2lf \n\n", b);

    return 0;
}
```
</details>

## Practicals #2

### Arithmetic Sequence-Progression

- Terms
  - **Difference**: rule for progression ('d=2')
  - **Initial Term**: ('a1=1')
  - **Total Terms**: ('n=9')
  - **n-th term**: last term in the sequence ('an=17')

### Exercises

- Formulas

| Exercise | To-do                                | Formula                       |
| ---      | ---                                  | ---                           |
| 1.       | **n-th Term of Arithmetic Sequence** | `an = a1 + (n - 1) * d`       |
| 2.       | **Sum of Arithmetic Sequence**       | `Sn = (a1 + an) * n / 2`      |
| 9.       | **distance between 2 given points**  | `d = √ (x1-x2)^2 + (y1-y2)^2` |

####  1. n-th of Arithmetic Sequence

> see our custom [documentation](/docs/documentation.md) for differences between:
> - `float` and `double` Variable types
> - `%f` and `%lf` placeholders


####  2. Sum of Arithmetic Sequence
####  3. Employee Salary Calculator

```c
#include <stdio.h>

// [ a1=2.5 | a2=5 | a3=7.5 | d=2.5 | n=15 | an=? | Sn=? ]

int main(){

    // 1. n-th of Arithmetic Sequence
    double a1, d, an;
    int n;
    
    printf("Enter the Initial Term (a1): ");
    scanf("%lf", &a1);

    printf("Enter the Total number of elements (n): ");
    scanf("%d", &n);

    printf("Enter the Difference in in Arithmetic Sequence (d): ");
    scanf("%lf", &d);

    an = a1 + (n - 1) * d;
    printf("\nThe n-th (an) Term of your Arithmetic Sequence is %.2lf \n", an);

    // 2. Sum of Arithmetic Sequence
    double Sn = (a1+an) * n / 2;
    printf("The Sum (Sn) of your Arithmetic Sequence is %.2lf \n\n", Sn);

    // 3. Employee Salary Calculation
    double hourSalary, monthHours;
    printf("Salary [€/hour]: ");
    scanf("%lf", &hourSalary);
    printf("Hours worked per month: ");
    scanf("%lf", &monthHours);

    double monthSalary = hourSalary * monthHours;
    printf("Salary per Month: %.2lf € \n", monthSalary);

    return 0;

}
```

####  4. Finding a Driving Time

- vehicle leaves from A to B
  - distance known
  - speed known
  - how long will it take?
- formula
  - `t = d / v`

<!-- horas minutos segundos importante
para esto y para cosas tipo Neofech dawg!


ojo REMAINDER, int VS double...-->

####  5. Convert Seconds into Hours, Minutes and Seconds

- todo
  - receive seconds as Integer
  - convert seconds into
    - total hours
    - total minutes
    - remaining seconds
- example (4000 seconds)
  - 1 hour = 3600 seconds
  - minutes 4000 - 3600 = 400; 400/60= 6 minutes
  - seconds 400 % 60 = 40 seconds

####  6. Removing Decimal Part from an Integer

- todo
  - user input variable "data" type float
  - print only the decimal part
  - consider casting
- example
  - receive 12.7
  - output 0.7 


```c
#include <stdio.h>


int main(){

    // 4. Finding a Driving Time...
    int distance, speed;
        printf("Enter distance [km]: ");
        scanf("%d", &distance);  
        printf("Enter speed [km/h]: ");
        scanf("%d", &speed);

    double speedInMinutes = speed / 60.0;
    int hours = distance / speed;
    int remainingMinutes = (distance % speed) / speedInMinutes;

    printf("The time from A to B will take %d hours and %d minutes \n\n", hours, remainingMinutes);


    // 5. Convert Seconds Into Hours, Minutes and Seconds
    int totalSeconds;
    printf("Enter the number of seconds: ");
    scanf("%d", &totalSeconds);

    int totalHours = totalSeconds/3600;
    int totalMinutes = (totalSeconds-(totalHours*3600))/60;
    int remainingSeconds = (totalSeconds-(totalHours*3600)) % 60;

    printf("Conversion: %.2d:%.2d:%.2d \n\n", totalHours, totalMinutes, remainingSeconds);


    // 6. Removing Decimal Part from an Integer
    float data;
    printf("Enter a decimal number: ");
    scanf("%f", &data);

    float dataDecimal = data - (int)data;
    printf("This is the decimal part of your number: %.3f \n", dataDecimal);
    printf("This is your number without its decimals: %d \n", (int)data);


    return 0;

}
```
  
####  7. Sum of Triple Digits

- todo
  - receive number with 3 digits
  - calculate sum of such digits
- example
  - receive 531
  - sum = 5+3+1=9

####  8. Print Reversed Number

- todo
  - receive 3-digit number
  - print it reversed!

```c
#include <stdio.h>

int main(){

    // 7. Sum of Triple Digits
    int userNumber;
        printf("Enter a 3-digit number: ");
        scanf("%d", &userNumber);

    int units = userNumber % 10;
    int tens = (userNumber/10) % 10;
    int hundreds = userNumber / 100;

    int sumDigits = units+tens+hundreds;
    printf("The sum of the given digits is: %d \n\n", sumDigits);


    // 8. Print Reversed Number
    int userNum;
        printf("Enter a 3-digit number: ");
        scanf("%d", &userNum);

    int un = userNum % 10;
    int ten = (userNum/10) % 10;
    int hun = userNum / 100;

    int reversedNum = un*100 + ten*10 + hun;

    printf("The reversed number is: %d \n\n", reversedNum);
    // printf("The reversed number is: %d%d%d \n\n", un, ten, hun);


    return 0;
}
```

####  9. Distance Between 2 Points

- todo
  - calculates distance between two given point
    - a(x1,y1)
    - b(x2,y2)
  - distance using **formula** above 

> notice **memory allocation** ie. `&x1`...

<!-- TODO:
- receive user input as CHAR names (places)
  - database name = x,y COORDS
  - (figure out conversion to KMs)
  - output distance in KMs
-->


####  10. Efficent Calculation Example


- todo 
  - receive integer X
  - calculate and print X to the power of [2, 4, 6, 8]


```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){

    // 9. Distance Between 2 Points
    double x1,y1,x2,y2;
    double squareX, squareY;
        double distance;

    printf("Enter X1: ");
    scanf("%lf", &x1);

    printf("Enter Y1: ");
    scanf("%lf", &y1);

    printf("Enter X2: ");
    scanf("%lf", &x2);

    printf("Enter Y2: ");
    scanf("%lf", &y2);

    squareX = pow((x1-x2), 2);
    squareY = pow((y1-y2), 2);

    // distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    distance = sqrt(squareX + squareY);
    printf("The Distance between the points (%.2lf, %.2lf) and (%.2lf, %.2lf) is %.2lf \n\n", x1,y1,x2,y2,distance);


    // 10. Efficient Calculation Example
    int numberX;
    int power2, power4, power6, power8;

    printf("Enter your number: ");
    scanf("%d", &numberX);
  
    power2 = pow(numberX, 2);
    power4 = pow(numberX, 4);
    power6 = pow(numberX, 6);
    power8 = pow(numberX, 8);
    
    printf("%d to the power of 2 is: %d \n", numberX, power2);
    printf("%d to the power of 4 is: %d \n", numberX, power4);
    printf("%d to the power of 6 is: %d \n", numberX, power6);
    printf("%d to the power of 8 is: %d \n\n", numberX, power8);

    return 0;
}
```

```c
// SUPER COOL IDEA
int numberX, numberY;
int powerNumber;

printf("Enter the X number of [x^y]: ");
scanf("%d", &numberX);

printf("Enter the Y number of [x^y]: ");
scanf("%d", &numberY);

powerNumber = pow(numberX, numberY);
    printf("%d to the power of %d is: %d \n\n", numberX, numberY, powerNumber);
```

## AlphaTech QUIZ #1

some good questions
- What is an Algorithm?
  - A well-defined set of commands to solve a certain problem
- What is a "Compilation Error"?
  - An error in the code that the compilar tracked and mentioned it to the developer.
- What is a "Run-Time Error"?
  - An error that couldn't be tracked by the compiler, which can make the program crash when it's running

- what variables store integer values?
  - `long` and `int`
- real values?
  - `float` and `double`
- character?
  - `char` 
- `float` has higher precission than `double`?
  - False
- Can we initialize a variable in the same line we declare it?
  - Yes
- Why we're using **Casting**?
  - Change var type duh



<!--

why `void main(){ }`-->