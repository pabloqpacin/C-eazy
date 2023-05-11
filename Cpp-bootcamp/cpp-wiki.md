# Cpp Wiki

<details>
<summary>Table of Contents</summary>

- [Cpp Wiki](#cpp-wiki)
  - [1. Syntax](#1-syntax)
    - [Keywords](#keywords)
    - [Identifiers](#identifiers)
    - [Operators](#operators)
    - [Punctuation](#punctuation)
  - [2. Datatypes](#2-datatypes)
    - [Primitive Datatypes](#primitive-datatypes)
      - [Character](#character)
      - [Integer](#integer)
      - [Floating-point](#floating-point)
      - [Boolean](#boolean)
  - [3. Constants](#3-constants)
    - [Literal Constants](#literal-constants)
      - [Integer Literal Constants](#integer-literal-constants)
      - [Floating-point Literal Constants](#floating-point-literal-constants)
      - [Character Literal Constants (escape code)](#character-literal-constants-escape-code)
    - [Declared Constants](#declared-constants)
    - [Constant Expressions](#constant-expressions)
    - [Emumerated Constants](#emumerated-constants)
    - [Defined Constants](#defined-constants)
  - [n. SPECIAL FEATURES](#n-special-features)
    - [Preprocessor Directives](#preprocessor-directives)
    - [Libraries - Header files](#libraries---header-files)

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

| operator | info
| ---      | ---
| +
| -
| *
| /
| <<       | stream insertion <!--chevron-->
| >>       | stream extraction
| ::       | scope resolution (!)
|          |
| sizeof() | queries object bit size

### Punctuation

| punctuation | info
| ---         | ---
| ;           | terminate statement
| { }   
| " "         | delimit string
| ' '         | delimit chars
| ( )

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

### Defined Constants

> `#define keyword`


## n. SPECIAL FEATURES

### [Preprocessor Directives](https://cplusplus.com/doc/tutorial/preprocessor/)

| directive | info
| ---       | ---
| #include

### Libraries - Header files

- `iostream`

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

- `climits`
- `cfloat`