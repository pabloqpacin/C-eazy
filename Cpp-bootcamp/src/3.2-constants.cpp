/*
- Frank's Carpet Cleaning Service
Charges $30 per room
Sales tax rate is 6%
Estimates are valid for 30 days
- Prompt the user for the number of rooms they would like cleaned
and provide an estimate such as:
'Estimate for carpet cleaning service:
Number of rooms: 2
Price per room: $30
Cost: $60
Tax: $3.6
Total estimate: $63.6
The estimate is valid for 30 days'
- Pseudocode:
...
*/

#include <iostream>
using namespace std;

// GUD APPROACH
int main(){
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many rooms would you like cleaned? ";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    const double price_per_room {30.00};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    double service_cost {price_per_room * number_of_rooms};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << price_per_room << endl;
    cout << "Cost: $" << service_cost << endl;
    cout << "Tax: $" << service_cost * sales_tax << endl;
    cout << "Total estimate: $" << service_cost + (service_cost * sales_tax) << endl;
    cout << "The estimate is valid for " << estimate_expiry << " days" << endl;

    cout << endl;
    return 0;
}

/* // GAWDAWFUL APPROACH
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many rooms would you like cleaned? ";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << 30 << endl;
    cout << "Cost: $" << 30 * number_of_rooms << endl;
    cout << "Tax: $" << 30 * number_of_rooms * 0.06 << endl;
    cout << "Total estimate: $"
         << (30 * number_of_rooms) + (30 * number_of_rooms * 0.06) << endl;
    cout << "The estimate is valid for " << 30 << " days" << endl;
*/

/* // INITIAL APPROACH
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many rooms would you like cleaned? ";

    int number_of_rooms {0};
    cin >> number_of_rooms;

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of rooms: " << number_of_rooms << endl;
    cout << "Price per room: $" << 30 << endl;

    int cost_service {number_of_rooms * 30};
    cout << "Cost: $" << cost_service << endl;

    double service_tax {cost_service * 0.06};
    cout << "Tax: $" << service_tax << endl;

    cout << "Total estimate: $" << cost_service + service_tax << endl;
    cout << "The estimate is valid for 30 days \n" << endl;
*/
