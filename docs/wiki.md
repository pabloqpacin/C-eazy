# C wiki

<details>
<summary>Table of Contents</summary>

- [C wiki](#c-wiki)
  - [Headers .h](#headers-h)
  - [Functions - Commands](#functions---commands)
  - [Variables](#variables)
  - [Format Specifiers](#format-specifiers)
  - [Math formulas](#math-formulas)
  - [Operators](#operators)
    - [Relational Operators](#relational-operators)
    - [Logical Operators](#logical-operators)
    - [Assignment Operators ( + Arithmetic)](#assignment-operators---arithmetic)
  - [Numeral Systems ](#numeral-systems-)
    - [BIN: Position Value (`k`=0/1)](#bin-position-value-k01)
    - [DEC to BIN to DEC Conversion example](#dec-to-bin-to-dec-conversion-example)
    - [BIN \& HEX Position Value ](#bin--hex-position-value-)
  - [Other conventions](#other-conventions)
- [Snippetz](#snippetz)

</details>

## Headers .h

<!-- random documentation
- https://stackoverflow.com/questions/55420836/is-it-good-practice-to-always-include-the-standard-headers
-->

| Section | library    | functionality         | notes                  |
| ------- | ----       | --------              | ---                    |
| 1       | <stdio.h>  | standard input/output |                        |
| x       | <stdlib.h> | -                     |                        |
| 2       | <math.h>   | math functions        | `gcc foo.c -o foo -lm` |
| 7       | <string.h> | working with strings

> notably he won't discuss `<stdlib.h>`

<details>
<summary>[solved] Compiler error with <\math.h></summary>

1. problem
```bash
[Running] cd "/home/pabloqpacin/ASIR+/C-eazy/2-Variables/" && gcc practicals2-9.c -o practicals2-9 && "/home/pabloqpacin/ASIR+/C-eazy/2-Variables/"practicals2-9
/usr/bin/ld: /tmp/ccM2AvDd.o: in function `main':
practicals2-9.c:(.text+0x134): undefined reference to `sqrt'
collect2: error: ld returned 1 exit status
```

2. documentation
   1. [documentation1](https://stackoverflow.com/questions/10409032/why-am-i-getting-undefined-reference-to-sqrt-error-even-though-i-include-math)
   2. [documentation2](https://www.knowprogram.com/c-programming/undefined-reference-to-sqrt-or-other-mathematical-functions-even-includes-math-h-header/)
   3. [documentation3](https://stackoverflow.com/questions/57173093/how-to-include-compiler-flags-in-visual-studio-code)

3. solution: add `-lm` to CLI command or VSCode's `tasks.json`!

```bash
# Add -lm to gcc command
gcc foo.c -o foo -lm
```

```json
// .vscode/tasks.json
{
    "tasks": [
        {
            "args": [
                "-lm"
            ]
        }
    ]
}
```

</details>


## Functions - Commands

| Section | Function          | functionality          | notes |
| ------- | ----              | --------               | ---   |
| 1       | printf()          | print to screen        |
| ...     | puts()            | print string           |
| 2       | scanf()           | read user input        |
| 2.9     | pow(x,y)          | elevates to the power  |
| 2.9     | sqrt()            | calculates square root |
| 7       | ~~[gets()](https://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-used)~~   | `scanf` for strings, dangerous! |
| 7       | [fgets()](https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm)   | `scanf` for strings |
| 7       | strlen(str)       | finding the lenth      | `<string.h>`
| 7       | strcpy(dest,src)  | copying content        | `<string.h>`
| 7       | strcat(dest,src)  | concatenating          | `<string.h>`
| 7       | strcmp(str1,str2) | comparing as per ASCII | `<string.h>`




## Variables

| Section | Type      | Content               |
| ------- | ----      | --------              |
| 2       | int       | integers              |
| 2       | double    | int + floating point  |
| 2       | float     | floating point        |
| 3B      | character | character             |

> see [documentation](/docs/documentation.md) on `double` vs `float`




## Format Specifiers

| Section | placeholder | role                           | notes
| ------- | ----        | --------                       | ---
| 1       | %d          | replace integer                | may ASCII dec
| 1       | %f          | replace floating point numbers |
| 1       | %.2f        | only 2 decimals                |
| 2       | %lf         | for **doubles**                |
| 3B      | %c          | replace character [1]          | ASCII value
| 3B      | %X          | provide HEX                    | ASCII in hex
| 6       | %lu         | memory address (decimal)       | **'long unsigned int'**
| 6B      | %p          | memory address (hex)           | ... // `printf("%p", &a);`
| 7       | %s          | strings                        | last char = default `\0` 



<details>
<summary>ASCII...</summary>

```c
#include <stdio.h>

int main(){

    char myChar1 = 'a';
    printf("Select a character: ");
    scanf("%c", &myChar1);
        // what if we scan for %X or alike...

    printf("- Character: %c \n", myChar1);
    printf("- Decimal ASCII Code: %d \n", myChar1);
    printf("- Hexadecimal ASCII Code: %X \n\n", myChar1);
        // And the binary?

    return 0;
}
```
</details>


## Math formulas


| Section | To-do                                | Formula                       |
| ---     | ---                                  | ---                           |
| 2.1     | **n-th Term of Arithmetic Sequence** | `an = a1 + (n - 1) * d`       |
| 2.2     | **Sum of Arithmetic Sequence**       | `Sn = (a1 + an) * n / 2`      |
| 2.9     | **distance between 2 given points**  | `d = √ (x1-x2)^2 + (y1-y2)^2` |
| 5       | **Factorial of n**                   | `F(n)=1*2*3*...*n`            |
| 5.7     | **Derivatives**                      | `(c*x^n) = n*c*x^(n-1)`       |

## Operators

> extra documentation:
- [x] @Programiz: [C Programming Operators](https://www.programiz.com/c-programming/c-operators)
- [ ] @Programiz: [Bitwise Operators in C Programming](https://www.programiz.com/c-programming/bitwise-operators)
- [ ] GeeksForGeeks: [Operators in C](https://www.geeksforgeeks.org/operators-in-c/)

### Relational Operators

| Section | Operator | Meaning                  | 
| ---     | ---      | ---                      | 
| 3       | >        | Greater than             |
| 3       | >=       | Greater than or equal to |
| 3       | <=       | Less than                |
| 3       | <=       | Less than or equal to    |
| 3       | ==       | 'left' equals to 'right' |
| 3       | !=       | Not equals to            |

> notice that `==` is a Relational Operator, while `=` won't be used to check any condition but rather an **Assignment Operator**



### Logical Operators

| Section | Operator | Symbol | Meaning              | 
| ---     | ---      | ---    | ---                  | 
| 3       | AND      | &&     | both operands true   |
| 3       | OR       | \|\|   | either is true       |
| 3       | NOT      | !      | reverses value       |


<details>
<summary>Truth Tables [AND OR NOT]</summary>

| Operand | Operator | Result |
| ---     | ---      | ---    |
| T       | NOT      | F      |
| F       | NOT      | T      |


| 1 condition | 2 condition | Operator | Result |
| ---         | ---         | ---      | ---    |
| T           | T           | AND      | T      |
| T           | F           | AND      | F      |
| F           | T           | AND      | F      |
| F           | F           | AND      | F      |


| 1 condition | 2 condition | Operator | Result |
| ---         | ---         | ---      | ---    |
| T           | T           | OR       | T      |
| T           | F           | OR       | T      |
| F           | T           | OR       | T      |
| F           | F           | OR       | F      |

</details>

### Assignment Operators ( + Arithmetic)

| Section | Operator     | Meaning        |
| ---     | ---          | ---            |
| 1       |  `+`         |                | 
| 1       |  `-`         |                | 
| 4       | foo `+=` bar | foo=foo+bar    | 
| 4       | foo `-=` bar | foo=foo-bar    | 
| 4       | foo`++`      | foo=foo+1      |
| 4       | foo`--`      | foo=foo-1      | 

> extensive to `*`, `/` and `%`; see documentation above




## Numeral Systems <!--(3.5)-->


<details>
<summary>0-16: DEC BIN OCT HEX</summary>

| DEC | BIN   | OCT | HEX |
| --- | ---   | --- | --- |
| 0   | 0     | 0    | 0   |
| 1   | 1     | 1    | 1   |
| 2   | 10    | 2    | 2   |
| 3   | 11    | 3    | 3   |
| 4   | 100   | 4    | 4   |
| 5   | 101   | 5    | 5   |
| 6   | 110   | 6    | 6   |
| 7   | 111   | 7    | 7   |
| 8   | 1000  | 10    | 8   |
| 9   | 1001  | 11    | 9   |
| 10  | 1010  | 12    | A   |
| 11  | 1011  | 13    | B   |
| 12  | 1100  | 14    | C   |
| 13  | 1101  | 15    | D   |
| 14  | 1110  | 16    | E   |
| 15  | 1111  | 17    | F   |
| 16  | 10000 | 20    | 10  |
| ... | ...   | ...   | ... |
| 26  | 11010 | 32    | 1A  |

> BIN 011.010 = 32 OCT
> 
> BIN: 0001.1010 = 1A HEX

</details>


> NOTE: in `0011`, the **first `0`s** are *'leading zeroes'*
>

| CONVERTION ARITHMETICS |`digit value = base^position` |
| --- | --- |


### BIN: Position Value (`k`=0/1)

| k8   | k7   | k6  | k5  | k4  | k3  | k2  | k1  | k0  |
| ---  | ---  | --- | --- | --- | --- | --- | --- | --- |
| 256  | 128  | 64  | 32  | 16  | 8   | 4   | 2   | 1   |

<!-- > - [ ] signed thing? -->



### DEC to BIN to DEC Conversion example

| DEC | BIN            |
| --- | ---            |
| 700 | 10-1110-1001 |

| 1   | 0       | 1   | 1   | 1   | 0       | 1   | 0       | 0     | 1   |
| --- | ---     | --- | --- | --- | ---     | --- | ---     | ---   | --- |
| 512 | ~~256~~ | 128 | 64  | 32  | ~~16~~  | 8   | ~~4~~   | ~~2~~ | 1   |

<details>
<summary>operations</summary>

> 233 = 128 + 64 [192] + 32 [224] + 0 (~~16 [240]~~) + 8 [232] + 0 + 1 [233]


| iteration | (remainder)       | value 
| ---       | ---               | ---
| k0        | 700 / 2 = 350 (0) | 1
| k1        | 350 / 2 = 125 (0) | 2
| k2        | 175 / 2 = 87 (1)  | 4
| k3        | 87 / 2 = 43 (1)   | 8
| k4        | 43 / 2 = 21 (1)   | 16
| k5        | 21 / 2 = 10 (1)   | 32
| k6        | 10 / 2 = 5 (0)    | 64
| k7        | 5 / 2 = 2 (1)     | 128
| k8        | 2 / 2 = 1 (0)     | 256
| k9        | 1 / 2 = 0 (1)     | 512
| k10       | 0 / 2 = 0 (0)     | 1024
| k11       | 0 / 2 = 0 (0)     | 2048

</details>

### BIN & HEX Position Value <!--weight-->

| iteration | BIN power     | HEX power
| ---       | ---           | ---   
| k0        | 2^0 = 1       |  16^0 = 1
| k1        | 2^1 = 2       |  16^1 = 16
| k2        | 2^2 = 4       |  16^2 = 256
| k3        | 2^3 = 8       |  16^3 = 4096
| k4        | 2^4 = 16      |  16^4 = 65,536
| k5        | 2^5 = 32      |  16^5 = 1,048,576
| k6        | 2^6 = 64      |  16^6 = 16,777,216
| k7        | 2^7 = 128     |  16^7 = 268,435,456
| k8        | **2^8 = 256** |  16^8 = 4,294,967,296
| k9        | 2^9 = 512     |  16^9 = 68,719,476,736
| k10       | 2^10 = 1024   |  16^10 = 1,099,511,627,776





## Other conventions

| Section | Letter | Meaning             |
| ---     | ---    | ---                 |
| 3B      | `k`    | number of iteration |




# Snippetz


<details>
<summary>S2 - secondz conversion</summary>

```c
#include <stdio.h>

int main(){

    int seconds;
    int hours, minutes, remainingSeconds;

    printf("Enter the total seconds: ");
    scanf("%d", &seconds);

    hours = seconds/3600;
    minutes = (seconds - hours*3600) / 60;
    remainingSeconds = (seconds - hours*3600) % 60;

    printf("%.2d:%.2d:%.2d \n", hours, minutes, remainingSeconds);

    return 0;
}
```

</details>

<details>
<summary>S3 - breakdown number digitz</summary>

```c
#include <stdio.h>

/* Section 3 - mind the 'num % 10' operations aye */

int main()
{
	int num;
	int units, tens, hundreds;
	printf("Enter a 3-digit num: ");
	scanf("%d", &num);

	units = num % 10;
	tens = (num / 10) % 10;
	hundreds = num / 100;

	if (hundreds < tens && tens < units)
		printf("ASCENDING\n");
	else 
		printf("NOT ASCENDING\n");

	return 0;
}
```
</details>

- if statementz <!--course VS https://www.programiz.com/c-programming/c-if-else-statement-->
  - see [ChatGPT take](/3-Conditions/readme.md#chatgpt-on-if-statements) on **if-statements**
- switch-casez
- loopz
