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