# Cpp Bootcamp

> @FrankMitropoulos: [Beginning C++ Programming - From Beginner to Beyond](https://www.udemy.com/course/beginning-c-plus-plus-programming/)

<details>
<summary>Table of Contents</summary>

- [Cpp Bootcamp](#cpp-bootcamp)
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

```markdown
# UPDATE
- use `&variable` to print the memory address of any element
```
<details>

```cpp
// ARRAYS
#include <iostream>
using namespace std;

int main(){
    int my_scores [] {1,2,3,4,5};
    for (auto n: my_scores)
        cout << n << ": " << &n << endl;
    cout << endl;
    int arr_size = sizeof(my_scores) / sizeof(my_scores[0]);
    for (int i{0}; i<arr_size; ++i)
        cout << my_scores[i] << ": " << &my_scores[i] << endl;
    return 0;
}
```
```cpp
// VECTORS
#include <vector>
#include <iostream>
using namespace std;

int main(){
    vector<char> my_scores {'a','b','c','d','e'};
    for (auto c: my_scores) 
        cout << c << ": " << static_cast<void*>(&c) << endl;
    // auto => deduces the type as a copy of the elements (same address)
    // auto& => deduces the type as a reference to the elements (different addresses)
    cout << endl;
    for (size_t i{0}; i<my_scores.size(); ++i)
        cout << my_scores[i] << ": " << static_cast<void*>(&my_scores[i]) << endl;
    return 0;
}
```
</details>

- What is an Array?
  - compound **data type/structure**: collection of elements of the same type
  - FIXED size, stored contiguosly in memory
  - each element can be accessed directly by position/index; first is 0 & last is -1
  - 'no checking if you are out of bounds'
  - very efficient; iteration (looping) is often used to process
- Declaring and Initializing Arrays
```cpp
#include <iostream>
using namespace std;

int main(){
    // int i {0};
    int test_scores [3] {1,2,3};
    // for (i=0; i<3; i++){
    //     cout << test_scores[i] << endl;
    // }
    const int days_in_year {365};
    double high_temperatures [days_in_year] {0};
    // for (i=0; i<days_in_year; i++){
    //     cout << high_temperatures[i] + i << endl;
    // }
    int another_array [] {1,2,3};   // Compiler determines size based on elements
    // for (i=0; i<another_array[-1]; i++){
    //     cout << another_array[i] << endl;
    // }
    // int test_score_1 {0};    // CAN'T BE DONE - NEED ARRAY/VECTOR
    // int test_score_2 {0};
    // int test_score_666 {0};
    // for (i=0;i<2;i++){
    //     int test_score_"i";
    // }
    return 0;
}
```
- Accessing and Modifying Array Elements
  - NOTE: consider `int array [] {1,2,3}`: as `array[0]` is in the memory address 1000, `array[1]` will be found with 1000+4 (int byte size), etc
```cpp
#include <iostream>
using namespace std;

int main(){

    int int_array [5] {};   // '[]' here would cause *stack smashing*
    cout << "- " << int_array << " // Enter 3 integers separated with spaces: ";
    cin >> int_array[0];
    cin >> int_array[1];
    cin >> int_array[2];
    cout << "First integer is: " << int_array[0] << endl;
    cout << "Second integer is: " << int_array[1] << endl;
    cout << "Third integer is: " << int_array[2] << endl;

    char vowels [] {'a','e','i','o','u'};
    cout << "\n- " << static_cast<void*>(vowels) << endl;
    // cout << vowels;  // Since chars, prints string until \O (null char)
    cout << "First vowel is: " << vowels[0] << endl;
    cout << "Last vowel is: " << vowels[4] << endl;
    // cin >> vowels[5]; // *STACK SMASHING*

    double high_temps [] {12.1,21.2};
    cout << "\n- " << high_temps << endl;
    cout << "First high temperature is: " << high_temps[0] << endl;
    high_temps[0] = 6.9;
    cout << "First high temperature is now: " << high_temps[0] << endl;
    
    return 0;
}
```
- EXERCISE
- Multidimensional Arrays
  - Squre brackets MUST NOT be empty now
```cpp
#include <iostream>
using namespace std;

int main(){
    // int movie_rating [3][4]{};
    const int rows {3}; // 3 reviewers
    const int cols {4}; // 4 movies
    // int movie_rating [rows][cols] {};
    // cin >> movie_rating [1][2];
    // cout << movie_rating [1][2];
    int movie_rating [rows][cols] {
        {0,4,3,5},
        {2,3,3,5},
        {1,4,4,5}
    };
    cout << movie_rating [1][2];
    return 0;
}
```
- What is a Vector?
  - container in the Standard Template Library
  - dynamic array (OBJECT) that can grow and shrink at runtime
  - similar semantics and syntax as arrays (same type/elements), very efficient, provides 'bounds checking'
  - allows for many functions like sort, reverse, find and more
- Declaring and Initializing Vectors (Dynamic Arrays)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Declare 5 elements initialized as 0 by default
    vector <char> vowels (5);
    // Implicit size declaration, explicit initialization
    vector <int> test_scores {100,98,89,85,92};
    // Size declaration, initialization for each and every element!
    vector <double> high_temperatures (365, 80.0);
    return 0;
}
```
- Accessing and Modifying Vector Elements
  - methods will be bounds-checked!! (ie. `.at()`...)
  - if out of bounds: **exception** and error message generated (runtime interrupted)
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> test_scores {100,95,99,87,88};
    cout << "First score at index 0: " << test_scores[0] << endl;
    cout << "Last score at index 4: " << test_scores.at(4) << endl;

    cin >> test_scores.at(4);
    cout << "New last score at index 4: " << test_scores.at(4) << endl;
    test_scores.at(4) = 69;
    cout << "New-new last score at index 4: " << test_scores.at(4) << endl;
    
    // cin >> test_scores[5];
    // cout << "New score at index 5: " << test_scores[5] << endl;
    test_scores.push_back(44);  // Only 1 element at a time
    cout << "Index 5 after push_back: " << test_scores.at(5) << endl;
    
    return 0;
}
```
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    // vector <char> vowels;    // Empty vector
    // vector <char> vowels (5);   // 5 elements all initialized to zero
    // vector <char> vowels (5, 'y');   // 5 elements all initialized to 'y'
    vector <char> vowels {'a','e','i','o','u'};
    cout << vowels[0] << endl;
    cout << vowels.at(4) << endl;
    // cout << sizeof vowels << endl;
    cout << "There are " << vowels.size() << " vowels in the vector" << endl;

    // cout << "Redo the first vowel... ";
    // cin >> vowels.at(0);
    // cout << vowels[0] << endl;

    cout << "Enter a fake vowel: " << endl;
    char fake_vowel {0};
    cin >> fake_vowel;
    vowels.push_back(fake_vowel);
    cout << "Now there are " << vowels.size() << " vowels in the vector" << endl;
    return 0;
}
```
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <vector<int>> movie_ratings {
        {1,2,3,4},
        {1,2,4,4},
        {1,3,4,5}
    };
    cout << "Movie ratings by reviewer #1:" << endl;
    cout << movie_ratings[0][0] << endl;
    cout << movie_ratings[0][1] << endl;
    cout << movie_ratings.at(0).at(2) << endl;
    cout << movie_ratings.at(0).at(3) << endl;
    return 0;
}
```
- EXERCISE
- SECTION CHALLENGE
- SECTION QUIZ
  1.  Arrays are always indexed starting at subscript *0*.
  2.  How many integers can the array named numbers contain? `int numbers[10];` *10*
  3.  Which of the following is a legal array definition in C++? *`float numbers[10]`*
  4.  C++ treats an array name as: *the location in memory of first array element*
  5.  All array elements must be: *of the same type*
  6.  Given the following array declaration, how would you display `100.7` from the array? `double temperatures[] = {98.6, 95.2, 88.7, 100.7, 89.0};` *`cout << temperatures[3] << endl;`*
  7.  Given the following array declaration, what would the following code display? `double temperatures[] {98.6, 95.2, 88.7, 100.7, 89.0}; cout << temperatures[5] << endl;` *garbage data* <!--NOT it won't compile, out-of-range error-->
  8.  How would you define a vector named temperatures that contains doubles? *`vector <double> temperatures;`*
  9. How would you determine the number of elements contained in a vector named temperatures? *`temperatures.size()`* <!--NOT lenght() num_elements()-->
  10. What is one way that vectors and arrays are different? *vectors can vary their capacity as the program runs, but arrays are fixed in size*


