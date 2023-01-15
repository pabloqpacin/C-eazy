# C wiki


## .h libraries

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


## commands/functions

| Section | Function | functionality          |
| ------- | ----     | --------               |
| 1       | printf() | print to screen        |
| ...     | puts()   | ...                    |
| 2       | scanf()  | read user input        |
| 2.9     | pow(x,y) | elevates to the power  |
| 2.9     | sqrt()   | calculates square root |




## Variable Types

| Section | Type     | Content               |
| ------- | ----     | --------              |
| 2       | int      | integers              |
| 2       | double   | int + floating point  |
| 2       | float    | floating point        |

> see [documentation](/docs/documentation.md) on `double` vs `float`




## 'placeholders'

| Section | placeholder | role                           |
| ------- | ----        | --------                       |
| 1       | %d          | replace integer                |
| 1       | %f          | replace floating point numbers |
| 1       | %.2f        | only 2 decimals                |
| 1       | %c          | replace character [1]          |
| 2       | %lf         | for **doubles**                |
