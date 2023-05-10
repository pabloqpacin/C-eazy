# Cpp Course Contents

<details>
<summary>Table of Contents</summary>

- [Cpp Course Contents](#cpp-course-contents)
  - [1. Getting Started](#1-getting-started)
  - [2. Structure of a C++ Program](#2-structure-of-a-c-program)
  - [3. Variables and Constants](#3-variables-and-constants)
  - [4. Arrays and Vectors](#4-arrays-and-vectors)
  - [5. Statements and Operators](#5-statements-and-operators)
  - [6. Controlling Program Flow](#6-controlling-program-flow)
  - [7. Characters and Strings](#7-characters-and-strings)
  - [8. Functions](#8-functions)
  - [9. Pointers and References](#9-pointers-and-references)
  - [10. OOP - Classes and Objects](#10-oop---classes-and-objects)
  - [11. Operator Overloading](#11-operator-overloading)
  - [12. Inheritance](#12-inheritance)
  - [13. Polymorphism](#13-polymorphism)
  - [14. Smart Pointers](#14-smart-pointers)
  - [15. Exception Handling](#15-exception-handling)
  - [16. I/O and Streams](#16-io-and-streams)
  - [17. The Standard Template Library (STL)](#17-the-standard-template-library-stl)
  - [18. Lambda Expressions](#18-lambda-expressions)

</details>


## 1. Getting Started

- Writing our first program
  - [ ] compilation: 0 errors, 0 warnings, cpp version..., `.o` files
```cpp
#include <iostream>

int main(){
    int favoriteNumber;
    std::cout << 'Enter your favorite number between 1 and 100: ';
    std::cin >> favoriteNumber;
    std::cout << "Amazing! That's my favorite number too!" << std::endl;
    return 0;
}
```
- Building our first program
  - @VSCode: [Using C++ and WSL in VS Code](https://code.visualstudio.com/docs/cpp/config-wsl) (zCustom)
    - @GNU: [GCC Warning options](https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html)
  - **build**: compile + link external libraries/files + create executable
  - **clean build**: remove existing `.o` files
  - [ ] nvim... ([1](https://www.reddit.com/r/neovim/comments/118x06o/help_setting_up_cpptools_for_nvimdap_to_debug_c/), [nvim-dap](https://github.com/mfussenegger/nvim-dap)) (zCustom)
- Compiler Errors
  - syntax errors (`std::cout << "Errors << std::endl`)
  - semantic errors (`aInt + bString;`)
- Compiler Warnings
  - potential problems, although machine code can be generated // **no warnings policty**
  - `warning: VAR is used uninitialized`
  - `warning: VAR set but not used`
  - `warning: unused VAR`
- Linker Errors
  - can't find all object files (libraries, etc.) to create executable
  - `undefined reference to ...`
- Runtime Errors
  - while executing; typical: divideByZero, fileNotFound, outOfMemory; may cause CRASH
  - **exception handling** can help deal with these
- Logic Errors
  - bugs that cause program to run incorrectly
- SECTION CHALLENGE
```cpp
/*
Create a Cpp program that asks the user for their favorite number between 1 and 100,
then reads this number from the console.
Suppose the user enters 24.
Then display the following to the console:
'Amazing!! That's my favorite number too!
No really! 24 is my favorite number!'
*/

#include <iostream>

int main(){
    int favoriteNumber;
    std::cout << "Enter your favorite number between 1 and 100: ";
    std::cin >> favoriteNumber;
    std::cout << "Amazing!! That's my favorite number too!" << std::endl;
    std::cout << "No really!! " << favoriteNumber << " is my favorite number!" << std::endl;
    return 0;
}

// still missing the enforcing of 1-100...
```
- Quiz
  1. *Compilers* are used to translate programming language source code instructions into the appropriate machine language instructions.
  2. An Integrated Development Environment (IDE) typically includes: *a debugger, a text-editor and a compiler*
  3. A *program* is a set of instructions that a computer executes to solve a problem.
  4. Syntax errors are detected by the *compiler* <!--NO debugger linker editor-->
  5. A set of precise steps for solving a problem is known as a(n): *algorithm*
  6. The statements written by programmers are called *source code* <!--NO object code-->
  7. The rules that must be followed when writing programs in specific programming languages are called *syntax*
  8. Mistakes by the programmer that cause a program to produce incorrect results are called *logic errors* <!--NO syntax linker compiler-->
  9. If you declare a variable and use it before initializing it the compiler will generate a(n) *warning* <!--NO error segmentationFault runtimeError-->
  10. The error generated when all the parts that make up a program cannot be put together because one or more are missing is called a *linker error*


## 2. Structure of a C++ Program
## 3. Variables and Constants
## 4. Arrays and Vectors
## 5. Statements and Operators
## 6. Controlling Program Flow
## 7. Characters and Strings
## 8. Functions
## 9. Pointers and References
## 10. OOP - Classes and Objects
## 11. Operator Overloading
## 12. Inheritance
## 13. Polymorphism
## 14. Smart Pointers
## 15. Exception Handling
## 16. I/O and Streams
## 17. The Standard Template Library (STL)
## 18. Lambda Expressions