## 5. Statements and Operators

- Expressions and Statements
  - EXPRESSION
    - building block of a program
    - "sequence of operators and operands that specifies a computation"
    - computes a value from a number of operands
  - STATEMENT
    - complete line of code that performs some action
    - usually terminated with a semi-colon
    - usually contains expressions
    - Cpp has many types: expression, null, compound, selection, iteration, declaration, jump, try-blocks...
```cpp
// EXPRESSIONS
34              // literal
favorite_number // variable
1.5 + 2.8       // addition
2 * 5           // multiplication
a > b           // relational - evaluates to a BOOl
a = b           // assignment

// STATEMENTS
int x;                                      // declaration
favorite_number = 12;                       // assignment
1.5 + 2.8;                                  // expression
x = 2 * 5;                                  // assignment
if (a > b) cout << "a is greater than be";  // if statement
;                                           // null statement
```
- Using Operators
  - rich set: unary, binary, ternary
  - common groups: assignment, arithmetic, increment/decrement, relational, logical, member access, other
- The Assignment Operator (`=`)
  - for `lhs = rhs;`
    - `rhs` is an expression that is evaluated to a value that is stored to `lhs`
    - `lhs` must be assignable and the value/type of `rhs` must be compatible (STATICALLY TYPED)
    - assignment expression is evaluated to what was just assigned; more than one variable can be assigned in a single statement
```cpp
// Assignment Operator (=)
int num1 {10};
int num2 {20};
// num1 = 100;
// num1 = num2;
num1 = num2 = 1000;
cout << "num1 is " << num1 << endl;
cout << "num2 is " << num2 << endl;
```
- Arithmetic Operators: `+ - * / %`
```cpp
// Arithmetic Operators (+ - * / %)
int num1 {200};
int num2 {100};
int result {0};
result = num1 + num2;
result = num1 - num2;
result = num1 * num2;
result = num1 / num2;
result = num1 % num2;
cout << num1 << " % " << num2 << " = " << result << endl;

const double usd_per_eur {1.08};
cout << "\nWelcome to the EUR to USD converter" << endl;
cout << "Enter the value in EUR: ";
double euros {0.0};
double dollars {0.0};
cin >> euros;
dollars = euros * usd_per_eur;
cout << euros << " euros is equivalent to " << dollars << " dollars" << endl;
```
- EXERCISES
  - Using the Assignment Operator
  - Using the Arithmetic Operators
- Increment and Decrement Operators: `++ --`
  - can be used with integers, floating point types and pointers
  - prefix & suffix: `++num` & `num++`
  - don't overuse this operator! Never use it twice for the same variable in the same statement!
```cpp
int counter {10};
int result {0};
cout << "Counter: " << counter << endl; // 10
counter = counter + 1;
cout << "Counter: " << counter << endl; // 11
counter++;
cout << "Counter: " << counter << endl; // 12
++counter;
cout << "Counter: " << counter << endl; // 13

// Counter will be pre-incremented (BEFORE it's used)
counter = 10;
result = 0;
result = ++counter;
cout << "Counter: " << counter << endl; // 11
cout << "Result: " << result << endl;   // 11
result = ++counter;
cout << "Counter: " << counter << endl; // 12
cout << "Result: " << result << endl;   // 12

// Counter will be post-incremented (AFTER it's used)
counter = 10;
result = 0;
result = counter++;
cout << "Counter: " << counter << endl; // 11
cout << "Result: " << result << endl;   // 10
result = counter++;
cout << "Counter: " << counter << endl; // 12
cout << "Result: " << result << endl;   // 11
```
- Mixed Expressions and Conversions
  - INTRO
    - Cpp operations occur on same type operands; if different type, Cpp will convert one (importantly, this can affect calculation results)
    - Cpp will attempt to automatically convert types (coercion); if it can't a compiler error will occur
    - TYPES: lower & higher: can hold smaller/larger values; lower types can be converted into higher types
    - type coercion: conversion of one operand to another data type: promotion & demotion: convertion to higher/lower type: mathematical expressions | assignment to lower type
  - CASTING
    - explicit type casting - `static_cast<type>(var)`
```cpp
// Promotion (int to double)
2 * 5.2;
// Demotion (double to int)
int num {0};
num = 100.2;
cout << num << endl;
```
```cpp
#include <iostream>
using namespace std;

int main(){
    int total {0};
    int num1 {0}, num2 {0}, num3 {0};
    const int count {3};
    cout << "Enter 3 integers separated by spaces: ";
    cin >> num1 >> num2 >> num3;
    total = num1 + num2 + num3;
    double average {0.0};
    average = static_cast<double>(total) / count;
    // average = (double)total / count; // C-like casting
    cout << "The three numbers are: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Total is: " << total << endl;
    cout << "Average is: " << average << endl;
    return 0;
}
```
- Testing for Equality: `== !=`
  - compares the values of 2 expressions
  - evaluates to a Boolean (True or False, 1 or 0)
  - mind `boolalpha`!
