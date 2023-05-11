/*
Modify the previous source code to include both small and large rooms.
*/

#include <iostream>
using namespace std;

int main(){
    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl;
    cout << "How many small rooms would you like cleaned? ";
    int number_of_small_rooms {0};
    cin >> number_of_small_rooms;
    cout << "How many large rooms would you like cleaned? ";
    int number_of_large_rooms {0};
    cin >> number_of_large_rooms;

    const double price_per_small_room {25.00};
    const double price_per_large_room {35.00};
    const double sales_tax {0.06};
    const int estimate_expiry {30};

    double service_cost {(price_per_small_room * number_of_small_rooms)
                        + (price_per_large_room * number_of_large_rooms)};

    cout << "\nEstimate for carpet cleaning service" << endl;
    cout << "Number of small rooms: " << number_of_small_rooms << endl;
    cout << "Number of large rooms: " << number_of_large_rooms << endl;
    cout << "Price per small room: $" << price_per_small_room << endl;
    cout << "Price per large room: $" << price_per_large_room << endl;
    cout << "Cost: $" << service_cost << endl;
    cout << "Tax: $" << service_cost * sales_tax << endl;
    cout << "====================================" << endl;
    cout << "Total estimate: $" << service_cost + (service_cost * sales_tax) << endl;
    cout << "The estimate is valid for " << estimate_expiry << " days" << endl;

    cout << endl;
    return 0;
}
