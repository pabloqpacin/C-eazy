# 5. Functions

## General Concept, Structure & Usage

<details>
<summary>explanation</summary>

intro
- All code in `main` = error-prone
- Catch-bugs
- Avoid repetition
  - For repetitive processes, **call** sb else!

basic structure
- **Name**: unique
- **List of Parameters**: no matter how many (ie. 0 OR 10) <!--waits to be called w/ given parameters-->
- **Body**: execute commands within; mind **local variables**!
- **Expected Return**: mind *return types*
  - integer type
  - floating point
  - character
  - ...

> - [ ] relationship between 'return types' and CPU components (ALU, ...)
 
C programming: **Signature**
1. **<"Return type">**
   - `int`: integers
   - `float`: floating point 
   - `double`: ...
   - `char`: characters
   - ...: strings
   - etc.
   - `void` if **returns NOTHING**

   > - [ ] [wiki](/docs/wiki.md)
2. **<"Function's Name">**
   - Avoid **reserved** words
   - Ensure clarity & readibility for names to avoid clutter; self-explanatory function names!!
3. **<"Parameters List">**
   - (call to do something)
   - required data for operation!
   - OK if empty! - according with body!!

Below, #4 examples of all standard function functionalities:

| Example | Parameters | Return |
| ---     | ---        | ---    |
| #1      | NO         | NO     |
| #2      | YES        | NO     |
| #3      | NO         | YES    |
| #4      | YES        | YES    |

> mind difference of RETURN vs PRINT (as "return" means functions EXCHANGE data)

</details>

<details>
<summary>examples</summary>

### Example #1 - Print Greetings!
- `void` type because **no-return**
- **no-parameteres** either: `()` in signature
- run `.c` with written `void` but empty `main`: no workie-workie

```c
#include <stdio.h>

// GREETING FUNCTION
// printf(HELLO\nsomething\nsomething)
// NO parameters, NO return;; only call and see it done, no exchange...

void printGreetings(){
    printf("  Sup Dawg? \n");
    printf("  C iz eazy dun't ye see \n");
}

int main(){
    printf("Before fun \n");
    printGreetings();
    printf("After fun \n");
    return 0;
}
```

### Example #2 - Print Max between 2 Integers
- todo
  - receive two numbers
  - print which one is max and which is min
- `void` because it doesn't **return** data to the main function, does it?
  - notice no `return` at the end!

```c
#include <stdio.h>


void printMinMax(int num1, int num2){
    if (num1>num2)
        printf("MAX = %d \nMIN = %d \n", num1, num2);
    else
        printf("MAX = %d \nMIN = %d \n", num2, num1);
}

int main(){
    int a, b;
    printf("Enter num 1: ");
    scanf("%d", &a);
    printf("Enter num 2: ");
    scanf("%d", &b);
    printMinMax(a, b);
    return 0;
}
```

### Example #3 - Return Max between 3 Integers
- todo
  - receive no parameters (but return something)
  - ask 3 numbers from user
  - max value between 3 given numbers
  - return maximum


```c
#include <stdio.h>

int maxBetween3(){
    int num1, num2, num3;
    printf("Enter num1, num2 and num3: ");
    scanf("%d%d%d", &num1, &num2, &num3);

    if (num1>num2)
        if (num1>num3)
            return num1;
        else
            return num3;
    else if (num2 > num3)
        return num2;
    else return num3;
}

int main(){
    int max;
    max = maxBetween3();
    printf("Maximum = %d \n", max);
    return 0;
}
```

### Example #4 - Calc & Return avg between 3 numbers

- todo
  - receive three grades
  - return average

> ~~`float`~~ but `double`!!

```c
#include <stdio.h>

double findAverage(int grade1, int grade2, int grade3){
    double avg;
    avg = (grade1+grade2+grade3) / 3.00;
    return avg;
}

int main(){
    double avg;
    int g1, g2, g3;
    printf("Enter three grades: ");
    scanf("%d%d%d", &g1, &g2, &g3);
    printf("Average = %.2lf \n", findAverage(g1,g2,g3));
    return 0;
}
```

</details>

## Functions: Challenges

### Challenge #1 - Find Rectangle Area

- todo
  - function to calculate area of rectangle
  - receive height and weight (double)
  - calculate and return area
  - print returned result in MAIN fun

```c
#include <stdio.h>

double areaCalculator(double height, double width){
    double area;
    return (area = height * width);
}

int main(){
    double a, b;
    printf("Enter Rectangle height: ");
    scanf("%lf", &a);
    printf("Enter Rectangle width: ");
    scanf("%lf", &b);
    printf("AREA = %.2lf \n", areaCalculator(a,b));
}
```

### Challenge #2 - Maximum DIGIT in a 2-digits number

- todo
  - pass 2-digit number as parameter to function that
    - verifies number has two-digits    (condition)
    - print highest digit
  - main calls function

```c
#include <stdio.h>

void maxDigit(int num){
    if (num<10 || num>99)
        printf("Number %d is not a two-digit number!", num);
    else{
        if (num/10>num%10)
            printf("Max digit in %d is... %d \n", num, num/10);
        else
            printf("Max digit in %d is... %d \n", num, num%10);
    }
}


int main(){
    int num;
    printf("Enter 2-digit number: ");
    scanf("%d", &num);
    maxDigit(num);
    return 0;
}
```

### Challenge #3 - Calculate FACTORIAL!

- todo
  - write function to
    - receive number
    - calculate its Factorial
    - return the result
  - print function result
- mind
  - if number n is negative: result=-1

```c
#include <stdio.h>

int factorialN(int n){
    int f=1, i;
    if (n<0)
        return -1;
    for (i=1;i<=n;i++)
        f*=i;
    return f;
}

int main(){
    int n;
    printf("Enter 'n' number: ");
    scanf("%d", &n);
    printf("Factorial of %d = %d \n", n, factorialN(n));
    return 0;
}
```

<!--
```c
#include <stdio.h>


int factorialN(){
    int n, f=1;
    int i;
    printf("Enter 'n' number: ");
    scanf("%d", &n);

    for (i=1;i<=n;i++)
        f*=i;
    return f;
}

int main(){
    printf("%d \n", factorialN());
    return 0;
}

```
-->

> - [ ] documentation on [Factorial of a negative number](https://youtu.be/dQw4w9WgXcQ)
>
<!-- > - [ ] how could we **RETURN BOTH** 'n' and 'f' -->
> - [ ] ALWAYS returns ONCE and ONE variable?!

## Practicals #5

### 1. Functions: "isEven" & "isOdd"



### 2. Sequence of 9s
### 3. Generation of Numbers 123... \<seq lenght>
### 4. Functions: "toLower" & "toUpper"
### 5. Chars To 3 Digits Integer
### 6. Amount and Average of Digits Less Than Given Digit
### 7. Derivatives
### 8. Sum of Divisors
### 9. Sum of Advisors
### 10. Perfect Numbers