```cpp
#include <iostream>
using std::cin, std::cout, std::endl;
using std::boolalpha, std::noboolalpha;

int main(){
    bool equal_result {false};
    bool not_equal_result {false};

    cout << boolalpha;  // defaults booleans to true/false
    int num1{}, num2{};
    cout << "Enter two integers separated by a space: ";
    // cin >> num1 >> num2;
    cout << 10 << " 9.99999" << endl;
    num1 = 10; num2 = 9.9999999999999999;
    equal_result = (num1 == num2);
    not_equal_result = (num1 != num2);
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;

    cout << noboolalpha;    // defaults booleans to 1/0
    char char1{}, char2{};
    cout << "\nEnter two characters separated by a space: ";
    cin >> char1 >> char2;
    equal_result = (char1 == char2);
    not_equal_result = (char1 != char2);
    cout << "Comparison result (equals): " << equal_result << endl;
    cout << "Comparison result (not equals): " << not_equal_result << endl;
    return 0;
}
```
- Relational Operators: `> >= < <= <=>`
  - also evaluate to a Boolean...
```cpp
int num{};
const int lower{10}, upper{20};
cout << boolalpha;

cout << "Enter an integer that is greater than " << lower << ": ";
cin >> num;
cout << num << " > " << lower << " is " << (num > lower) << endl;

cout << "Enter an integer that is less than or equal to " << upper << ": ";
cin >> num;
cout << num << " <= " << upper << " is " << (num <= lower) << endl;
```
- Logical Operators: `! && ||`
  - precedence: `not` higher than `and` higher than `or`
  - short-circuit evaluation: "when evaluating a logical expression C++ stops as soon as the result is known"
    - `expr1 && expr2 && expr3` will stop as soon as one is false! 
    - `expr1 || expr2 || expr3` will stop as soon as one is true!
```cpp
int num {};
const int lower {10};
const int upper {20};
cout << "Enter an integer - the bounds are " << lower << " and " << upper << ": ";
cin >> num;
bool on_bounds {false};
on_bounds = (num == lower || num == upper);
cout << num << " is equal to " << lower << " or " << upper << ": " << on_bounds << endl;
bool within_bounds {false};
within_bounds = (num > lower && num < upper);
cout << num << " is between " << lower << " and " << upper << ": " << within_bounds << endl;
bool outside_bounds {false};
outside_bounds = (num < lower || num > upper);
cout << num << " is less than " << lower << " or greater than " << upper << ": " << outside_bounds << endl;

int wint_speed {};
double temperature {};
bool wear_coat {false};
const int wind_speed_for_coat {25};     // wind over this value requires a coat
const double temperature_for_coat {45}; // temperature below this value requires a coat
cout << "Enter the current temperature in (F): ";
cin >> temperature;
cout << "Enter windspeed in (mhp): ";
cin >> wint_speed;
wear_coat = (temperature < temperature_for_coat || wint_speed > wind_speed_for_coat);
cout << "Do you need to wear a coat using OR? " << wear_coat << endl;
wear_coat = (temperature < temperature_for_coat && wint_speed > wind_speed_for_coat);
cout << "Do you need to wear a coat using AND? " << wear_coat << endl;
```
- Compound Assignment Operators: `+= -= *= /= %= >>= <<= &= ^= |=`
  - `lhs = lhs op (rhs)`
- Operator Precedence
  - use precedence rules when adjacent operators are different
  - use **associativity** rules when adjacent operators have the same precedence
  - use parenthesis to absolutely remove any doubt
- EXERCISE: Logical Operators and Operator Precedence
- SECTION CHALLENGE
- SECTION QUIZ
  1. The *prefix increment* operator increments the value of its operand by one then uses the value
  2. The operator used to test two operands for equality is *==*
  3. The operator that represents logical AND is *&&*
  4. The operator that represents logic OR is *||*
  5. —
  6. `a < 10`  is called a(n) *relational expression*
  7. —
  8. What is displayed by the following code? `int amount = 100; amount += amount * 2; cout << amount << endl;` *300*
  9. What is displayed by the following code? `int x= 5; int y= -2; int z = 2; cout << (x + y * z <= x + z * z - x) << endl;` // *1*
  10. What are the values of x and y after the following code executes? `double  a = 100; int b = 12; int x = b % 3; double  y = a / b; int z = a / b;` *x=0, y=8.33 and z=8*


## 6. Controlling Program Flow

- Controlling Program Flow...
  - building blocks: Sequence + Selection + Iteration
  - selection/decision-making: `if if-else switch ?:`
  - iteration: `for while do-while continue-break`
- if Statement
  - execute if true, skip if false
  - BLOCK STATEMENTS: variable declarations are visible only within the block (LOCAL SCOPE)
```cpp
double health {69.3};
bool player_healed {true};
if (health < 100 && player_healed)
    health = 100;

int num {0};
const int min {10};
const int max {100};
cout << "Enter a number between " << min << " and " << max << ": ";
cin >> num;
if (num >= min){
    cout << "\n============= Statement 1 =============" << endl;
    cout << num << " is greater than or equal to " << min << endl;
    int diff {num - min};
    cout << num << " is " << diff << " greater than " << min << endl;
}
if (num <= max){
    cout << "\n============= Statement 2 =============" << endl;
    cout << num << " is less than or equal to " << max << endl;
    int diff {max - num};
    cout << num << " is " << diff << " less than " << max << endl;
}
if (num >= min && num <= max){
    cout << "\n============= Statement 3 =============" << endl;
    cout << num << " is in range" << endl;
    cout << "This means that statements 1 and 2 must also display!" << endl;
}
if (num == min || num == max){
    cout << "\n============= Statement 4 =============" << endl;
    cout << num << " is right on a boundary" << endl;
    cout << "This means all 4 statements display" << endl;
}
```
- EXERCISE: if Statement - Can you Drive?
- if else Statement
  - if true execute statement1, if false execute statement2
```cpp
double health {69.3};
bool player_healed {false};
// player_healed = true;
if (health < 100 && player_healed) health = 100;
else ++health;
cout << health << endl;

// #include <cstdlib>
srand(static_cast<int>(time(NULL)));    // seed the random number generator with the current time
int score {rand() % 100 + 1};           // generate a random number between 1 and 100
if (score >= 90) cout << score << " : " "A" << endl;
else if (score >= 80) cout << score << " : " "B" << endl;
else if (score >= 70) cout << score << " : " "C" << endl;
else if (score >= 60) cout << score << " : " "D" << endl;
else cout << score << " : " "F" << endl;
```
```cpp
int num {};
const int target {10};
cout << "Enter a number and I'll compare it to " << target << ": ";
cin >> num;
if (num >= target){
    cout << "\n===================================" << endl;
    cout << num << " is greater than or equal to " << target << endl;
    int diff {num - target};
    cout << num << " is " << diff << " greater than " << target << endl;
} else {
    cout << "\n===================================" << endl;
    cout << num << " is less than " << target << endl;
    int diff {target - num};
    cout << num << " is " << diff << " less than " << target << endl;
}
```
- EXERCISE: if else Statement - Can you Drive?
- Nested if Statements
  - allows for tseting of multiple conditions
  - dangling else problem: `else` belongs to the closest `if`
