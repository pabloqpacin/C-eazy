# C wiki


## Headers .h

<!-- random documentation
- https://stackoverflow.com/questions/55420836/is-it-good-practice-to-always-include-the-standard-headers
-->

| Section | library    | functionality         | notes                  |
| ------- | ----       | --------              | ---                    |
| 1       | <stdio.h>  | standard input/output |                        |
| x       | <stdlib.h> | -                     |                        |
| 2       | <math.h>   | math functions        | `gcc foo.c -o foo -lm` |

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

| Section | Function | functionality          |
| ------- | ----     | --------               |
| 1       | printf() | print to screen        |
| ...     | puts()   | ...                    |
| 2       | scanf()  | read user input        |
| 2.9     | pow(x,y) | elevates to the power  |
| 2.9     | sqrt()   | calculates square root |




## Variables

| Section | Type     | Content               |
| ------- | ----     | --------              |
| 2       | int      | integers              |
| 2       | double   | int + floating point  |
| 2       | float    | floating point        |

> see [documentation](/docs/documentation.md) on `double` vs `float`




## 'Placeholders'

| Section | placeholder | role                           |
| ------- | ----        | --------                       |
| 1       | %d          | replace integer                |
| 1       | %f          | replace floating point numbers |
| 1       | %.2f        | only 2 decimals                |
| 1       | %c          | replace character [1]          |
| 2       | %lf         | for **doubles**                |


## Math formulas


| Section | To-do                                | Formula                       |
| ---      | ---                                  | ---                           |
| 2.1       | **n-th Term of Arithmetic Sequence** | `an = a1 + (n - 1) * d`       |
| 2.2       | **Sum of Arithmetic Sequence**       | `Sn = (a1 + an) * n / 2`      |
| 2.9       | **distance between 2 given points**  | `d = √ (x1-x2)^2 + (y1-y2)^2` |


## Relational Operators

| Section | Operator | Meaning                  | 
| ---     | ---      | ---                      | 
| 3       | >        | Greater than             |
| 3       | >=       | Greater than or equal to |
| 3       | <=       | Less than                |
| 3       | <=       | Less than or equal to    |
| 3       | ==       | 'left' equals to 'right' |
| 3       | !=       | Not equals to            |

> notice that `==` is a Relational Operator, while `=` won't be used to check any condition but rather an **Assignment Operator**



## Logical Operators

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

# Snippetz

<details>
<summary>breakdown number digitz</summary>

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
- switch-casez
- 