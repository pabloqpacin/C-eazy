# 3B - Binary, Hex and ASCII

## Introduction to Bits, Bytes and Binary Numbers

Intro
- Decimal Digit: 0,1,2,3,4,5,6,7,8,9
- English Letter: A,B,C,...Z,a,b,c,...z
- Bit: 0,1
- **A `bit` can be either `0` or `1` - total of two options**
- **A `bit` is a basic unit in computing**

Bits & Bytes
- A `bit` is just a basic unit to represent a *value*
- A `byte` is a sequence of **8 bits**

|0  |1  |1  |0  |1  |1  |1  |0  |0  |
|---|---|---|---|---|---|---|---|---|

|1  |1  |0  |1  |1  |0  |0  |0  |0  |
|---|---|---|---|---|---|---|---|---|

|1  |1  |0  |0  |1  |1  |0  |1  |1  |
|---|---|---|---|---|---|---|---|---|

> - [ ] **9th bit** is *signed/unsigned*!!

Decimal Numbers
- **[Base 10]**
- *Poition & power*: `... 3 2 1 0`
- examples
  - `2463 = 2\*10^3 + 4\*10^2 + 6\*10^1 + 3*10^0`
- A "Decimal Number" consists of **"digits"**.
- "Digits" are placed at "positions", from right to left, starting at **position 0**.
- There's a "weight" associated with each digit position (*power*).
- `weight = base^position`

| Decimal [Base10] | Binary [Base2] |
| ---              | ---            |
| 0                | 0              |
| 1                | 1              |
| 2                | 10             |
| 3                | 11             |
| 4                | 100            |
| 5                | 101            |
| 6                | 110            |
| 7                | 111            |
| 8                | 1000           |
| 9                | 1001           |
| 10               | 1010           |