```cpp
int score {0};
cout << "Enter your score on the exam (0-100): ";
cin >> score;
char letter_grade {};
if (score >= 0 && score <= 100){
    cout << "================================" << endl;
    if (score >= 90) letter_grade = 'A';
    else if (score >= 80) letter_grade = 'B';
    else if (score >= 70) letter_grade = 'C';
    else if (score >= 60) letter_grade = 'D';
    else letter_grade = 'F';
    cout << "Your grade is: " << letter_grade << endl;
    if (letter_grade == 'F') cout << "Sorry, you must repeat the class" << endl;
    else cout << "Congrats!" << endl;
} else {
    cout << "Sorry, " << score << " is not in range" << endl;
}
```
- EXERCISE: Nested if Statements - Can you Drive?
- switch-case Statement
  - the control expression must evaluate to an integer type
  - the case expressions must be constant expressions that evaluate to integer or integer literals
  - once a match occurs all following case section are executed UNTIL a `break` is reached and the switch is complete
  - `default` is optional but should be handled
  - commonly used with ENUM types
```cpp
char letter_grade {};
cout << "Enter the grade you expect on the exam: ";
cin >> letter_grade;

switch (letter_grade) {
    case 'a': case 'A': cout << "You need a 90 or above, study hard!" << endl; break;
    case 'b': case 'B': cout << "You need 80-89 for a B, go study!" << endl; break;
    case 'c': case 'C': cout << "You need 70-79 for an average grade!" << endl; break;
    case 'd': case 'D': cout << "Hmm, you should strive a better grade. All you need is 60-69" << endl; break;
    case 'f': case 'F': {
        char confirm {};
        cout << "Are you sure (y/n)? ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') cout << "OK, I guess you didn't study..." << endl;
        else if (confirm == 'n' || confirm == 'N') cout << "Good - go study!" << endl;
        else cout << "Illegal choice" << endl;
        break;
    }
    default: cout << "Sorry, not a valid grade" << endl;
}

// enum Direction {
//     left, right, up, down
// };
// Direction heading {};
// cout << heading << endl;    // 0 as for default ie. left
// switch (heading){
//     case left: cout << "Going left" << endl; break;
//     case right: cout << "Going right" << endl; break;
//     case up:     // continues up to break/default
//     case down:   // continues up to break/default
//     default: cout << "OK" << endl;
// }
```
- EXERCISE: Switch Statement - Day of the Week
- Conditional Operator: `(cond_expr) ? expr1 : expr2`
  - cond_expr evaluates to a boolean expression
  - if true the value of expr1 is returned, if false then expr2
  - ternary operator, very useful when used inline, very easy to abuse (AVOID NESTING)!
```cpp
int score{69};
cout << ((score > 90) ? "Excellent" : "Good") << endl;

int num{};
cout << "Enter an integer: ";
cin >> num;
if (num % 2 == 0) cout << num << " is even" << endl;
else cout << num << " is odd" << endl;
cout << num << " is " << ((num%2==0) ? "even" : "odd") << endl;

int num1{}, num2{};
cout << "Enter two integers separated by a space: ";
cin >> num1 >> num2;
if (num1 != num2){
    cout << "Largest: " << ((num1 > num2) ? num1 : num2) << endl;
    cout << "Smallest: " << ((num1 < num2) ? num1 : num2) << endl;
} else {
    cout << "The numbers are the same" << endl;
}
```
- Looping
  - iteration or repetition; allows the execution of a statement or block of statements repeatedly
  - made up of a loop condition and the body which contains the statements to repeat
  - usecases: specific number of times, each element in a collection, while condition remains true, until condition becomes false, until we reach the end of some input stream, forever, many many more...
  - Cpp looping constructs
    - for loop: iterate a specific number of times
    - range-based for loop: one iteration for each element in a range or collection
    - while loop: iterate while condition remains true, stop when condition becomes false, checking the condition at the beginning of every iteration
    - do-while loop: like while but checking the condition at the end of every iteration
- for Loop
  - `for (initialization; condition; increment) statement;`
    - initialization executed once before every iteration
    - condition evaluates to Bool, checked before every iteration; if true loop iterates, if false iterations stop
    - increment executes after the statements
  - with ARRAYS[3]: either `i<3` or `i<=2`!!
  - COMMA operator: not used often but can initialize variables in loops (associativity left-to-right, so result is rightmost)
```cpp
for (int i{1}; i<=10; ++i)
    cout << i << endl;

for (int i{1}; i<=10; i+=2)
    cout << i << endl;

for (int i{10}; i>0; --i)
    cout << i << endl;
cout << "Blastoff!" << endl;

for (int i{10}; i<=100; i+=10)
    if (i % 15 == 0) cout << i << endl;

for (int i{1}; i<=100; ++i)
    cout << i << ((i%10==0) ? "\n" : " ");
```
```cpp
for (int i{1}, j{5}; i<=5; ++i, ++j)
    cout << i << " * " << j << " = " << (i * j) << endl;

int scores [] {100,90,87};
for (int i{0}; i<3; ++i)
    cout << scores[i] << endl;

// #include <vector>
vector <int> nums {10,20,30,40,50};
for (unsigned i{0}; i<nums.size(); ++i)
    cout << nums[i] << endl;

for (;;)
    cout << "Endless loop" << endl;
```
- EXERCISE: for Loop - Sum of Odd Integers
- range-based for Loop
  - introduced in C++11
  - same type both condition variable & sequence; either explicit declaration or `auto` keyword
```cpp
for (auto c: "This is a test")
    cout << ((c == ' ') ? '\t' : c);

// More in ../src/
```
- EXERCISE: Using the range-based for Loop
- while Loop
  - condition testing evaluated to boolean at the beginning of each iteration
  - input validation!
```cpp
int i {1};
while (i <=5){
    cout << i << endl;
    ++i;    // important
}

i = 1;
while (i <= 10){
    if (i % 2 == 0)
        cout << i << endl;
    ++i;
}

int scores [] {100,90,87};
int i {0};
while (i < 3){
    cout << scores[i] << endl;
    ++i;
}

int num {};
cout << "Enter a positive integer - start the countdown: ";
cin >> num;
while (num > 0){
    cout << num << endl;
    --num;
}
cout << "Blastoff!" << endl;

int num {};
cout << "Enter a positive integer to count up to: ";
cin >> num;
int i {1};
while (num >= i){
    cout << i << endl;
    i++;
}
```
```cpp
int number {};
cout << "Enter an integer between 0 and 100: ";
cin >> number;
while (cin.fail() || number <= 0 || number >= 100){
    cin.clear();          // clear the fail bit
    cin.ignore(1000, '\n'); // discard extraneous characters
    cout << "Enter a valid integer: ";
    cin >> number;
}
cout << "Thanks" << endl;

bool done {false};
int number {0};
while (!done){
    cout << "Enter an integer between 1 and 5: ";
    cin >> number;
    if (number<=1 || number>=5)
        cout << "Out of range, try again" << endl;
    else {
        cout << "Thanks!" << endl;
        done = true;
    }
}
```
- EXERCISE: while Loop (!)
- do while Loop
  - condition evaluated after iteration, so the loop body will execute at least once!
