# Cpp Course Contents

<details>
<summary>Table of Contents</summary>

- [Cpp Course Contents](#cpp-course-contents)
  - [1. Getting Started](#1-getting-started)
  - [2. Structure of a C++ Program](#2-structure-of-a-c-program)
  - [3. Variables and Constants](#3-variables-and-constants)
  - [3. Variables and Constants](#3-variables-and-constants-1)
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
- SECTION QUIZ
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

- Basic Syntax Components (keywords, identifiers, operators and punctuation)
  - [keywords](https://en.cppreference.com/w/cpp/keyword): ~90, reserved, can't modify their meaning (eg. int, return)
  - identifiers: #include, main, std, cout, cin, ...
  - operators: + - / * << >> ::
  - punctuation: ; {} "" '' ()
- `#include` Preprocessor Directive
  - **directives**: #include,  #if #elif #else #endif, #ifdef #ifndef #define #undef, #line #error #pragma
  - the C++ preprocessor is a program that processes the source code before the compiler sees it
    - it first strips all the comments from the source file (replaces each with a single space)
    - then looks for directives (#foo) and executes them
  - as for `#include`, it replaces the line with the referenced file and recursively processes it as well
  - by the time the compiler sees the source code, all comments are gone and all preprocessor directives have been processed and removed
  - the C++ preprocessor does not understand C++
    - it simply follows the preprocessor directives and gets the source code ready for the compiler
    - the compiler is the program that does understand C++
  - NOTE: conditional compilation: compile only portion if on Windows, else if on Linux, etc.
- Comments
  - programmer readable explanations in the source code, ain't compiled!
    - inline: `// foo`
    - multiline: `/* foo */` 
  - "self-documenting code"
    - avoid obvious and explain the not-so-obvious
    - keep it consistant
- The `main()` function
  - 1 in every Cpp program; starting point of program execution; 'return 0' indicates successful program execution
  - `int main(int argc, char *argv[])` << OperatingSystem(terminal) provides 'argument count' and 'argument vector'
- Namespaces (`std`, ...)
  - complex programs: our code, libraries' code, 3rdParty code...
  - avoid 'naming conflict' with namespace scope (containerize names/references)
  - scope resolution operator:: => assign
  - alternative: 'using namespace directive'
    - NOTE: namespace brings all given identifiers, which may cause conflict
    - for large programs, consider the qualified variant
```cpp
// explicit namespaces (via scope resolution operator)
std::cout << "foo";
std::cin >> foo;
std::cout << "foo" << std::endl;

// using namespace directive
using namespace std;
cout << "foo";
cin >> foo;
cout << "foo" << endl;

// qualified using namespace variant
using std::cout;
using std::cin;
using std::endl;
cout << "foo" << endl;
```

- Basic IO using `cin` and `cout`
  - cout: standard output stream, console/screen
    - can be chained, does not aumatically add line breaks
    - `cout << "data 1 is " << data1 << endl;`
      - `endl` flush stream to get output, since stream is buffered
    - `cout << "data 1 is " << data1 << "\n";`
  - cin: standard input stream, keyboard
    - *keyboard -> buffer -> cin/compiler*
    - can be chained: `cin >> data1 >> data2:`
    - can fail if entered data can't be interpreted (wrong value, datatype, ...)
    - uses whitespace: will assume spaces, tabs & newlines as ENTER
  - cerr: error output
  - clog: diagnostic output
  - <<: insertion operator, output streams
  - \>>: extraction operator, input streams
```cpp
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::flush;

int main(){
    cout << "Hello World!" << endl;
    cout << "Hello ";
    cout << "World!" << endl;
    cout << "Hello " << "World!" << endl;
    cout << "Hello " << "World! \n" << flush;

    int num1;
    int num2;
    double num3;

    // WHITESPACE: If input "9 8 7 6.5" in first prompt, there won't more prompts!!
    cout << "Enter a first integer: ";
    cin >> num1;
    cout << "Enter a second integer: ";
    cin >> num2;
    cout << "You entered " << num1 << " and " << num2 << endl;

    cout << "Enter two integers separated with a space: ";
    cin >> num1 >> num2;
    cout << "You entered " << num1 << " and " << num2 << endl;

    cout << "Enter a double: ";
    cin >> num3;
    cout << "You entered " << num3 << endl;

    return 0;
}
```
- EXERCISES
  1. Using `cout` and the insertion operator to say hi
  2. Using `cout` and the insertion operator
  3. Using `cin` and the extractor operator
- SECTION QUIZ
  1. In a C++ program, two forward slash characters “//” are used to indicate: *The beginning of a comment.*
  2. A statement that begins with the # symbol is called a *preprocessor directive*.
  3. Naming conventions: `camelCase` `PascalCase` `snake_case` `UPPER_CASE`
  4. What is used to terminate a statement in C++? *A semi-colon `;`*
  5. What happens if you use a C++ keyword as an identifier name? *The program will not compile* <!--NO logicError programCrash linkerError-->
  6. Every complete C++ program must have a(n) *function named `main`* <!--NO errorHandler coutStatement includeIostreamStatement-->
  7. What will the following code display? *—*
  8. The C++ main function must return *`0`* when the program terminates successfully. <!--NO success noValue -1-->
  9. Which of the following are valid operators in C++? *All + * >> <<*
  10. What will the following code display? *—*


## 3. Variables and Constants

- What is a variable?
- Declaring and Initializing Variables
- EXERCISE
- Global Variables
- C++ Built-in Primitive Types
- What is the Size of a Variable (`sizeof`)
- What is a Constant?
- Declaring and Using Constants
- SECTION CHALLENGE
- SECTION QUIZ


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