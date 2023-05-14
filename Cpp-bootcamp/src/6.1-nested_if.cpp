/*
Shipping cost calculator
Ask the user for package dimension in inches
length, width, height - these should be integers
All dimensions must be 10 inches or less or we cannot ship it
Base cost $2.50
If package volume is greater than 100 cubic inches there is a 10% surcharge
If package volume is greater than 500 cubic inches there is a 25% surcharge
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int length{}, width{}, height{};
    int package_volume {};
    double base_cost {2.50};
    int max_dimensions_length {10};
    const int tier1_threshold {100};
    const int tier2_threshold {500};
    double tier1_surcharge {0.10};
    double tier2_surcharge {0.25};

    cout << "Welcome to the package cost calculator" << endl;
    cout << "Enter length, width and height of the package separated by spaces: ";
    cin >> length >> width >> height;

    if (length > max_dimensions_length || width > max_dimensions_length || height > max_dimensions_length){
        cout << "Sorry, package rejected - dimensions exceeded" << endl;
    } else {
        package_volume = length * width * height;
        double package_cost {base_cost};    // package_cost = base_cost;
        if (package_volume > tier2_threshold){
            package_cost += package_cost * tier2_surcharge;
            cout << "adding tier 2 surcharge" << endl;
        } else if (package_volume > tier1_threshold){
            package_cost += package_cost * tier1_surcharge;
            cout << "adding tier 1 surcharge" << endl;
        }
        cout << fixed << setprecision(2); // prints 2 decimals
        cout << "The volume of the package is: " << package_volume << endl;
        cout << "Your package will cost $" << package_cost << " to ship" << endl;
    }

    cout << endl;
    return 0;
}


    // int score{88};
    // if (score > 90)
    //     if (score > 95) cout << "A+";
    //     else cout << "A";
    // else cout << "Sorry, no A";

    // int score_frank {69};
    // int score_bill {69};
    // if (score_frank != score_bill)
    //     if (score_frank > score_bill)
    //         cout << "Frank Wins" << endl;
    //     else cout << "Bill Wins" << endl;
    // else cout << "Looks like a tie!" << endl;