```cpp
int number {};
do {
    cout << "Enter an integer between 1 and 5: ";
    cin >> number;
} while (number <= 1 || number >= 5);
cout << "Thanks" << endl;

char selection {};
do {
    double width{}, height{};
    cout << "Enter width and height separated by a space: ";
    cin >> width >> height;
    double area {width * height};
    cout << "The area is " << area << endl;
    cout << "Calculate another? (y/n): ";
    cin >> selection;
} while (selection == 'y' || selection == 'Y');
cout << "Thanks!" << endl;
```
- continue and break
  - used within any Loop; don't overuse them!
  - continue: no further statements in the body of the loop are executed; control immediately goes directly to the beginning of the loop for the next iteration
  - break: no further statements in the body of the loop are executed; loop is immediately terminated; control immediately goes to the statement following the loop construct
```cpp
vector <int> values {1,2,-1,3,-1,-99,7,8,10};
for (auto val: values){
    if (val == -99)
        break;
    else if (val == -1)
        continue;
    else
        cout << val << endl;
}
```
- Infinite Loops
  - endless loop: control expression always evaluate to true
  - usually unintented and a programmer error
  - sometimes used with `break` statements to control them
  - sometimes REQUIRED: event loop in an event-driven program, Operating System, etc.
    - mobileDevices, embeddedSystems: listen for mouseClicks, mouseMovement, touches, etc.
    - handle IO, manage resources, etc. until poweroff
```cpp
// Infinite for
for (;;)
    cout << "This will print forever" << endl;

// Infinite while
while (true)
    cout << "This will print forever" << endl;

// Infinite do-while
do {
    cout << "This will print forever" << endl;
} while (true);

// Actually useful but better add condition to be evaluated
while (true){
    char again {};
    cout << "Do you want to loop again? (y/n): ";
    cin >> again;
    if (again == 'n' || again == 'N')
        break;
}
```
- Nested Loops
  - as many levels deep as required; very useful with multi-dimensional data structures
  - outer loop VS inner loop
```cpp
for (int outer_val {1}; outer_val <= 2; ++outer_val){
    for (int inner_val {1}; inner_val <= 3; ++inner_val)
        cout << outer_val << ": " << inner_val << endl;
    cout << "Inner loop completed" << endl;
}
cout << "Outer loop completed" << endl;

for (int num1 {1}; num1 <= 10; ++num1){
    cout << num1 << " TIMES TABLE" << endl;
    for (int num2 {1}; num2 <= 10; ++num2){
        cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    }
    cout << "-------------------" << endl;
}
```
```cpp
// Arrays
int grid[5][3] {};
for (int row{0}; row<5; ++row){
    for (int col{0}; col<3; ++col){
        grid[row][col] = 420;
        cout << grid[row][col] << " ";
    }
    cout << endl;
}

// Vectors + range-based loop
vector<vector<int>> vector_2d {
    {1,2,3},
    {10,20,30,40},
    {100,200,300,400,500}
};
for (auto vec: vector_2d){
    for (auto val: vec)
        cout << val << " ";
    cout << endl;
}

// Nested Loops - Histogram
int num_items {};
cout << "How many data items do you have? ";
cin >> num_items;
vector <int> data {};
for (int i{1}; i <= num_items; ++i){
    int data_item {};
    cout << "Enter data item " << i << ": ";
    cin >> data_item;
    data.push_back(data_item);
}
cout << "Displaying Histogram" << endl;
for (auto val: data){
    for (int i{1}; i<=val ; ++i)
        cout << ((i%5==0) ? "+" : "-");
    cout << endl;
}
```
- EXERCISE (!): Nested Loops - Sum of the Products of all Pairs of Vector Elements
- SECTION CHALLENGE
- SECTION QUIZ
  1. What is the value of `num` after the following code executes if the user enters `10` at the keyboard? `int num; cin >> num;  if (num > 10) num -= 10; else num += 10;` *20*
  2. What does the following code snippet display if the user enters `70` at the keyboard? *—*
  3. *—*
  4. What will the following code snippet display? `int num = 10; while (num >= 1) cout << num << " "; num--;` *10 10 10 ... infinitely*
  5. The while loop is an example of a(n) *pre-test loop*
  6. A do-while loop is guaranteed to execute *at least one time*
  7. The for loop has 3 expressions in the following order: *initialize, test, increment*
  8. A loop that is located inside another loop is called a(n) *nested loop*
  9. In order to terminate the execution of a loop, we can use the *`break`* statement
  10. If you know ahead of time how many times you need to loop, which loop would you use? *for loop*


## 7. Characters and Strings

> `<cctype>` `<cstring>` `<cstdlib>` // `<string>`

```markdown
# SECTION SUMMARY

// C-style
- <cctype>
  - `isalpha(c)` `isalnum(c)` `isdigit(c)` `isprint(c)`
  - `islower(c)` `isupper(c)` `isspace(c)` `ispunct(c)`
  - `tolower(c)` `toupper(c)`
- <cstring>
  - `strcpy(...)`
  - `strcat(...)`
  - `strlen(...)`
- <cstdlib>
  - ...

// C++
- <string>
  - `substr(starting_index, length)`
  - `substr(starting_index, length)`
  - `find(substring,starting_index)`
  - `erase(starting_index, length)`
  - `my_string.clear()`
  - `my_string.length()`
  - `getline(cin,variable,length)`
- GENERAL
  - `my_string.at(n)`
```

