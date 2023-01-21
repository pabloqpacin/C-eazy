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

#### `isEven`
- todo
  - implement `isEven` function
    - signature
    - body
      - receive an int
      - return 1 if given int is even
      - otherwise, return 0


#### `isOdd`
- todo
  - implement another function `isOdd` to
    - receive int
    - return 1 if odd
    - otherwise, 0


```c
#include <stdio.h>

int isEven(int n){
    if (n%2==0)
        return 1;
    return 0;
}

int isOdd(int n){
    if (isEven(n))
        return 0;
    return 1;
}


int main(){
    int n;
    printf("Enter num: ");
    scanf("%d", &n);
    if (isEven(n))
        printf("%d is even \n", n);
    else if (isOdd(n))
        printf("%d is odd \n", n);
    return 0;
}
```

> - [ ] **booleans** not yet explained // function type?!



### 2. Sequence of 9s

- todo
  - write function that receives a "lenght" number to
    -  (body)
    -  return '999...9' of given "lenght"


```c
#include <stdio.h>

int sequenceGenerator(int lenght){
    int i, sequence;
        for (i=1;i<=lenght;i++){
        sequence=(sequence*10)+9;
    }
    return sequence;
}


int main(){
    int lenght;
    printf("Enter lenght of sequence: ");
    scanf("%d", &lenght);
    printf("%d \n", sequenceGenerator(lenght));
    return 0;
}
```
> **OJO**
> - if var type == **int** & lenght=10: returns `1410065407` both to me and @Vlad despite our different programs <!-- WHY **THAT** NUMBER?!?!? -->
> - this happens because `int` is vewry size-limited: `int` can only store **4 bytes** of memory!!
> - `int` range limits (digits): (*...*) (add to [wiki](/docs/wiki.md)!)
> - now `long` allows for **8 bytes** (digits: (*...*))
> 
> - [ ] rework with other variable types & add cheat-sheet to wiki!! 


### 3. Generation of Numbers 123... \<seq lenght>

> building from 5.2 right above!

- todo
  - receive lenght num and
    - if lenght <= 9 return 123...lenght
    - else 999...lenght


```c
/*
    mind variables
        - 'int' [%d] allows for 9 digits (lenght=9)
        - 'double' [%lf] for 15 
        - 'long' [%ld] for 18
        - TODO: '...' [%Ld] for ...
*/


#include <stdio.h>

long sequenceGenerator(int lenght){
    long sequence;
    int i;
    for (i=1;i<=lenght;i++){
        if (lenght<=9)
            sequence=(sequence*10)+i;
        else 
        sequence=(sequence*10)+9;
    }    
    return sequence;
}

int main(){
    int lenght;
    printf("Enter lenght of sequence: ");
    scanf("%d", &lenght);
    printf("%ld \n", sequenceGenerator(lenght));
    return 0;
}
```

> @Vlad uses a second `long shortSequence` rather than the 'if-statement' within `long sequenceGenerator`

### 4. Functions: "toLower" & "toUpper"

- todo
  - write function that receives a character to
    - check if char is 'uppercase' (A-Z)
      - return its 'lowercase' counterpart (a-z)
    - otherwise return ~~'-1'~~ 'F'

```c
/* ASCII
- uppercase: A=65d // Z=90
- lowercase: a=97 // z=122
    - therefore (letter-A+a = letter+32)
    - (Run Bash command 'ascii -o' )
- Should 'toLower' be 'int' to return '-1'?
*/

#include <stdio.h>

char toUpper (char letter){
    if (letter >= 97 && letter <= 122)
        return letter - 32;
    return -1;
}

char toLower(char letter){
    if (letter >= 65 && letter <= 90)
        return letter + 32;
    return -1;
    // return 'F';
    // return (toUpper(letter));
}

int main(){
    char letter;
    printf("Enter a char: ");
    scanf("%c", &letter);
    printf("To Lower: %c \nTo Upper: %c \n\n", \
                toLower(letter), toUpper(letter));
    return 0;
}
```

> Exercise neither throughly explained but fairly well solved as for `main` integration; I still would write the if-statement within `main`!!



### 5. Chars To 3 Digits Integer

> more ASCII representation
>

- mind
  - ascii variety; letters, numbers, other symbols...
  - [ ] '1' could be stored as an **integer (4 bytes)** OR as a **character (1 byte)**, although *'characters' can't perform math* operations!!