> see [wiki's Decimal/Binary Table](/docs/wiki.md#numeral-systems)

Binary Numbers
- **[Base 10]**
- same Positions & weight, power
- examples
  - `1101 = 1\*2^3 + 1\*2^2 + 0\*2^1 + 1*2^0 = 8 + 4 + 0 + 1 = 13`


### Base Notations

| Decimal numbers | Binary Numbers | Hex        |
| ---             | ---            | ---        |
| 25v10           | 101v2          | 2A3v16     |
| 25d             | 101b or 101B   | 2A3vh      |
| **0b**          |                | **0x 2A3** |

> - [x] **HEX notation**!

## Decimal to Binary Conversion


- Given number `X` in decimal
- Divide `X` by 2 and add **remainder** to binary
  - The **remainder** (0/1) will be added to bit `k` (*k* = number of iteration)
- Repeat step 2 while `X!=0`

> 1st iteration (k0)=position0, k1=position1, k2=position, ...
>
> The contribution of the value at `bit i` is `2^k`

### Practice

#### Decimal 5 == Binary 101

| iteration | (remainder)   |
| ---       | ---           |
| k0        | 5 / 2 = 2 (1) |
| k1        | 2 / 2 = 1 (0) |
| k2        | 1 / 2 = 0 (1) |

#### Decimal 11 = Binary 1011

| iteration | (remainder)    |
| ---       | ---            |
| k0        | 11 / 2 = 5 (1) |
| k1        | 5 / 2 = 2 (1)  |
| k2        | 2 / 2 = 1 (0)  |
| k3        | 1 / 2 = 0 (1)  |


#### Additional Exercises

| DEC | BIN                   | HEX
| --- | ---                   | ---
| 23  | 1-0111                | 0x17
| 54  | 11-0110               | 0x36
| 15  | 1111                  | 0x000F
| 345 | 1-0101-1001           | 0x159
| 700 | 1-1111-1111-1011-1101 | 0x2BC

<details>
<summary>Breakdown</summary>

##### 23d == 10111b == 0x77

| iteration | (remainder BIN)     | (remainder HEX)   |
| ---       | ---                 | ---               |
| k0        | 23 / 2 = 11 (1)     | 23 / 16 = 1 (7) |
| k1        | 11 / 2 = 5 (1)      | 1 / 16 = 0 (1)
| k2        | 5 / 2 = 2 (1)       |
| k3        | 2 / 2 = 1 (0)       |
| k4        | 1 / 2 = 0 (1)       |

##### 54d == 110110b == 0X

| iteration | (remainder)     | (remainder HEX)
| ---       | ---             | --- 
| k0        | 54 / 2 = 27 (0) | 54 / 16 = 3 (6)
| k1        | 27 / 2 = 13 (1) | 3 / 16 = 0 (3)
| k2        | 13 / 2 = 6 (1)  |
| k3        | 6 / 2 = 3 (0)   |
| k3        | 3 / 2 = 1 (1)   |
| k4        | 1 / 2 = 0 (1)   |

##### 345d = 1-0101-1001b == 0x159

| iteration | (remainder)       | value | (remainder HEX)
| ---       | ---               | ---   | ---
| k0        | 345 / 2 = 172 (1) | 1     | 345 / 16 =  21 (9)
| k1        | 172 / 2 = 86 (0)  | 2     | 21 / 16 = 1 (5)
| k2        | 86 / 2 = 43 (0)   | 4     | 1 / 16 = 0 (1)
| k3        | 43 / 2 = 21 (1)   | 8     |
| k3        | 21 / 2 = 10 (1)   | 16    |
| k4        | 10 / 2 = 5 (0)    | 32    |
| k4        | 5 / 2 = 2 (1)     | 64    |
| k4        | 2 / 2 = 1 (0)     | 128   |
| k4        | 1 / 2 = 0 (1)     | 256   |


##### 700d == 10-1011-1100b == 0x2BC

| iteration | (remainder)       | value | (remainder HEX)
| ---       | ---               | ---   | ---
| k0        | 700 / 2 = 350 (0) | 1     | 700 / 16 =  43 (12)
| k1        | 350 / 2 = 125 (0) | 2     | 43 / 16 = 2 (11)
| k2        | 175 / 2 = 87 (1)  | 4     | 2 / 16 = 0 (2)
| k3        | 87 / 2 = 43 (1)   | 8     |
| k4        | 43 / 2 = 21 (1)   | 16    |
| k5        | 21 / 2 = 10 (1)   | 32    |
| k6        | 10 / 2 = 5 (0)    | 64    |
| k7        | 5 / 2 = 2 (1)     | 128   |
| k9        | 2 / 2 = 1 (0)     | 256   |
| k9        | 1 / 2 = 0 (1)     | 512
| k9        | 0 / 2 = 0 (0)     | 1024

</details>


## Hexadecimal Numbers - Base 16 Notation

Intro - what is a Hex Value?
- Decimal Digits: 0,1,2,3,4,5,6,7,8,9
- Bits: 0,1
- Hex Digits: 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
  - A Hex Digit has 16 options

> see [wiki's table](/docs/wiki.md#numeral-systems) again


### HEX to DEC

Hexadecimal Numbers
- **[Base 16]**
- *Poition & power*: `... 3 2 1 0`
- examples
  - `0x 2A3 = 2\*16^2 + 10\*16^1 + 3\*16^0 = 512 + 160 + 3 = 675`
  - `0X 10 = 1\*16^1 + 0*16^0 = 16 +0 = 16`

<details>
<summary>Hex Power</summary>

| iteration | power op | POWER |
| ---       | ---      | ---   |
| k0        | 16^0     | 1     |
| k1        | 16^1     | 16    |
| k2        | 16^2     | 256   |
| k3        | 16^3     | 4096  |

</details>

#### Practice

| Hex    | Dec    | BIN |
| ---    | ---    | --- 
| 0x123  | 291    | 0001-0010-0011
| 0x2F   | 47     | 0010-1111
| 0x000F | 15     | 0000-0000-0000-1111 
| 0xA2   | 162    | 1010-0010
| 0xABCD | 43,981 | 1010-1011-1100-1101

- 0x123 = 1\*16^2 + 2\*16^1 + 3\*16^0 = 256 + 32 + 3 = 291
- 0x2F = 2\*16^1 + 15*16^0 = 32 + 15 = 47
- 0x000F = 0 + 0 + 0 + 15 = 15
- 0xA2 = 10\*16^2 + 2\*16^0 = 160 + 2 = 162
- 0xABCD = 10\*16^3 + 11\*16^2 + 12\*16^1 + 13\*16^0 = 40,960 + 2816 + 192 + 13 = 43,981

### DEC to HEX

Intro
- Given number `X` value in decimal
- Divide `X` by 16 and add **remainder** to Hex
- The *remainder (0-F)* will be added to digit `k`
- Repeat while `X!=0`

Examples
- 123d == 0X7B

| iteration | (remainder)       | AKA |
| ---       | ---               | --- |
| k0        | 123 / 16 = 7 (11) | B   |
| k1        | 7 / 16 = 0 (7)    | 7   |

Additional
> - [x] see other Additional above!

### HEX to BIN

conversion
- recap
  - Hexadecimal Number [Base 16]
  - Binary Number [Base 2]
- Both are based on powers of 2
- **1 HEX Digit == 4 BIN Digits**
- example
  - 0x2A3 = 10-1010-0011

practice

> see above!!

### BIN to HEX

example
- 1101-0110 == 0xD6

practice!

| BIN                        | HEX      |
| ---                        | ---      |
| 0b 0110-1101               | 0x 6D    |
| 0b 11-1111-1011            | 0x 3FB   |
| 0b 0-0011                  | 0x 03    |
| 0b 10-1010-1010-1010-1011  | 0x 2AAAB |
| 0b 000-0110-0001-0011-1000 | 0x 06138 |


## Introduction to ASCII table!

ASCII
- 'American Standard Code for Information Interchange'
- Is a character encoding scheme
- Characters/Symbols such as:
  - lower/upper case letters (a-z, A-Z)
  - digits (0-9)
  - punctuation
  - symbols
- each symbol has its own associated **"encoding"** ie. number

```bash
# Install ascii CLI program!!
apt show ascii && sudo apt install ascii
ascii -d
ascii -h
ascii -b
```

ASCII table
- notice the **numbers**, the actual characters for all digits, have a Dec/Hex/Bin encoding!!
  - such encoding goes from *48 to 57 (Dec)* (sequence!)
- capital letters ('A-Z`) bounded from *65 to 90*
- lowercase ('a-z'): *97 to 122*


## (Memory Representation) Practical Example for Displaying Values **(!)**

```c
#include <stdio.h>

// ASCII1.c

int main(){

    char myChar1 = 'a';
    printf("Select a character: ");
    scanf("%c", &myChar1); // here the BINARY ASCII encoding is saved to the MEMORY (random ADDRESS)
        // what if we scan for %X or alike...

    printf("- Character: %c \n", myChar1);
    printf("- Decimal ASCII Code: %d \n", myChar1);
    printf("- Hexadecimal ASCII Code: %X \n\n", myChar1);
        // And the binary?

    return 0;
}
```

## ASCII Memory Representation & Summary

Meaning **all these three variables will be stored as `01100001` in different memory addresses :D**

```c
#include <stdio.h>

// ASCII2.c

int main(){
    char myChar1 = 'a';
    char myChar2 = 97;
    char myChar3 = 0x61;

    printf("'Char1' == %c, %d, %X\n", myChar1, myChar1, myChar1);
    printf("'Char2' == %c, %d, %X\n", myChar2, myChar2, myChar2);
    printf("'Char3' == %c, %d, %X\n", myChar3, myChar3, myChar3);

    return 0;
}
```

Now in this case, while `'9'` represents ASCII-57 (`00111001`), `9` will be ASCII-9 (`00001001`)

```c
int main(){
    char myChar1 = 9;
    char myChar2 = '9';

    return 0;
}
```

In summary
- Each character (symbol) has its own "numerical" ASCII Code
- The ASCII Code can be seen in the ASCII Table in various formats:
  - Decimal
  - Hexadecimal
  - Binary
  - etc.
- Eventually, same value can be represented in various formats


## A program to Print a Date in Hexadecimal

- todo
  - receive 3 values from user (year, month, day)
  - print date in Hex
  - example: 2012-08-20 = 0x7DC-0x8-0x14

```c
#include <stdio.h>

int main(){

    int day, month, year;

    printf("Enter DATE [day-month-year]: ");
    scanf("%d%d%d", &day, &month, &year);
    
    printf("Your date in HEX will be: (0x) %X-%X-%X \n", day, month, year);

    return 0;
}
```


## Inspecting a Textual File Stored on Disk

- save file with `helloworld` string
- open editor
  - see HEX value for each character! 

```bash
# Bin files editor
apt show okteta
```

## Programs to check if an input is Lower_Upper_Case_Letter_or_Digit

- todo
  - receive a **character** from user
  - print whether the character is
    - lowercase letter
    - uppercase letter
    - digit
    - other (symbol, etc.)


```c
#include <stdio.h>

// ASCII4.c
// NOTICE WE USE '0', 'A' NOTATTION!!

int main(){

    char myChar;

    printf("Enter a character: ");
    scanf("%c", &myChar);
        // printf("You entered: %c - %d - %X \n", myChar, myChar, myChar);

    if (myChar >= '0' && myChar <= '9')
        printf("'%c' is a DIGIT! \n", myChar);
    else if (myChar >= 'a' && myChar <= 'z')
        printf("'%c' is a Lowercase letter! \n", myChar);
    else if (myChar >= 'A' && myChar <= 'Z')
        printf("'%c' is an Uppercase letter! \n", myChar);
    else printf("'%c' is neither a Digit, \
    a Lowercase or an Uppercase Letter! \n", myChar);

    return 0;
}
```

<!-- Could it be done
using different notation for the condition?
IE instead of 'A', its DEC or HEX value (0d65,0x41)
-->

## Hex Assignment

1. What is the expected result of the following code execution?

```c
#include<stdio.h>

int main()
{
printf("%x", 65);
return 0;
}
```


| DEC | Operation        | HEX |
| --- | ---              | --- |
| 65  | 65 / 16 = 4 (1)  |
|     | 4 / 16 = 0 (4)   | 41


```bash
# ...
ascii 65
```


> `41`

2. What is the expected result of the following code execution?

```c
#include<stdio.h>

int main()
{
printf("%x", 123);
return 0;
}
```


| DEC  | Operation          | HEX |
| ---  | ---                | --- |
| 123  | 123 / 16 = 7 (11)  | 7B

> `7B`

3. What is the expected result of the following code execution?

```c
#include<stdio.h>

int main()
{
  printf("%d",0x1A2);
  return 0;
}
```


| HEX   | Operation                                    | DEC
| 0x1A2 | 1\*16^2 + 10\*16^1 + 2\*16^0 = 256 + 160 + 2 | 418

> `418`



4. Write a program that reads from the user 1 character representing a "1-digit" value in Hexadecimal Format. The program should print the corresponding BINARY representation of the input.

For example:
- '4' --> "0100".
- '7' --> "0111".
- 'A' --> "1010".

The input values can be 0,1,2,3,...,A,B,C,D,E,F.


```c
#include <stdio.h>

// ASCII5.c
// HEX to BIN conversion (not ASCII related)
// NOTICE '0', '7'... NOT 0, 7

int main(){

    char myChar;
    printf("Enter a HEX Digit dawg [0-F]: ");
    scanf("%c", &myChar);

    switch(myChar){
        case '0': printf("0x%c == 0000 \n", myChar); break;
        case '1': printf("0x%c == 0001 \n", myChar); break;
        case '2': printf("0x%c == 0010 \n", myChar); break;
        case '3': printf("0x%c == 0011 \n", myChar); break;
        case '4': printf("0x%c == 0100 \n", myChar); break;
        case '5': printf("0x%c == 0101 \n", myChar); break;
        case '6': printf("0x%c == 0110 \n", myChar); break;
        case '7': printf("0x%c == 0111 \n", myChar); break;
        case '8': printf("0x%c == 1000 \n", myChar); break;
        case '9': printf("0x%c == 1001 \n", myChar); break;
        case 'A': printf("0x%c == 1010 \n", myChar); break;
        case 'B': printf("0x%c == 1011 \n", myChar); break;
        case 'C': printf("0x%c == 1100 \n", myChar); break;
        case 'D': printf("0x%c == 1101 \n", myChar); break;
        case 'E': printf("0x%c == 1110 \n", myChar); break;
        case 'F': printf("0x%c == 1111 \n", myChar); break;
        default: printf("Please try again dawg..."); break;
    }

    return 0;
}
```