- Character Functions
  - [\<cctype>](https://cplusplus.com/reference/cctype/): simple and useful functions (always expect a single character) for...
    - **testing** characters (evaluate to true/false) `isalpha(c)` `isalnum(c)` `isdigit(c)` `islower(c)` `isprint(c)` `ispunct(c)` `isupper(c)` `isspace(c)` ...
    - converting character case: `tolower(c)` `tolower(c)`
- C-Style Strings
  - sequence of characters:
    - contiguous in memory
    - implemented as an array of characters (we can access individual chars via 'array subscript syntax')
    - terminated by a NULL character (character `\0` with a value of zero)
    - referred to as zero or null terminated strings
  - string literal
    - sequence of characters in double quotes, eg. "Frank"
    - constant
    - terminated with NULL character
  - [\<cstring>](https://cplusplus.com/reference/cstring/): copying, concatenation, comparison, searching,... // All rely on char sequence terminating in NULL char!!
    - `strcpy`, `strcat`, `strlen`
  - \<cstdlib>: convert C-style strings to: integer, float, long, etc
```cpp
// C-style String Variables - '\0' demo
char my_name[8] {"Frank"};
cout << "Num elements: " << sizeof(my_name) / sizeof(my_name[0]) << endl;
for (auto val: my_name){
    if (isalnum(val)) cout << val << endl;  // #include <cctype>
    else if (val == '\0') cout << "NULL" << endl;
    else cout << "idk" << endl;
}
// my_name[6] = 'y';    // *stack smashing*


// C-style String Variables - assignment demo
char my_name[8];
    // my_name = "Frank";   // error
strcpy(my_name, "Frank");  // #include <cstring>
```
- Working with C-style Strings
```cpp
#include <cctype>   // for c-style string functions
#include <cstring>  // for character-based functions
#include <iostream>
using namespace std;

int main(){
    char first_name[20] {};
    char last_name[20] {};
    char full_name[50] {};
    // char temp[50] {};
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    // C-style variables are returned char by char until '\0' is found
    // 'strlen' returns a 'size_t' datatype
    cout << "Hello " << first_name << ", your first name has "
         << strlen(first_name) << " characters, \nand your last name, "
         << last_name << ", has " << strlen(last_name) << " characters" << endl;

    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, last_name);
    cout << "Your full name is " << full_name << endl;
    return 0;
}
```
```cpp
cout << "Enter your full name: ";
cin.getline(full_name,50);
// cin >> full_name; // Characters after the space won't be read!!
cout << "Your full name is " << full_name << endl;

strcpy (temp, full_name);

if (strcmp(temp, full_name) == 0)
    cout << temp << " and " << full_name << " are the same" << endl;
else cout << temp << " and " << full_name << " are different" << endl;

for (size_t i{0}; i< strlen(full_name); ++i)
    if (isalpha(full_name[i]))
        full_name[i] = static_cast<char>(toupper(full_name[i]));
        // full_name[i] = toupper(full_name[i]);
cout << "Your full name is " << full_name << endl;

if (strcmp(temp, full_name) == 0)
    cout << temp << " and " << full_name << " are the same" << endl;
else cout << temp << " and " << full_name << " are different" << endl;

cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;    // positive
cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;    // negative
```
- EXERCISE: Using C-style Strings
- C++ Strings (OOP-CLASSES!!)
  - **`std:string`: Class in the Standard Template Library**
    - `#include <string>`
    - std namespace
    - contiguous in memory BUT *dynamic size*
    - work with input and output streams
    - lots of useful **member functions**
    - familiar operators can be used...
    - safer (bound-checking...) & easily converted to C-style Strings if needed
  - assignment with `=` unlike C-style (functions)!! (`string s1; s1 = "C++ Rocks!";`)
  - comparison: character by character lexically
    - can compare: two objects, an object and a C-style literal, an object and a C-style variable
  - `substr(starting_index, length)`: extracts a substring from a std::string object
  - searching - `find(substring,starting_index)`: returns the index of a substring in a std::string
  - removing characters - `erase(start_index, length)`, `clear()`
  - Input - `>>` VS `getline()` (up to space VS up to \\n)
```cpp
#include <string>
using namespace std;

// Declaring and initializing
string s1;              // Empty
string s2 {"Frank"};    // Frank
string s3 {s2};         // Frank
string s4 {"Frank", 3}; // Fra
string s5 {s3, 0, 2};   // Fr
string s6 (3, 'X');     // XXX  // mind 'constructor syntax ()'

// Assignment =
string s1;
s1 = "C++ Rocks!";`
string s2;
s1 = s2;

// Concatenation
string part1 {"C++"};
string part2 {"is a powerful"};
string sentence;
sentence = part1 + " " + part2 + " language";
// sentence = "C++" + " is powerful"; // ERROR - need c++ strings with c-style literals

// Accessing characters [] and at() method
string s1 {"Frank"};
cout << s1[0] << endl;      // F
cout << s1.at(0) << endl;  // F
s1[0] = 'f';        // frank
s1.at(0) = 'p';    // prank    
string s2 {"Frank"};
for (int c: s2)
    cout << c << endl;
// char my_name [] {"Frank"};
// for (int c: my_name)
    // cout << c << endl;
```
```cpp
// Comparing
cout << boolalpha;
string s1 {"Apple"};
string s2 {"Banana"};
string s3 {"Kiwi"};
string s4 {"apple"};
string s5 {s1};
cout << (s1 == s5) << endl;         // true
cout << (s1 == s2) << endl;         // false
cout << (s1 != s2) << endl;         // true
cout << (s1 < s2) << endl;          // true
cout << (s2 > s1) << endl;          // true
cout << (s4 < s5) << endl;          // false
cout << (s1 == "Apple") << endl;    // true

// Substrings - substr()
    string s1 {"This is a test"};
    // for (size_t i{0}; i<s1.size();++i)
    //     cout << i << ": " << s1.at(i) << endl;
    cout << s1.substr(0,4) << endl;  // This
    cout << s1.substr(5,2) << endl;  // is
    cout << s1.substr(10,4) << endl; // test

// Searching - find()
string s1 {"This is a test"};
cout << s1.find("This") << endl;    // 0
cout << s1.find("is") << endl;      // 2
cout << s1.find("test") << endl;    // 10
cout << s1.find('e') << endl;       // 11
cout << s1.find("is",4) << endl;    // 5
cout << s1.find("XX") << endl;      // string::npos

// Removing characters
string s1 {"This is a test"};
cout << s1.erase(0,5) << endl;   // is a test
cout << s1.erase(5,4) << endl;   // is a
s1.clear();
cout << s1.erase(0,5) << endl;   // empty!!

// Other useful methods
string s1 {"Frank"};
cout << s1.size() << endl;      // 5
cout << s1.length() << endl;    // 5
s1 += " James";
cout << s1.length() << endl;      // 11

// INPUT
string s1;
// cin >> s1;           // Hello there - Only accepts up to the first space
// cout << s1 << endl;  // Hello
getline(cin, s1);       // Read entire line until \n
cout << s1 << endl;     // Hello there
getline(cin,s1,'x');    // this isx (DELIMITER!!)
cout << s1 << endl;     // this is
```
- Working with C++ Strings
```cpp
string s0;  // OK, no garbage
string s1 {"Apple"};
string s2 {"Banana"};
string s3 {"Kiwi"};
string s4 {"apple"};
string s5 {s1};
string s6 {s1,0,3}; // App
string s7 (10,'X'); // XXXXXXXXXX

s3 = s1 + " and " + s2 + " Juice";
// s3 = "Nice " + "cold " + s1 + " and " + s2 + " Juice";  // ERROR - need strcat()
cout << s3 << endl;

for (size_t i{0}; i<s1.length(); ++i)
    cout << s1.at(i) << endl;
for (auto c: s1)
    cout << c << endl;
```
```cpp
// NOTE string:npos !!
string s1 {"The secret word is Boo"};
string word {};

cout << "Enter the word to find: ";
getline(cin, word);
size_t position {s1.find(word)};

if (position != string::npos)
    cout << "Found " << word << " at position: " << position << endl;
else cout << "Sorry, " << word << " not found" << endl;
```
- EXERCISES: Using C++ Strings
- SECTION CHALLENGE
- SECTION QUIZ
  1. C-style strings are terminated with a(n) *null character \0*
  2. The function we can use to copy one C-style string to another is *`strcpy`*
  3. In order to use C-style string functions we must #include *`<cstring>`*
  4. To convert a char to its upper case equivalent we can use the *`toupper`* function
  5. The C-style string name[6] can *—*
  6. In order to use a C++ string object, we must #include *`<string>`*
  7. The + operator allows us to *concatenate* two C++ strings
  8. In order to find the index of a substring within a C++ string, we can use the *`find`* method
  9. We can compare two C++ strings using the *`==`*
  10. Which of the following are true about C++ strings? *C++ strings are objects, have a rich set of member methods, are preferred over C-style strings and can change in size dynamically*
- ASSIGNMENT: Letter Pyramid

<details>

```cpp
#include <string>
#include <iostream>
using namespace std;


int main() {
    string inputString;
    cout << "Enter a string: ";
    getline(cin, inputString);

    string::size_type length = inputString.length();

    for (string::size_type i = 0; i < length; i++) {
        for (string::size_type j = length - 1; j > i; j--) {
            cout << " ";
        }

        for (string::size_type k = 0; k <= i; k++) {
            cout << inputString[k];
        }

        for (string::size_type l = i - 1; l != string::npos; l--) {
            cout << inputString[l];
        }

        cout << endl;
    }

    return 0;
}
```
```cpp
// Letter Pyramid
// Written by Frank J. Mitropoulos

/*
Get the input from the user and store it in a std::string variable
Loop for each letter in the string entered by the user
    Determine how many blank spaces must be displayed before the current row and display them
    Determine how many letters must be displayed before the current character and display them
    Display the current character
    Display the remaining characters in reverse order
    Complete the row with a new line

*/

#include <string>
#include <iostream>
using namespace std;


int main()
{
    string letters{};
    cout << "Enter a string: ";
    getline(cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            cout << letters.at(j);
        }

        // Display the current 'center' character
        cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            cout << letters.at(k);
        }

        cout << endl; // Don't forget the end line
        ++position;
    }

    return 0;
}
```
</details>

## 8. Functions

```markdown
# SECTION SUMMARY