- todo
  - write function that receives 3 characters (digits)
  - check if all characters are digit-type
  - if so, function return DEC representation (integers)
  - EG. if receive '1'+'5'+'9', return 159
  - otherwise return 0


<!--
#### prototype 3
```c
/* ASCII
    - '0'=48d // '9'=57d
*/

#include <stdio.h>


int charToInt(char d1, char d2, char d3){
    int hundreds, tens, units;
    int conversion;
    if (d1>=48 && d1<=57)
        hundreds = d1 -0;
        if (d2>=48 && d2<=57)
            if (d3>=48 && d3<=57)
    
    printf("%d \n", hundreds);
    return 420;
    return conversion;
    return 0;
}


int main(){
    char d1, d2, d3;
    printf("Enter three digits: ");
    scanf("%c %c %c", &d1, &d2, &d3);
    printf("%d \n", charToInt(d1, d2, d3));
    return 0;

}
```

#### prototype 2
```c
/* ASCII
    - '0'=48d // '9'=57d
*/

#include <stdio.h>


int conversion(char d1, char d2, char d3){
                // conversion=d1*100+d2*10+d3;
                // printf("%d", conversion);
                // return d1*100+d2*10+d3;   
    // printf("%d%d%d", (int)d1, (int)d2, (int)d3);
    // return("%d%d%d", (int)d1, (int)d2, (int)d3);
    // // printf("%d, %d, %d", d1, d2, d3);
    
    int decimal;
    if (d1>=48 && d1<=57)
        if (d2>=48 && d2<=57)
            if (d3>=48 && d3<=57)
                decimal=(???)
    return 420;
    return decimal;
    return 0;
}


int main(){
    char d1, d2, d3;
    printf("Enter three digits: ");
    scanf("%c %c %c", &d1, &d2, &d3);
    printf("%d \n", conversion(d1, d2, d3));
    return 0;

}
```


#### prototype 1

> doesn't work cuz char dun't do mathz

```c
#include <stdio.h>


int conversion(char d1, char d2, char d3){
    int conversion;
    if (d1>=48 && d1<=57)
        if (d2>=48 && d2<=57)
            if (d3>=48 && d3<=57)
                conversion=d1*100+d2*10+d3;
                printf("%d", conversion);
                return d1*100+d2*10+d3;        
    return 0;
}


int main(){
    char d1, d2, d3;
    printf("Enter three digits: ");
    scanf("%c %c %c", &d1, &d2, &d3);
    printf("%d \n", conversion(d1, d2, d3));
    return 0;
}
```
-->


### 6. Amount and Average of Digits Less Than Given Digit

- todo
  - write a function that receives a long 'num' and a 'digit' to
    - print the sum of 'num' digits lower than 'digit'
    - return 'avg' of such digits


```c
#include <stdio.h>

double lowerThanDigit (int num, int digit){
    int counter;
    int temp, sum, avg;

    // If 'num' negative, turn it positive
    if (num < 0)
        num *= -1;

    // Iterate over all 'num' digits with 'num/10'
    for (temp=num; temp != 0; temp/=10){
        if (temp % 10 < digit){
            counter++;
            sum += temp % 10;
        }
    }
    
    printf("\nSUM of digits below %d in %d = %d \n", digit, num, sum);
    return avg = (double)sum / counter;
}


int main(){
    int num, digit;
    printf("Enter a long-ass number: ");
    scanf("%d", &num);
    printf("Please enter 'limit' [1/9]: ");
    scanf("%d", &digit);

    printf("AVG of digits below %d in %d = %.2lf \n\n", \
                digit, num, lowerThanDigit(num, digit));

    return 0;
}
```


<details>
<summary>@Vlad's</summary>

```c
#include <stdio.h>

double lowerThanDigit (int num, int digit){
    int counter;
    int totalSum;

    if (num < 0)
        num *= -1;

    while (num != 0){
        if (num % 10 < digit){
            counter++;
            totalSum += num % 10;
        }
        num/=10;
    }
    printf("Total Amount of Digits in %d = %d \n", num, counter);
    return (double)totalSum / counter;
}


int main(){
    int num, digit;
    num=2468;
    digit=5;

    lowerThanDigit(num, digit);
    printf("2. %.2lf", lowerThanDigit(num, digit));

    return 0;
}
```
</details>

