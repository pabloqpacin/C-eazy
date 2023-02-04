# 8. Recursions

<details>
<summary>Table of Contents</summary>

- [8. Recursions](#8-recursions)
  - [Concept and C usage](#concept-and-c-usage)
    - [General Visualization + Introduction](#general-visualization--introduction)
    - [Example 01 - Sum of Arithmetical Progression](#example-01---sum-of-arithmetical-progression)
    - [Example 02 - Factorial](#example-02---factorial)
    - [Challenge #1 - Fibonacci](#challenge-1---fibonacci)
    - [Challenge #2 - Sum of Digits in a Number](#challenge-2---sum-of-digits-in-a-number)
    - [Challenge #3 - Count of Digits](#challenge-3---count-of-digits)
  - [Practicals #8](#practicals-8)
    - [01. Recursive Function: Total Numbers Less Than Num](#01-recursive-function-total-numbers-less-than-num)
    - [02. Total Characters in a Sequence](#02-total-characters-in-a-sequence)
    - [03. Total Even Numbers in a Sequence](#03-total-even-numbers-in-a-sequence)
    - [04. Sum of All Even Numbers](#04-sum-of-all-even-numbers)
    - [05. Printing 1toN and Nto1](#05-printing-1ton-and-nto1)
    - [06. Printing Nto1 and 1toN](#06-printing-nto1-and-1ton)
    - [07. Lucas Sequence](#07-lucas-sequence)
    - [08. Finding Max Value in Sequence](#08-finding-max-value-in-sequence)
    - [09. Pell Number in a Pell Sequence](#09-pell-number-in-a-pell-sequence)
    - [10. Even Digits Sum](#10-even-digits-sum)
    - [11. Odd Even 'Positions' and 'Values' Finder](#11-odd-even-positions-and-values-finder)
  - [EXTRA](#extra)
    - [1. Print Sequence of num1s and then Sequence of num2s](#1-print-sequence-of-num1s-and-then-sequence-of-num2s)
    - [2. Print Sequence of char1s and then Sequence of char2s](#2-print-sequence-of-char1s-and-then-sequence-of-char2s)
    - [3. Print Seq. of LowerCase Chars + Seq. of UpperCase Chars](#3-print-seq-of-lowercase-chars--seq-of-uppercase-chars)
    - [4. Find if Digits are Ascending, Descending or not](#4-find-if-digits-are-ascending-descending-or-not)
    - [5. Even\_Odd Count of Digit Occurrences in num](#5-even_odd-count-of-digit-occurrences-in-num)

</details>

## Concept and C usage

### General Visualization + Introduction

<details>
<summary>Intro</summary>

- Recursion Concept:
  - New approach to solve problems
  - example
    - Original Problem: find sum of integers: 1 to n=5
    - sum_up_to(5): 1+2+3+4+5=15
      - in our minds, we go sum_up_to(1), sum_up_to(2), etc.
  - Problem to sub-problems
    - Can we solve the 'Original Problem' by dividing and solving some smaller "Sub Problems"?
      - If we can, can we do it on regular basis?
    - example
      - sum_up_to(3) = num(3) + [sum_up_to(2) = num(2) + {sum_up_to(1) = (1)}]
  - *Trivial Solution*: 'easy solution, that doesn't require further division'
  - *Recursion*:  'dividing problems into sub-problems and so on, until we reach the trivial condition'

- Real-Life examples of Recursions
  - **Russian dolls**: divide until we can't!
  - **Dream inside dream**
  - **Counting folders**: `cd` until can't `cd`
  - **Write 'recursion' in Google (feature)**

</details>

<details>
<summary>Examples</summary>

### Example 01 - Sum of Arithmetical Progression

- write a Recursive Function that:
  - receives a natural number (num)
  - returns the SUM of 'Arithmetical Progression from 1 to num'
- example
  - if num(5) return '1+2+3+4+5' sum(15)
  - syntax `SUM = 1+2+3+...+(num-1)+num = num+(num-1)+...+3.+2+1' 

```c
#include <stdio.h>

int sumUpTo(int num){
    if (num==1)
        return 1;
    return num + sumUpTo(num -1);
}

    // num=5 --> 5+sumUpTo(4) = 15
    // num=4 --> 4+sumUpTo(3) = 10
    // num=3 --> 3+sumUpTo(2) = 6
    // num=2 --> 2+sumUpTo(1) = 3
    // num=1 --> 1

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("Arithmetical Progresion from 1 to %d = %d \n", num, sumUpTo(num));
    return 0;
}
```


### Example 02 - Factorial

- Write a Recursive Function that:
  - receives a natural number (num)
  - returns the FACTORIAL of num
- FACTORIAL == **multiplication** of all natural numbers from 1 to n
  - F(n) = n *(n-1) *... *2 *1

```c
#include <stdio.h>

int factorial(int num){
    if (num==1)
        return 1;
    return num * factorial(num -1);
}

    // num=5 --> 5*factorial(4) = 120
    // num=4 --> 4*(factorial3) = 24
    // num=3 --> 3*factorial(2) = 6
    // num=2 --> 2*factorial(1) = 2
    // num=1 --> 1

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("Factorial(%d) = %d \n", num, factorial(num));
    return 0;
}
```

> Important to declare **base-case** (`if (num==1) return 1;`)

</details>

### Challenge #1 - Fibonacci

<details>
<summary>Request</summary>

- Write a Recursive **Fibonacci** Funtion that
  1. Receives a "n" (INDEX)
  2. Returns the VALUE at INDEX "n"
- Fibonacci Formula
  - Fibonacci(n): if n=0 return 0, if n=1 return 1, if n>1 return [F(n-1) + F(n-2)]
  - example F0=0, F1=1, F2=F1+F0=1+0=1, F3=F2+F1=1+1=2, F4=F3+F2=2+1=3  

</details>

```c
#include <stdio.h>

int fibonacci(int n){

    // if ((0 == n) || (1 == n)) return n; 
    if (n==0)
        return 0;
    if (n==1)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
    int n;
        printf("Enter INDEX: ");
        scanf("%d", &n);
    
    printf("Fibonacci-seq. VALUE at index n.%d = %d \n\n", n, fibonacci(n));
    return 0;
}
```

### Challenge #2 - Sum of Digits in a Number

<details>
<summary>Request</summary>

- Write a Recursive Function that
    1. Receives a number "num"
    2. Returns the SUM of all DIGITS
- example
  - num=67 --> sumOfDigits=6+7=13
  - num=9531 --> sumOfDigits=9+5+3+1=18

> Avoid loops-iteration!

</details>

```c
#include <stdio.h>

int sumDigitsNum(int num){
    if (num==0)
        return 0;
    /*
        if (num<=9)
            return num; ---> by @Vlad
    */
    return num%10 + sumDigitsNum(num/10);
}

int main(){
    int num;
        printf("Enter num: ");
        scanf("%d", &num);   
    printf("Sum of Digits in '%d' = %d \n\n", num, sumDigitsNum(num));
    return 0;
}
```

> Mind **base-case** for **recursive-call**!

### Challenge #3 - Count of Digits

<details>
<summary>Request</summary>

- Write a Recursive Function that
  - Receives a number "num"
  - Returns the TOTAL DIGITS in "num"
  - example:
    - num=67 --> totalDigits=2
    - num=9531 --> totalDigits=4

</details>

```c
/*
    EXAMPLE
    - sumOfDigits(213) = 3 + sumOfDigits(21) = 3 + 1 + sumOfDigits(2)
*/

#include <stdio.h>

int totalDigits(int num){

    if (num<=9)
        return 1;
    return 1 + totalDigits(num/10);
}

int main(){
    int num;
        printf("Enter num: ");
        scanf("%d", &num);   
    printf("Number of Digits in '%d' = %d \n\n", num, totalDigits(num));
    return 0;
}
```

<!--
#### prototype
```c
#include <stdio.h>

int totalDigits(int num){
    int counter;
    if (num<=9)
        return 1;
    else counter++;
    return counter + totalDigits(num/10);
}

int main(){
    int num;
        printf("Enter num: ");
        scanf("%d", &num);   
    printf("Number of Digits in '%d' = %d \n\n", num, totalDigits(num));
    return 0;
}
```
> MAX 4 Digits tho?! Even if trying with other [data types](https://www.programiz.com/c-programming/c-data-types) like `double` or `long int`!
-->

## Practicals #8

### 01. Recursive Function: Total Numbers Less Than Num

<details>
<summary>Request</summary>

- Write a recursive function that will:
  - Receive integer "num"
  - Read sequence of integers until input=-1
  - Return the total number of ints smaller than "num"
- example
  - num=5
  - seq = 6,8,10,3,1,7,-1
  - return: 2
- mind:
  - we don't know how many inputs we'll receive
  - don't use loops-iterations

</details>

```c
#include <stdio.h>

int totalUnderNum(int num){
    int seq;
        printf("New number in sequence (-1 to end): ");
        scanf("%d", &seq);
    if (seq == -1)
        return 0;
    if (seq < num)
        return 1 + totalUnderNum(num);
    return totalUnderNum(num);
}

int main(){
    
    int num;
        printf("Enter 'num' to verify smaller values: ");
        scanf("%d", &num);

    printf("Total of numbers in sequence smaller than num '%d' = %d \n\n", num, totalUnderNum(num));

    return 0;
}
```

> Basically, call function to return values until returns 0!

<!--
#### prototype 01
```c
#include <stdio.h>

int totalUnderNum(int num){

    int counter; 
    int seq;

    puts("Enter SEQUENCE // end with '-1'");
    
    while (seq != -1){
        scanf("%d", &seq);
        if (seq<num)
            counter++;
        else if (seq == -1){
            return 0;
            break;
        }
    }

    return counter-1;
}


int main(){

    int num;
        printf("Enter 'num' to check integers in seq. below its value: ");
        scanf("%d", &num);

    printf("Total of ints in seq. \
smaller than num '%d' = %d \n", num, totalUnderNum(num));

    return 0;
}
```
-->

### 02. Total Characters in a Sequence

- Write a recursive function that:
  - Receive given Char
  - Read sequence of characters from the user, until '$'
  - Calculate number of instances of a given Character in a Sequence

```c
#include <stdio.h>

int charInstances(char myChar){
    char seq;
        printf("New character in sequence ('$' to end): ");
        scanf(" %c", &seq);
    if (seq == '$')
        return 0;
    if (seq == myChar)
        return 1 + charInstances(myChar);
    return charInstances(myChar);
}

int main(){
    char myChar;
        printf("Enter Character 'myChar' to verify instances in seq. below: ");
        scanf("%c", &myChar);
    printf("Total instances of char '%c' in sequence = %d \n\n", myChar, charInstances(myChar));
    return 0;
}
```

> Mind `" %c"` ([error if no space](https://stackoverflow.com/questions/17917638/it-prints-the-printf-statement-twice))
> 
> Mind @Vlad's `getchar();` prior to the 'stopping-base condition' 

### 03. Total Even Numbers in a Sequence

- Write a recursive function that:
  - Calculates and returns the total amount of EVEN numbers in a Sequence
  - Read a sequence of integers from the user (until '-1)


```c
#include <stdio.h>

int evenInSeq(){
    int seq;
        printf("New number in sequence (-1 to end): ");
        scanf("%d", &seq);
    if (seq == -1)
        return 0;
    if (seq%2==0)
        return 1 + evenInSeq();
    return evenInSeq();
}

int main(){
    printf("Total of EVEN numbers in sequence = %d \n\n",evenInSeq());
    return 0;
}
```

### 04. Sum of All Even Numbers

- Same as last exercise, but return the SUM of all Even numbers


```c
#include <stdio.h>

int evenInSeq(){
    int seq;
        printf("New number in sequence (-1 to end): ");
        scanf("%d", &seq);
    if (seq == -1)
        return 0;
    if (seq%2==0)
        return seq + evenInSeq();
    return evenInSeq();
}

int main(){
    printf("Sum of all EVEN numbers in sequence = %d \n\n",evenInSeq());
    return 0;
}
```

### 05. Printing 1toN and Nto1

- Write recursive function that:
  - Receives "n" number
  - Prints all numbers from n to 1
  - Prints all numbers from 1 up to n

```c
/*  RECURSIONS:
    'printNto1': prints n and calls itself(n-1) until n=0
    'print1toN': now it calls itself(n-1) until n=0, then it will print "outwards"
        from the last recursion to the first!
*/

#include <stdio.h>

void printNto1(int n){
    if (n >= 1){
        printf("%d ", n);
        printNto1(n - 1);
    } 
}

void print1toN(int n){
    if (n >= 1){
        print1toN(n - 1);
        printf("%d ", n);
    } 
}

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("All the values from %d to 1 are: \n", n);
        printNto1(n);
    printf("\nAll the values from 1 to %d are: \n", n);
        print1toN(n);
    
    printf("\n");
    return 0;
}
```

<details>
<summary>@ChatGPT's</summary>

```c
#include <stdio.h>

void print_numbers(int n) {
  if (n <= 0) {
    return;
  }
  printf("%d\n", n);
  print_numbers(n - 1);
}

int main(void) {
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);
  print_numbers(n);
  return 0;
}
```

The program defines a recursive function `print_numbers` that takes an integer `n` as input.
The function uses an if statement to check if `n` is less than or equal to 0. If it is, the function returns without doing anything.
If `n` is greater than 0, the function prints `n` and then calls itself with `n-1` as the argument, which will repeat the process until `n` is less than or equal to 0.
In the main function, the user is prompted to enter a number, which is then passed to the `print_numbers` function to be printed.

</details>

<!--
#### prototype 01

```c
#include <stdio.h>

void print1toN(int n){
    int num=1;
    if (num<n){
        printf("%d ", num);
        num++;
    }
    if (num==n);
        return;
    print1toN(n);
}

int main(){

    int n;
        printf("Enter 'n' number: ");
        scanf("%d", &n);

    // printf("- 1 to %d below.", n);
    print1toN(n);

    printf("\n");
    return 0;
}
```

### prototype 00
```c
#include <stdio.h>

int print1toN(int n){

    int num=1;
    if (num==n)
        return 0;
    if (num<n)
        return num;

    printf("%d ", num);
    return print1toN(n);

}

int main(){

    int n;
        printf("Enter 'n' number: ");
        scanf("%d", &n);

    printf("All numbers from 1 to 'n' %d...", n);
    print1toN(n);

    printf("\n");
    return 0;
}
```
-->

### 06. Printing Nto1 and 1toN

- Expand previous exercise:
  - now Print: **nTo1ToN**

```c
// Vlad's Recursive Function
void printNto1toN(int n){
    
    if (n==1)
        printf("%d ", n);
    else {                  // if (n > 1)
        printf("%d ", n);
        printNto1toN(n - 1);
        printf("%d ", n);
    } 
}
```


```c
#include <stdio.h>

void printNto1toN(int n){
    if (n >= 1){
        printf("%d ", n);
        printNto1toN(n - 1);
    if (n > 1)
        printf("%d ", n);
    } 
}

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("All the values from %d to 1 to %d are: \n", n, n);
        printNto1toN(n);
    
    printf("\n");
    return 0;
}
```


### 07. Lucas Sequence

<details>
<summary>Request</summary>

- Write recursive function that:
  - Receives integer as Index for Lucas-sequence
  - Returns Value of such Index
- **Lucas Sequence** (Ln)
  - n0, value=2
  - n1, value=1
  - if n>1, value=`n-1 + n-2`
    - n2, value=1+2=3
    - n3, value=3+1=4
    - n4, value=4+3=7

</details>


```c
#include <stdio.h>

int Lucas(int n){
    if (0 == n) return 2;
    if (1 == n) return 1;
    return Lucas(n-1)+Lucas(n-2);
}

int LucasNotRecursive(int n){

    int i;
    int temp;
    int previous=2;
    int current=1;

    if (0 == 2) return 2;
    if (1 == n) return 1;
    for (i=2;i<=n;i++){
        temp = previous + current;
        previous = current;
        current = temp;
    } return current;
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Value of index n.%d in the Lucas Sequence = %d \n", n, Lucas(n));
    return 0;
}
```


### 08. Finding Max Value in Sequence

- Write recursive function that
  - Receives a natural number 'num'
  - Read a sequence of 'num' from user
  - Return the max value in sequence!

```c
#include <stdio.h>

int findMax(int num){
    int seq, max;
    printf("Enter new number: ");
    scanf("%d", &seq);

    if (1 < num){
        max = findMax(num-1);
        if (seq > max) return seq;
        else return max;
    }
}

int main(){
    int num;
    printf("Enter length of sequence: ");
    scanf("%d", &num);
    printf("Max value in sequence = %d \n", findMax(num));
    return 0;
}
```

> Again, first recurse *inwards*, then *outwards*!

<details>
<summary>findMin</summary>

```c
int findMin(int num){
    int seq, min;
    printf("Enter new number: ");
    scanf("%d", &seq);
    if (1 < num){
        min = findMin(num-1);
        if (seq < min) return seq;
        else return min;
    }
}
```

</details>

<details>
<summary>prototype (wrong)</summary>

```c
#include <stdio.h>

int findMaxValue(int num){
    int seq, max;
    printf("Enter new number: ");
    scanf("%d", &seq);
    if (seq > max) max = seq;
    printf("- seq = %d \n", seq);
    printf("- max = %d \n", max);

    if (1 == num) return max;
    return findMaxValue(num-1);
}
```
</details>

<!--
#### prototype 02
```c
#include <stdio.h>

int findMaxValue(int num){
    int seq, max;
    if (0 == num) return 0;
    if (0 < num){
        printf("Enter new number: ");
        scanf("%d", &seq);
        return max;
    }
    if (seq > max) max=seq;
    return findMaxValue(num-1);
}
```

#### prototype 01
```c
#include <stdio.h>

int findMaxValue(int num){
    int seq = num;
    printf("Enter new number: ");
    scanf("%d", &num);
    if (num > seq)
        return seq;
    return findMaxValue(num);
}
```
-->

### 09. Pell Number in a Pell Sequence

<details>
<summary>Request</summary>

- Pell Sequence rules
  - if index n0, value (Pn)=0
  - n1 = value 1
  - if n>1: `2*P(n-1)+P(n-2)`
- Examples
  - P0=0
  - P1=1
  - P2=`2*P1+P0`=2*1+0=2
    - P3=2*P2+P1=2*2+1=5
    - P4=2*P3+P2=2*5+2=12
    - P5=2*P4+P3=2*12+5=29
    - P6=2*P5+P4=2*29+12=70
    - P7=2*P6+P5=2*70+29=169
    - P8=2*P7+P6=2*169+70=408
    - P9=2*P8+P7=2*408+169=985
</details>


```c
#include <stdio.h>

int pellValue(int n){
    if ((0 == n) || (1 == n)) return n;
    return 2 * pellValue(n-1) + pellValue(n-2);
}

int pellNotRecursive(int n){
    int previous, current=1, next, i;
    if ((0 == n) || (1 == n)) return n;
    for (i=2; i<=n; i++){
        next = 2 * current + previous;
        previous = current;
        current = next;
    } return current;
}

int main(){
    int n;
    printf("Enter Pell sequence index: ");
    scanf("%d", &n);
    printf("Value of Pell number(%d) = %d \n", n, pellValue(n));

    printf("Not recursive result: %d \n", pellNotRecursive(n));
    return 0;
}
```


### 10. Even Digits Sum

- Write recursive function that
  - Receives an integer 'n'
  - Return 1 if the sum of the digits in 'n' is EVEN
  - Return 0 otherwise

```c
// ALT - Recursive Function Optimized & Minimized

int evenSum(int n){
    if (n<10) return n%2 ? 0:1;
    return n%10%2 ? !evenSum(n/10) : evenSum(n/10);
}
```

```c
#include <stdio.h>

int actualSum(int n){
    if (9 >= n ) return n;
    return n%10 + actualSum(n/10);
}

int evenSum(int n){
    int sum;
    if (9 >= n) sum = n;
    sum = n%10 + actualSum(n/10);
    if (0 == sum%2) return 1;
    if (0 != sum%2) return 0;
}


int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);   
    printf("- Sum = %d \n", actualSum(n));

    if (evenSum(n))
        printf("- Sum is EVEN! \n");
    else printf("- Sum is ODD! \n");

    return 0;
}

/*
    fun(5) = 5
    fun(156) = 6 + fun(15) = 6 + 5 + fun(1)
*/
```

>  Boolean-doable...


### 11. Odd Even 'Positions' and 'Values' Finder

<details>
<summary>Request</summary>

- Write a recursive function that:
  - Receives 'n' natural number
    - Multiple digits mean multiple "positions", where '0' is the smallest unit, etc.
  - Ensure every number in EVEN position has EVEN value and viceversa
    - Return `1` if match, return `0` otherwise!
  - Example (36435) --> '5' is position '0' which should be EVEN, therefore returns `0`

</details>

```c
#include<stdio.h>
 
int EvenOddDigitFinder(int num, int position){
    
    int digit = num % 10;
    num /= 10;
 
    if (num == 0) return 1;
        
    if (position % 2 == 0){
        if (digit % 2 == 0) return EvenOddDigitFinder(num, position + 1);
        else return 0;
    }
    
    if (position % 2 != 0){
        if (digit % 2 != 0) return EvenOddDigitFinder(num, position + 1);
        else return 0;
    }
    
}
 
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Answer is: %d \n", EvenOddDigitFinder(num, 0));
    return 0;
}
```

<!--
```c
/* POINT
fun(432) -> 2 OK + fun(43) -> 3 OK + fun(4) -> 4 OK
*/

/* IDEA
    - n0%2 should equal 0
    - n1%2 should equal 1
    - n2%2 should equal 0
    - n3%2 should equal 1

    if broken, return 0, otherwise keep recursing until... (n<10)?
*/

#include <stdio.h>

int evenOdds(int n){

    if (9 >= n)
        return (evenOdds(n/10)%2) ? 0:1;

    // return 1;
    // return 0;
}

int main(){

    int n;
    puts("Verifying values match Odd/Even positions.");
    puts("12==OE ok, 123==EOE not OK, 1234==OEOE ok.\n");
    printf("Enter a number: ");
    scanf("%d", &n);

    if (fun(n)) puts("Yay! Values and positions match .EOE! \n");
    else puts("Yikes! Values and positions don't match .EOE! \n");

    return 0;
}
```
-->


## EXTRA
### 1. Print Sequence of num1s and then Sequence of num2s
### 2. Print Sequence of char1s and then Sequence of char2s 
### 3. Print Seq. of LowerCase Chars + Seq. of UpperCase Chars
### 4. Find if Digits are Ascending, Descending or not
### 5. Even_Odd Count of Digit Occurrences in num