<cmath>
- `sqrt(num)`   `pow(base,exp)`
- sin cos
- ceil floor round
<cstdlib>
- srand
- rand
<ctime>
- `time()`
<random>
- [ ] 
```

> There's a field in Computer Science called Software Engineering. SWE is all about designing your solutions and writing your code in a way that can be easily understood, debugged and extended. A fundamental principle is abstraction, which is exactly what functions help us achieve.

- What is a Function?
  - Cpp program == [Cpp Standard Libraries](https://en.cppreference.com/w/cpp/header) + Third-party libraries + our own FUNCTIONS and CLASSES
  - Functions allow the modularization of a program: separate code into logical self-contained units, that can be reused
  - Boss/Worker analogy: write code to the function specification - understand what the function does, what information needs, what returns, any errors it may produce, performance constraint
    - Don't worry about HOW the function works internally (unless you are the one writing the function)
```cpp
#include <cmath>

int add_numbers(int a, int b){
    if (a < 0 || b < 0) return 0;
    else return a + b;
}

int main(){
    cout << sqrt(400.0) << endl;
    cout << pow(2.0,3.0) << endl;
    cout << add_numbers(-1,9) << endl;
    return 0;
}
```
```cpp
#include <ctime>
#include <cstdlib>

int random_number {};
size_t count {10};   // amount of random numbers to generate
int min {1};         // lower bound (inclusive)
int max {20};        // upper bound (inclusive)

// Seed the random number generator, otherwise the generation sequence will always be the same
cout << "RAND_MAX on my system is: " << RAND_MAX << endl;
srand(static_cast<int>(time(nullptr)));

for (size_t i{1}; i<=count; ++i){
    random_number = rand() % max + min;
    cout << random_number << endl;
}
```
- EXERCISE: Using Functions from the `<cmath>` library
- Function Definition
  - return type (`void`|datatype) + name + parameter list + body
```cpp
#include <iostream>
using namespace std;

const double pi {3.14159};

double calc_area_circle(double radius){
    return pi * radius * radius;
}
double calc_volume_cylinder(double radius, double height){
    return calc_area_circle(radius) * height;
    // return pi * radius * radius * height;
}

void area_circle(){
    double radius{};
    cout << "Enter the radius of the circle: ";
    cin >> radius;
    cout << "The area of a circle with radius " << radius << " is: " << calc_area_circle(radius) << endl;
}
void volume_cylinder(){
    double radius{};
    double height{};
    cout << "Enter the radius of the cylinder: ";
    cin >> radius;
    cout << "Enter the height of the cylinder: ";
    cin >> height;
    cout << "The volume of a cylinder with radius " << radius << " and height " << height << " is: " << calc_volume_cylinder(radius,height) << endl;
}

int main(){
    area_circle();
    volume_cylinder();
    return 0;
}
```
- Function Prototypes <!--PRE-DECLARATION-->
  - Compiler must know a function before it's used
    - Define functions before calling them
      - ok for small programs
      - not practical for larger programs
      - impossible if they call one another
    - Use function prototypes
      - tells the compiler what it needs to know without a full function definition
      - also called forward declarations
      - placed at the beginning of the program
      - also used in our header files (`.h`) - more about this later
      <!-- - CUSTOM: if function is prototyped but not defined, Linker error at compile-time! -->
```cpp
#include <iostream>
using namespace std;
void supdawg(int count);    // Prototype - function pre-declared
void dawg();               // Prototype - function pre-declared

int main(){
    supdawg(5);
    cout << "not much wbu" << endl;
    return 0;
}
void supdawg(int count){
    for (int i{0}; i<count; ++i){
    cout << "sup";
    dawg();
    }
}
void dawg(){
    cout << "dawg" << endl;
}
```
- Function Parameters and the `return` Statement
  - data passed to a function
    - called 'arguments' in the function call
    - called 'parameters' in the function definition
    - must match in number, order and type, although the compiler will try to do type-converstion if necessary <!--NO WARNINGS for strings/arrays...-->
  - *Pass-by-value*
    - data passed into a function is passed-by-value
    - a **copy** of the data is passed to the function — which has pros and cons...
    - whatever changes made to the parameter in the function don't affect the argument passed in
    - formal VS actual parameters: defined in function header VS used in function call, arguments
  - Function `return` statement
    - if function returns a value it requires the statement; if the function doesn't return a value it is *optional*
    - immediately exits the function!
    - we can have many in a function, but should avoid it
    - the return value is the result of the function call...
```cpp
void param_test(int formal){
    cout << formal << endl; // 50
    formal = 100;
    cout << formal << endl; // 100
}

int main(){
    int actual {50};
    cout << actual << endl; // 50
    param_test(actual);
    cout << actual << endl; // 50
    return 0;
}
```
- EXERCISE: Functions and Prototypes - Converting Temperatures
- Default Argument Values
  - when a function is called, all arguments must be supplied
  - sometimes some of the arguments have the same values most of the time
  - we can tell the compiler to use default values if the arguments are not supplied
  - default values can be in the prototype OR definition, not both — best practice in the prototype; must appear at the tail end of the parameter list
  - can have multiple default values — must appear consecutively at the tail end of the parameter list
```cpp
double calc_cost(double base_cost, double tax_rate = 0.06);

