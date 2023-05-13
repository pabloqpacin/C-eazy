#include <iostream>
using namespace std;

int main(){

    const int dollar_value {100};
    const int quarter_value {25};
    const int dime_value {10};
    const int nickel_value {5};
    const int penny_value {1};

    int change_amount {0};
    cout << "Enter an amount in cents: ";
    cin >> change_amount;

    int balance{0}, dollars{0}, quarters{0}, dimes{0}, nickels{0}, pennies{0};

    dollars = change_amount / dollar_value;
    balance = change_amount % dollar_value;
    // balance = change_amount - (dollars * dollar_value);
    quarters = balance / quarter_value;
    balance %= quarter_value;
    // balance -= quarters * quarter_value;
    dimes = balance / dime_value;
    balance %= dime_value;
    nickels = balance / nickel_value;
    balance %= nickel_value;
    pennies = balance / penny_value;
    balance %= penny_value;

    cout << "Dollars  : " << dollars << endl;
    cout << "Quarters : " << quarters << endl;
    cout << "Dimes    : " << dimes << endl;
    cout << "Nickels  : " << nickels << endl;
    cout << "Pennies  : " << pennies << endl;

    return 0;
}