# 1. Basics of C

<!--
- Documentation
  - Clean [C code](/source/)
  - [Clang-wiki](/docs/Clang-wiki.md)
- Lectures
  - **format specification**
  - MILESTONE: [calculator-A](/source/02-PrintfPrograms/calculatorA.c)
  - PRACTICALS-1
-->


## Welcome First Program


### C Program Structure

```c
#include <stdio.h>

int main(){
    printf("Hello World\n");
    return 0;
}
```



### Welcome **printf() function**!

<details>
<summary>Snippet</summary>

```c
#include <stdio.h>
// Glue different funtionalities // .h libraries
/* "standard input/output" functionality
(input=keyboard, output=screenDisplay) */

int main(){
/* main = entry point for actual commands
'{ }' == container for commands, ie. '{ foo }' */

    printf("Hello World!\n");
    puts("Supdawg\n\n");

    return 0;
    // OS reckons success // return(0); - OK TOO
}
```

</details>

### Challenge #1 - Print Your First Name and Last Name!
### Challenge #2 - Print ...
### Challenge #3 - Print an "Isosceles Triangle"

<details>
<summary>Snippet</summary>

```c
#include <stdio.h>

int main()
{
    // Chall. #1 - Print Name
    printf("Name's Pablo, \nPablo Quevedo Pacin \n\n");
   
    // Chall. #2 - Print some strings
    printf("Full name: Pablo Quevedo Pacin\nAge: 27 years young\nGender: lmao\n\n");
        // All 'printf()' lines require '\n'; else they print in the same line!
        // note 'printf()' should take 1 line; can't split the parenthesis into many lines
    printf("Full name: Pablo Quevedo Pacin\n");
    printf("Age: 27yo IE way too f* old\n");
    printf("Gender: feminist male lmao\n\n");
  
    
    // Chall. #3 - Print Isosceles Triangle
    printf("  *  \n *** \n*****\n\n");
    // Several lines
    printf("  *  \n");
    printf(" *** \n");
    printf("*****\n\n");

    return 0;
}
```
</details>

## Comments & Format Specification

### Format Specifications in C

- **PLACEHOLDERS**
  - '%d == Integer number; ok if SUM ('2+2')
  - '%f' == Floating point number
  - '.<number>' == digits to return

### PDF exercises

```c
#include <stdio.h>

int main(){
    
    /* %d */
    printf("I'm 27 yo\n");
    printf("I'm %d dawg\n", 27);
    printf("I'm %d yo while yer %d\n\n", 27, 23);
    
    /* %.2f */
    printf("Me fave number is %f\n", 1.2);
    printf("Me fave number is %.2f\n\n", 4.2);

    /* FORMAT SPECIFICATIONS (PDF) */
    printf("a=%d, b=%d, a+b=%d \n", 5, 7, 5+7);  
    printf("a=%d, b=%d, a+b=%d+%d=%d \n", 3, 2, 3, 2, 5);
    printf("a=%d, b=%d, a+b=%d+%d=%d \n\n", 4, 6, 4, 6, 4+6);
    
    return 0;
}

```

### Milestone #1 - Building Your First Calculator A

```c
/* Milestone #1: First Calculator

Write a program that will print on the screen the
results of 5 mathematical operations:

    Addition (+)
    Substraction (-)
    Multiplication (*)
    Division (/)
    Remainder (%)

(Stick to the integers '5' & '2')
*/

#include <stdio.h>

int main()
{

    printf(" %d + %d = %d = %.2d \n\n", 5, 2, 5+2, 7);
    printf(" %d - %d = %d = %.2d \n\n", 5, 2, 5-2, 3);
    printf(" %d * %d = %d = %.2d \n\n", 5, 2, 5*2, 10);

    /* notice '5/2' equals integer '2'
    as per correction, we take the FULL part of the division */
    printf(" %d - %d = %d = %.3f \n\n", 5, 2, 5/2, 2.5);
    printf(" %d %% %d = %d \n\n", 5, 2, 5%2);

    return 0;
}
```

## Practicals Part #1: Basics of C Programming

```c
#include <stdio.h>

int main()
{
    // A) Asterisks Rectangle
    printf("**********\n**********\n**********\n**********\n**********\n\n");

    // B) Pattern
    printf("1*********\n12********\n123*******\n1234******\n12345*****\n\n");

    // C) X Shape
    printf("*   *\n * * \n  *  \n * * \n*   *\n\n");    // only 5 Col per line
    printf("*       *\n  *   * \n    *   \n  *   * \n*       *\n\n");

    // D) Print: Current Year - Age = Birth Year
    printf("We are in %d and I'm %d yo therefore I was born in %d \n\n", 2023, 27, 2023-27);
        // Hold on; this is not accurate cuz my age may change; should determine MONTHS aye!

    return 0;

}
```





## custom C

- `puts`

| printf() | =  | puts() |
| ---      |--- |---     |

- **placeholders**

```c
#include <stdio.h>


int main(){
    
    printf("Year: %d \nWeek: %.2d \nDay: %c \n\n", 2023, 2, 'W');

    // (https://stackoverflow.com/questions/10947965/why-is-c-used-in-c)
    // Because %d will print the numeric character code of the char,
    printf("%d \n", 'a');       //prints 97 (on an ASCII system), while
    printf("%c \n\n", 'a');       // prints a.

    return 0;

}
```

<!--
SHOULD LOOK MORE INTO THE LAST SNIPPET!
-->