# Cpp Wiki

<details>
<summary>Table of Contents</summary>

- [Cpp Wiki](#cpp-wiki)
  - [1. Syntax](#1-syntax)
    - [Keywords](#keywords)
    - [Punctuation](#punctuation)
    - [Identifiers](#identifiers)
    - [Operators](#operators)
      - [Operator Precedence](#operator-precedence)
    - [STREAM MANIPULATORS](#stream-manipulators)
  - [2. Datatypes](#2-datatypes)
    - [Primitive Datatypes](#primitive-datatypes)
      - [Character](#character)
      - [Integer](#integer)
      - [Floating-point](#floating-point)
      - [Boolean](#boolean)
    - [Not primitives](#not-primitives)
  - [3. Constants](#3-constants)
    - [Literal Constants](#literal-constants)
      - [Integer Literal Constants](#integer-literal-constants)
      - [Floating-point Literal Constants](#floating-point-literal-constants)
      - [Character Literal Constants (escape code)](#character-literal-constants-escape-code)
    - [Declared Constants](#declared-constants)
    - [Constant Expressions](#constant-expressions)
    - [Emumerated Constants](#emumerated-constants)
    - [Defined Constants](#defined-constants)
  - [i. Control Flow](#i-control-flow)
  - [n. ...OOP](#n-oop)
    - [...METHODS](#methods)
  - [m. SPECIAL FEATURES](#m-special-features)
    - [Preprocessor Directives](#preprocessor-directives)
    - [Libraries - Header files](#libraries---header-files)
      - [Cpp Standard Library header files](#cpp-standard-library-header-files)
      - [](#)
  - [z. APPENDIX](#z-appendix)
    - [Boolean Algebra](#boolean-algebra)
    - [input validation](#input-validation)
    - [...member functions](#member-functions)

</details>

<hr>

## 1. Syntax

### [Keywords](https://en.cppreference.com/w/cpp/keyword)

| keyword | info
| ---     | ---
| int
| return
| double
| ...


### Punctuation

| punctuation | info
| ---         | ---
| ;           | terminate statement
| { }   
| " "         | delimit string
| ' '         | delimit chars
| ( )
| < >         | contain objects/classes ?


### Identifiers

<!-- EG. #include, main, std, cout, cin, endl... -->

| identifier | info
| ---        | ---
| cin
| cout
| cerr       | -
| clog       | -
| endl       | endline stream manipulator, newline + flush stream buffer
| flush      | flush only, cout.flush()

### Operators

<!-- - Member access: eg.array subscript operator -->

| category   | operator | info
| ---        | ---      | ---
| assignment | =        | lvalue takes rvalue
| arithmetic | +        | addition
|            | -        | substraction
|            | *        | multiplication
|            | /        | division
|            | %        | modulo/remainder (ints only)
| increment  | ++       | increment by 1 <!--POINTERS DAWG-->
| decrement  | --       | decrement by 1
| equality   | ==       | equal
|            | !=       | not equal
| relational | >        | greater than
|            | >=       | greater than or equal to
|            | <        | less than
|            | <=       | less than or equal to
|            | <=>      | three-way comparison (C++20)
| logical    | !  &emsp;  not   | negation
|            | &&  &ensp;  and  | logical and
|            | \|\|  &emsp;  or | logical or
| compound   | +=       | lhs = lhs + (rhs);
|            | -=       | lhs = lhs - (rhs)
|            | *=       | lhs = lhs * (rhs)
|            | /=       | lhs = lhs / (rhs)
|            | %=       | lhs = lhs % (rhs)
| bitwise... | >>=      | lhs = lhs >> (rhs)
|            | <<=      | lhs = lhs << (rhs)
|            | &=       | lhs = lhs & (rhs)
|            | ^=       | lhs = lhs ^ (rhs)
|            | \|=      | lhs = lhs \| (rhs)
|            |          |
| ...        | <<       | stream insertion <!--chevron-->
|            | >>       | stream extraction
|            | ::       | scope resolution (!)
|            |          |
|            | sizeof() | queries object bit size
|            | .        | object.method

#### [Operator Precedence](https://en.cppreference.com/w/cpp/language/operator_precedence)

> Precedence & Associativity

| Precedence | Operator                  | Description      | Associativity  
| :-:        | ---                       | ---              | ---            
| 1          | ::                        | Scope resolution | Left-to-right →
| 2          | [] <br> -> <br> . <br> () | Function calls <br> Member access | "
| 3          | ++i <br> --i <br> not <br> -(unary) <br> *(de-ref) <br> & <br> sizeof | Prefix increment and decrement <br> Unary plus and minus <br> Logical and bitwise NOT <br> Indirection (dereference) <br> Address-of <br> Size-of | Right-to-left ←
| 4          | 
| 5          | a*b a/b a%b               | Multiplication, division and remainder | Left-to-right →
| 6          | a+b a-b                   | Division and substraction | "
| 7          | << >>                     | Bitwise left shift and right shift | "
| 8          |
| 9          | < <= > =>                 | Relational operators       | " 
| 10         | == !=                     | Equality operators         | "
| 11         | a&b                       | Bitwise AND                | "
| 12         | ^                         | Bitwise XOR (exclusive OR) | "
| 13         | \|                        | Bitwise OR (inclusive OR)  | "
| 14         | &&                        | Logical AND                | "
| 15         | \|\|                      | Logical OR                 | "
| 16         | ?: = op=                  | Ternary conditional, Direct assignment, Compound assignment | Right-to-left ←
| 17         | ,                         | Comma                      | Left-to-right →

### STREAM MANIPULATORS

> ...

| manipulator | info
| ---         | ---
| boolaplha   | sets booleans to true/false until turned off
| noboolalpha | resets booleans to 1/0

<hr>

## 2. Datatypes

| size (bits) | representable values       | power
| ---         | ---                        | ---
| 8           | 256                        | 2**8
| 16          | 65,536                     | 2**16
| 32          | 4,294,967,296              | 2**32
| 64          | 18,446,744,073,709,551,615 | 2**64

### Primitive Datatypes

#### Character

> Unicode...

| type     | info
| ---      | ---
| char     | 1 byte, at least 8 bits
| char16_t | At least 16 bits
| char32_t | At least 32 bits
| wchar_t  | Can represent the largest available character set

#### Integer

> signed/unsigned

| type                           | info
| ---                            | ---
| signed\|unsigned short int     | At least 16 bit
| signed\|unsigned int           | At least 16 bit
| signed\|unsigned long int      | At least 32 bit
| signed\|unsigned long long int | At least 64 bit

#### Floating-point

> represented by mantissa and exponent (scientific notation)
> precision and size are compiler-dependent

| type        | info              | typical range
| ---         | ---               | ---
| float       | 7 decimal digits  | 1.2x10**-38 to 3.4x10**38
| double      | 15 decimal digits | 2.2x10**-308 to 1.8x10**308
| long double | 19 decimal digits | 3.3x10**-4932 to 1.2x10**4932

#### Boolean

> true/false = 0 is false, non-zero is true
> used to know if something changes state (gameOver, keyPressed...)

| type | info
| ---  | ---
| bool | usually 8 bits, true/false

### Not primitives

- `size_t`: unsigned integer/long data type that is typically used to represent the size of an object or array

<hr>

## 3. Constants

### Literal Constants

#### Integer Literal Constants

| literal | info
| ---     | ---
| 12      | int
| 12U     | unsigned int
| 12L     | long int
| 12LL    | long long int

#### Floating-point Literal Constants

| literal | info
| ---     | ---
| 12.1    | double
| 12.1F   | float
| 12.1L   | long double

#### Character Literal Constants (escape code)

| literal | info
| ---     | ---
| \n      | newline
| \r      | return
| \t      | tab
| \b      | backspace
| \'      | single quote
| \"      | double quote
| \\      | backslash

### Declared Constants

> `const keyword`

### Constant Expressions

> `constexpr keyword`

### Emumerated Constants

> `enum keyword`

```cpp
enum Color {
    red, green, blue
};
Color screen_color {green}
// Color screen_color {};  // defaults to red
```

### Defined Constants

> `#define keyword`

## i. Control Flow



<hr>

## n. ...OOP

### ...METHODS

> methods are functions that work with objects

- vector.at(element) == arr[i]
  - object.method(index)
- vector.push_back(element)
- vector.size()


## m. SPECIAL FEATURES

### [Preprocessor Directives](https://cplusplus.com/doc/tutorial/preprocessor/)

| directive | info
| ---       | ---
| #include

### Libraries - Header files

#### [Cpp Standard Library header files](https://en.cppreference.com/w/cpp/header)

- {1} `<iostream>` 
- {2} `<iomanip>` 
  - cout << fixed << setprecision(2); // prints 2 decimals
- {4} `<vector>`  <!--Standard Template Library-->
- [`<cctype>`](https://cplusplus.com/reference/cctype/) aka `ctype.h`
  - isalpha(), isupper(), ... <!--True if...-->
- `<climits>`
- `<cfloat>`
- [`<cstring>`](https://cplusplus.com/reference/cstring/)
  - strcpy
- {8} `<cmath>` 
  - sqrt, pow; sin, cos; ceil, floor, round
- {8} `<cstdlib>`
  - rand, srand
- {8} `<ctime>`
  - time()


<details>

```cpp
───────┬────────────────────────────────────────────────────────────────────────────────────────
       │ File: /usr/include/c++/11/iostream
───────┼────────────────────────────────────────────────────────────────────────────────────────
   1   │ // Standard iostream objects -*- C++ -*-
   2   │
   3   │ // Copyright (C) 1997-2021 Free Software Foundation, Inc.
   4   │ //
   5   │ // This file is part of the GNU ISO C++ Library.  This library is free
   6   │ // software; you can redistribute it and/or modify it under the
   7   │ // terms of the GNU General Public License as published by the
   8   │ // Free Software Foundation; either version 3, or (at your option)
   9   │ // any later version.
  10   │
  11   │ // This library is distributed in the hope that it will be useful,
  12   │ // but WITHOUT ANY WARRANTY; without even the implied warranty of
  13   │ // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  14   │ // GNU General Public License for more details.
  15   │
  16   │ // Under Section 7 of GPL version 3, you are granted additional
  17   │ // permissions described in the GCC Runtime Library Exception, version
  18   │ // 3.1, as published by the Free Software Foundation.
  19   │
  20   │ // You should have received a copy of the GNU General Public License and
  21   │ // a copy of the GCC Runtime Library Exception along with this program;
  22   │ // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
  23   │ // <http://www.gnu.org/licenses/>.
  24   │
  25   │ /** @file include/iostream
  26   │  *  This is a Standard C++ Library header.
  27   │  */
  28   │
  29   │ //
  30   │ // ISO C++ 14882: 27.3  Standard iostream objects
  31   │ //
  32   │
  33   │ #ifndef _GLIBCXX_IOSTREAM
  34   │ #define _GLIBCXX_IOSTREAM 1
  35   │
  36   │ #pragma GCC system_header
  37   │
  38   │ #include <bits/c++config.h>
  39   │ #include <ostream>
  40   │ #include <istream>
  41   │
  42   │ namespace std _GLIBCXX_VISIBILITY(default)
  43   │ {
  44   │ _GLIBCXX_BEGIN_NAMESPACE_VERSION
  45   │
  46   │   /**
  47   │    *  @name Standard Stream Objects
  48   │    *
  49   │    *  The &lt;iostream&gt; header declares the eight <em>standard stream
  50   │    *  objects</em>.  For other declarations, see
  51   │    *  http://gcc.gnu.org/onlinedocs/libstdc++/manual/io.html
  52   │    *  and the @link iosfwd I/O forward declarations @endlink
  53   │    *
  54   │    *  They are required by default to cooperate with the global C
  55   │    *  library's @c FILE streams, and to be available during program
  56   │    *  startup and termination. For more information, see the section of the
  57   │    *  manual linked to above.
  58   │   */
  59   │   ///@{
  60   │   extern istream cin;       /// Linked to standard input
  61   │   extern ostream cout;      /// Linked to standard output
  62   │   extern ostream cerr;      /// Linked to standard error (unbuffered)
  63   │   extern ostream clog;      /// Linked to standard error (buffered)
  64   │
  65   │ #ifdef _GLIBCXX_USE_WCHAR_T
  66   │   extern wistream wcin;     /// Linked to standard input
  67   │   extern wostream wcout;    /// Linked to standard output
  68   │   extern wostream wcerr;    /// Linked to standard error (unbuffered)
  69   │   extern wostream wclog;    /// Linked to standard error (buffered)
  70   │ #endif
  71   │   ///@}
  72   │
  73   │   // For construction of filebuffers for cout, cin, cerr, clog et. al.
  74   │   static ios_base::Init __ioinit;
  75   │
  76   │ _GLIBCXX_END_NAMESPACE_VERSION
  77   │ } // namespace
  78   │
  79   │ #endif /* _GLIBCXX_IOSTREAM */
```

</details>

#### 

<hr>

## z. APPENDIX

### Boolean Algebra

| expression a | not a
| ---          | ---
| true         | false
| false        | true

| expression a | expression b | a and b
| ---          | ---          | ---
| true         | true         | true
| true         | false        | false
| false        | true         | false
| false        | false        | false

| expression a | expression b | a or b
| ---          | ---          | ---
| true         | true         | true
| true         | false        | true
| false        | true         | true
| false        | false        | false

### input validation

```cpp
int number {};
cout << "Enter an integer between 0 and 100: ";
cin >> number;
// while (number <= 0 || number >= 100){
//     cout << "Enter a valid integer: ";
//     cin >> number;
// }
    // The program may go into an infinite loop when you enter 'sup' because the cin stream extraction operator (>>) fails to convert the input to an integer, and sets the fail bit on the stream. Once the fail bit is set, all subsequent attempts to extract data from the stream will fail until the fail bit is cleared. However, the program enters an infinite loop because it does not clear the fail bit before the loop continues.
    // To fix this issue, you can add a call to cin.clear() to clear the fail bit before each input operation, and add a call to cin.ignore() to discard any extraneous characters in the input stream. Here's the modified code:
while (cin.fail() || number <= 0 || number >= 100){
    cin.clear();          // clear the fail bit
    cin.ignore(1000, '\n');// discard extraneous characters
    cout << "Enter a valid integer: ";
    cin >> number;
}
cout << "Thanks" << endl;
    // The fail bit is one of the error bits used by the input/output library in C++ to indicate an error in reading or writing data. It is set by the input/output library when a failure occurs in reading or writing data.
    // When you input a string "sup" into an integer variable number using cin, it tries to read the string and convert it to an integer. Since "sup" is not a valid integer, the fail bit is set by cin, indicating that the input operation has failed.
    // When the fail bit is set, the stream is considered to be in a fail state. In this state, further input operations on the stream will not succeed until the fail bit is cleared.
    // In the case of your code, when cin sets the fail bit, the input operation in the while loop does not execute, causing an infinite loop. To fix this, you can clear the fail bit using cin.clear() and discard the invalid input using cin.ignore(). This way, the input operation in the while loop can execute again, and the user can input a valid integer.
```


### ...member functions 

Technically, `.clear()`, `.fail()`, `.size()`, and other similar constructs in C++ are called member functions.

A member function is a function that belongs to a class or an object and is used to manipulate or access the object's data. It is defined inside a class definition and can be called on an instance of the class or object.

In the case of C++ input/output streams, these member functions are part of the `std::istream` and `std::ostream` classes, which provide functionality for reading input and writing output, respectively.

So, `.clear()`, `.fail()`, `.size()`, etc. are member functions of these classes and are used to manipulate or access the stream's internal data or state.

---

```cpp
// cin >> char_array;
cin.getline(char_array,50);
```