<!--
#### Prototype 2
```c
/*
    NOTES
    - 'operation' function is 'double' because 'avg' be floatey 
*/

#include <stdio.h>

double operation(int num, int digit){
    int temp, sum, currentValue;
    double avg;

    // while (temp>10){
    //     printf("%d ", temp);
    //     sum+=temp%10;
    //     temp=temp/10-temp%10;
    // }

    for (temp=num; temp>10; (temp-currentValue)/10){
        currentValue=temp%10;
        printf("%d", currentValue);
        if (currentValue<digit)
            sum+=currentValue;
    }

    printf("SUM of %d's digits below %d = %d \n", num, digit, sum);
    return avg;
    return 420;
}

int main(){
    int num, digit;
    printf("Please enter a long-ass number: ");
    scanf("%d", &num);
    printf("Please enter a random number (1/9): ");
    scanf("%d", &digit);

    printf("AVG of %d's digits below %d = %.2lf \n\n", \
                num, digit, operation(num, digit));

    return 0;
}
```

#### prototype 1

```c
/*
    NOTES
    - 'operation' function is 'double' because 'avg' be floatey 
*/

#include <stdio.h>

double operation(int num, int digit){
    int sum;
    double avg;
    printf("SUM of %d digits below %d = %d \n", num, digit, sum);
    return 420;
    return avg;
}

int main(){
    int num, digit;
    printf("Please enter a long-ass number: ");
    scanf("%d", &num);
    printf("Please enter a random number (1/9): ");
    scanf("%d", &digit);

    printf("AVG of %d digits below %d = %.2lf \n\n", \
                num, digit, operation(num, digit));

    return 0;
}
```
-->

### 7. Derivatives

- todo
  - implement a function to receive constant value and power n
  - then calculate the Derivative
  - return the value of the position.
- example:
  - c = 4; x = 2; n = 3;


```c
#include <stdio.h>
#include <math.h>


float derivative(float c, float x, float n){
    float der;

    der = n * c * pow(x, n-1);
    return der;
}


int main(){
    float c, x, n;
    c=4;
    x=2;
    n=3;

    printf("%.4f \n", derivative(c,x,n));

    return 0;
}
```

### 8. Sum of Divisors & Sum of Advisors

#### Divisors!

- todo
  - write function that receives 'num' integer
  - calculate and return SUM OF DIVISORS
  - (divisor if 'num % divisor == 0' )
- examples
  - 12: 1,2,3,4,6,12
  - 15: 1,5,15


```c
#include <stdio.h>

/* not optimized solution
int sumOfDivisors(int num){
    int i, sum=1+num;

    if (num == 1)
        return num;
    for (i=2; i <= num/2; i++){
        if (num % i == 0)
            sum+=i;
    }
    return sum;
}
*/

int sumOfDivisors(int num){
    int i, sum=1;
    if (num==1)
        return 1;
    for (i=2; i*i<num; i++){
        if (num%i==0)
            sum+=i+num/i;
    }
    return sum+num;
}

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("SUM OF DIVISORS = %d \n", sumOfDivisors(num));
    return 0;
}
```


<details>
<summary>prototype</summary>

```c
#include <stdio.h>

int sumOfDivisors(int num){
    int sum, i;
    for (i=1;i<=num;i++){
        if (num%i==0)
            sum+=i;
    }
    return sum;
}

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    printf("SUM OF DIVISORS = %d \n", sumOfDivisors(num));
    return 0;
}
```

</details>


### 9. Perfect Numbers

- todo
  - write function that receives int 'num' to
  - return 1 if num is perfect, 0 otherwise
  - (perfect number == num with a value that equals the sum of its divisors EXCLUDING the num itself)
- examples
  - 6: 1,2,3 = 6 // perfect
  - 12: 1,2,3,4,6 = 16 // not perfect
  - 15: 1,3,5 = 9 // not perfect
  - 28: 1,2,4,7,14 = 28 // perfecct


```c
#include <stdio.h>

int isPerfect(int num){
    int i, sum=1;
    for (i=2; i*i<num;i++){
        if (num%i==0)
            sum+=i+num/i;
    }
    if (sum==num)
        return 1;
    return 0;
}

int main(){
    int num;
    printf("Enter num: ");
    scanf("%d", &num);
    if (isPerfect(num))
        printf("%d is a perfect number \n", num);
    else printf("%d ain't a perfect number \n", num);
    return 0;
}
```

> Alternatively, take a **"modular"** approach and split functionality into separate functions dawg!