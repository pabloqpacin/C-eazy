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