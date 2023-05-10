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
