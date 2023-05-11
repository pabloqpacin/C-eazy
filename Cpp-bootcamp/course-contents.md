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
  - [ ] compilation: 0 errors 0 warnings, cpp version..., `.o` files...
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
  - abstraction for a memory location, where data is stored; they have type & value
  - must be declared before they are used, and their value might change
- Declaring and Initializing Variables
  - can contain letters, numbers and underscores - must begin with letter or underscore (NO number)
  - cannot use Cpp reserved keywords, cannot redeclare a name in the same scope (remember Cpp is case-sensitive)
  - consistent naming conventions, meaningful names
  - declare and initialize them (LOCAL VARIABLES) close to their usecase, NOT atop
```cpp
    int age = 69;               // C-like initialization
    double rate (4.20);         // Constructor initialization
    string name {"supdawg"};    // C++11 list initialization syntax
```
```cpp
#include <iostream>
using namespace std;

int main(){
    cout << "Enter the width of the room: ";
    double room_width {0};
    cin >> room_width;
    cout << "Enter the length of the room: ";
    double room_length {0};
    cin >> room_length;
    cout << "The area of the room is " << room_width * room_length << endl;
    return 0;
}
```
- EXERCISE
- Global Variables
  - declared outside of functions, to be used in any part of the code
  - scope, visibility...
  - compiler first looks for LOCAL variables, then GLOBAL variables
```cpp
#include <iostream>
using namespace std;

int age {24};

int global_variable(){
    return age;
}

int main(){
    int age {28};
    cout << age << endl;                // Prints 28
    cout << global_variable() << endl;  // Prints 24
    return 0;
}
```
- C++ Built-in Primitive Types
  - types: character, integer (signed/unsigned),  floating-point types, boolean type
  - size and precision: machine/compiler-dependent (`#include <climits>`); the more bits the more unique values can be represented and more storage is required; mind *overflows*
```cpp
#include <iostream>
using namespace std;

int main(){
    char middle_initial {'Q'};
    cout << "My middle initial is " << middle_initial << endl;

    unsigned short int exam_score {55};
    cout << "My exam score was " << exam_score << endl;

    int countries_represented {65};
    cout << "There were " << countries_represented
         << " countries represented in my meeting" << endl;

    long people_in_spain {47'615'034};
    cout << "There are about " << people_in_spain << " people in Spain" << endl;

    float car_payment {420.69};
    cout << "My car payment is " << car_payment << endl;

    double pi {3.14159};
    cout << "Pi is " << pi << endl;

    long double large_amount {2.7e120}; // 2.7x10**120
    cout << large_amount << " is a very big number" << endl;

    bool game_over {false};
    cout << "The value of gameOver is " << game_over << endl;

    return 0;
}
```
- What is the Size of a Variable (`sizeof`)
  - for datatypes/variables
  - NOTE: `<climits>` & `<cfloat>`
- What is a Constant?
  - like Cpp variables: have names, occupy storage, are usually 'typed'
  - however: their value cannot change once declared
  - types:
    - literal constants: -
    - declared constants: `const keyword`
    - constant expressions: `constexpr keyword`
    - enumerated constants: `enum keyword`
    - defined constants: `#define foo "bar"` (AVOID)
- Declaring and Using Constants
- SECTION CHALLENGE
- SECTION QUIZ
  1. Data values that do not change while a program executes are *literals*.
  2. All variables must have a *definition* before they are used in a program.
  3. Storage locations in memory are represented by *variables*.
  4. String literals are always enclosed in *double quotes ""*.
  5. Character literals are always enclosed in *single quotes ''*.
  6. A variable that can hold only true or false values is of type *bool*.
  7. The following expression determines how many bytes of storage are required to store a double on your computer: *`sizeof(double)`*
  8. What is the output from the following code: `int x; cout << x << endl;` *some garbage value*
  9. Which variable definition is not legal in C++? *`int x = 100`*
  10. Which line in the following code will generate a compiler error? *—*


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