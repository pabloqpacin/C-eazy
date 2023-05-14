// Section 9
// Challenge
/*    
    This challenge is about using a collection (list) of integers and allowing the user
    to select options from a menu to perform operations on the list.
    
    Your program should display a menu options to the user as follows:
    
    P - Print numbers
    A - Add a number
    M - Display mean of the numbers
    S - Display the smallest number
    L - Display the largest number
    Q - Quit

    Enter your choice:
    
The program should only accept valid choices from the user, both upper and lowercase selections should be allowed.
If an illegal choice is made, you should display, "Unknown selection, please try again" and the menu options should be
displayed again.


If the user enters 'P' or 'p', you should display all of the elements (ints) in the list.
If the list is empty you should display "[] - the list is empty"
If the list is not empty then all the list element should be displayed inside square brackets separated by a space. 
For example, [ 1 2 3 4 5 ]
      
If the user enters 'A' or 'a' then you should prompt the user for an integer to add to the list 
which you will add to the list and then display it was added. For example, if the user enters 5
You should display, "5 added".
Duplicate list entries are OK

If the user enters 'M' or 'm'  you should calculate the mean or average of the elements in the list and display it.
If the list is empty you should display, "Unable to calculate the mean - no data"

If the user enters 'S' or 's' you should display the smallest element in the list.
For example, if the list contains [2 4 5 1],  you should display, "The smallest number is 1"
If the list is empty you should display, "Unable to determine the smallest number - list is empty"

If the user enters 'L' or 'l' you should display the largest element in the list
For example, if the list contains [2 4 5 1], you should display, "The largest number is 5"
If the list is empty you should display, "Unable to determine the largest number - list is empty"

If the user enters 'Q' or 'q' then you should display 'Goodbye" and the program should terminate.

Before you begin. Write out the steps you need to take and decide in what order they should be done.
Think about what loops you should use as well as what you will use for your selection logic.

This exercise can be challenging! It may likely take a few attempts before you complete it -- that's OK!

Finally, be sure to test your program as you go and at the end.

Hint: Use a vector!

Additional functionality if you wish to extend this program.

- search for a number in the list and if found display the number of times it occurs in the list
- clearing out the list (make it empty again) (Hint: the vector class has a .clear() method)
- don't allow duplicate entries
- come up with your own ideas!

Good luck!
*/

#include <vector>
// #include <iomanip>
#include <iostream>
using namespace std;

int main() {

    char selection {};
    vector <int> data_items {};
    // cout << fixed << setprecision(2); // prints 2 decimals
    cout << "Welcome to the data analysis lab" << endl;

    while (true){
        cout << endl;
        cout << "P - Print numbers" << endl
             << "A - Add a number" << endl
             << "M - Display mean of the numbers" << endl
             << "S - Display the smallest number" << endl
             << "L - Display the largest number" << endl
             << "Q - Quit" << endl
             << "\nEnter your choice: ";
        cin >> selection;
        
        switch (selection) {
            case 'P': case 'p': {
                if (data_items.size() == 0)
                    cout << "[] - the list is empty" << endl;
                else {
                    cout << "[";
                    for (auto val: data_items)
                        cout << " " << val << " ";
                    cout << "]" << endl;
                } break;
            }
            case 'A': case 'a': {
                int new_item{};
                cout << "Enter integer to add to the list: ";
                cin >> new_item;
                data_items.push_back(new_item);
                cout << new_item << " added" << endl;
                break;
            }
            case 'M': case 'm': {
                if (data_items.size() == 0)
                    cout << "Unable to calculate the mean - no data" << endl;
                else{
                    int total{0};
                    for (auto item: data_items)
                        total+=item;
                    cout << "The mean is: " << total << "/" << data_items.size() << " = " 
                        << total / static_cast<double>(data_items.size()) << endl;
                } break;
            }
            case 'S': case 's': {
                if (data_items.size() == 0)
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                else {
                    int smallest {data_items.at(0)};
                    for (auto item: data_items)
                        if (item < smallest)
                            smallest = item;
                    cout << "The smallest number is: " << smallest << endl;
                } break;
            }
            case 'L': case 'l': {
                if (data_items.size() == 0)
                    cout << "Unable to determine the largest number - list is empty" << endl;
                else {
                    int largest {data_items[0]};
                    for (size_t i{0}; i<data_items.size(); ++i)
                        if (data_items[i] > largest)
                            largest = data_items[i];
                    cout << "The largest number is: " << largest << endl;
                } break; 
            }
            case 'Q': case 'q':
                cout << "Goodbye" << endl; break;
            default:
                cout << "Unknown selection, please try again" << endl;
        }

        // Akshually break the loop
        if (selection == 'q' || selection == 'Q')
            break;
    }

    cout << endl;
    return 0;
}


/*
    - [ ] ADDITIONAL FUNCTIONALITY
    - [ ] HARDEN UP SECURITY - ENFORCE INPUT VALIDATION
*/