double calc_cost(double base_cost, double tax_rate){
    return base_cost += (base_cost * tax_rate);
}

int main(){
    double cost {};
    cost = calc_cost(100.0);    // will use the default tax
    cout << "Cost: " << cost << endl;
    cost = calc_cost(100.0, 0.08);  // will use 0.08 not the default
    cout << "Cost: " << cost << endl;
    return 0;
}
```
```cpp
void greeting(string name, string prefix = "Mr.", string suffix = "");

void greeting(string name, string prefix, string suffix){
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}

int main(){
    greeting("Pablo Quevedo");
    greeting("Frank Miller", "Dr.");
    greeting("Glenn Jones", "Dr.", "M.D.");
    greeting("James Rogers", "Professor", "Ph.D");
    return 0;
}
```
- EXERCISE: Using Default Argument Values - Grocery List
- Overloading Functions
  - (we can have functions that have) different parameter types lists that have the same name
  - abstraction mechanism since we can just think 'print' for example, and specify the parameter data3type
  - a type of **polymorphism**: we can have the same name work with different data types to execute similar behavior
  - the compiler must be able to tell the functions apart based on the parameter lists and arguments supplied
  - the `return` type is not considered! — thus parameters differenciate
```cpp
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void print(int num=69){
    cout << "Print int: " << num << endl;
}
void print(char c){
    cout << "Print char: " << c << endl;
}
void print(double num=6.9){
    cout << "Print double: " << num << endl;
}
void print(float num){
    cout << "Print float: " << num << endl;
}
void print(string s){
    cout << "Print string: " << s << endl;
}
void print(vector<string> vec){
    cout << "Print vector: ";
    for (auto v: vec)
        cout << v << " ";
    cout << endl;
}

int main(){
    print(100);
    print('A'); // Prints char or int (65) if no char function!!
    print(123.5);
    print(123.5F);  // Prints float or double if no float function!
    print("C-style string");
    string s {"C++ string"};
    vector<string> vec {"who","am","i"};
    print(vec);
    // print(); // ERROR because two functions with default means confused compiler!
    return 0;
}
```
- EXERCISE: Overloading Functions - Calculating Area
- Passing Arrays to Functions
  - just need to provide square brackets in the formal parameter description
    - `void print_array(int numbers [], size_t size);`
  - the array elements are NOT copied, instead we are passing in the **memory address** of the first element
    - since the array name evaluates to the location of the array in memory, this address is what is copied!!
    - so the function has no idea how many elements are in the array since all it knows is the location of the first element (the name of the array)
    - to iterate effectively, pass in the **size** of the array to the function!!
  - since we are passing in the location of the array, **the function may modify the actual array**!
    - use `const` to ensure unmodifiable lvalue
```cpp
void zero_array(int scores [], size_t size);
void set_array(int scores [], size_t size, int value = 100);
void print_array(const int scores [], size_t size);

void zero_array(int scores [], size_t size){
    // for (auto n: scores) n = 0;  // won't work...
    for (size_t i{0}; i<size; ++i)
        scores[i] = 0;
}
void set_array(int scores [], size_t size, int value){
    for (size_t i{0}; i<size; ++i)
        scores[i] = value;
}
void print_array(const int scores [], size_t size){
    for (size_t i{0}; i<size; ++i){
        cout << scores[i] << " ";
        // scores[i] = 0;  // Good ERROR because constant declaration
    }
    cout << endl;
}

int main(){
    int my_scores [] {100,98,90,86,84};
    int arr_size = sizeof(my_scores) / sizeof(my_scores[0]);
    // for (auto n: my_scores) ++arr_size;
    
    // zero_array(my_scores, arr_size);
    set_array(my_scores, arr_size, 97);
    print_array(my_scores, arr_size);
    return 0;
}
```
- EXERCISE: Passing Arrays to Functions - Print a Guest List
- *Pass-by-Reference*
  - Sometimes we want to be able to change the actual parameter from within the function body
  - To achieve this we need the **location or address** of the actual parameter
  - We can use parameters to tell the compiler to pass in a reference to the actual parameter
  - The formal parameter will now be an alias for the actual parameter
```cpp
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void pass_by_ref1(int &num);
void pass_by_ref2(string &s);
void pass_by_ref3(vector<string> &v);
void print_vector(const vector<string> &v);

void pass_by_ref1(int &num){
    num = 1000;
}

void pass_by_ref2(string &s){
    s = "Changed";
}

void pass_by_ref3(vector <string> &v){
    v.clear();
}

void print_vector(const vector<string> &v){
    for (auto s: v)
        cout << s << " ";
    cout << endl;
}

int main(){
    int num {10};
    cout << "Num before calling pass_by_ref1: " << num << endl;
    pass_by_ref1(num);
    cout << "Num after calling pass_by_ref1: " << num << endl;

   string name{"Frank"};
   cout << "\nName before calling pass_by_ref2: " << name << endl;
   pass_by_ref2(name);
   cout << "Name after calling pass_by_ref2: " << name << endl;

   vector<string> stooges {"Larry", "Moe", "Curly"};
   cout << "\nStooges before calling pass_by_ref3: ";
   print_vector(stooges);
   pass_by_ref3(stooges);
   cout << "Stooges after calling pass_by_ref3: ";
   print_vector(stooges);

    cout << endl;
    return 0;
}
```
- EXERCISE: Using Pass by Reference - Print a Guest List
- **Scope Rules**
  - C++ uses scope rules to determine where an identifier can be used
  - C++ uses static or lexical scoping
  - Local or Block scope
    - Identifiers declared in a block `{}`
    - Function parameters have block scope
    - Only visible within the the block `{}` where declared
    - Function local variables are only active while the function is executing
    - Local variables are NOT preserved between function calls
    - With nested blocks inner blocks can 'see' but outer blocks cannot 'see' in
    - Static local variables (`static int value {10};`), value is preserved between function calls.
  - Global scope
    - Identifier declared outside any function or class
    - Visible to all parts of the program after the global identifier has been declared
    - Global constants are OK
    - Best practice - DON'T use global variables
```cpp
void static_local_example(){
    static int num {5000};  // retains its value between calls
    cout << "\nLocal static num is " << num << " in static_local_example - start" << endl;
    num += 1000;
    cout << "Local static num is " << num << " in static_local_example - end" << endl;
}

int main(){
    int num {100};
    int num1 {500};
    cout << "Local num is " << num << " in main" << endl;
    { // Creates a new level of scope
        int num {200};
        cout << "Local num is " << num << " in inner block in main" << endl;
        cout << "Inner block in main can see out - num1 is " << num1 << endl;
    }
    cout << "Local num is " << num << " in main still" << endl;
    static_local_example(); // 5000 - 6000
    static_local_example(); // 6000 - 7000
    static_local_example(); // 7000 - 8000
    return 0;
}
```
- How do Function Calls Work?
  - 
- inline Functions
- Recursive Functions
- EXERCISE: Implementing a Recursive Function - Save a Penny
- SECTION CHALLENGE
- SECTION QUIZ
- 

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