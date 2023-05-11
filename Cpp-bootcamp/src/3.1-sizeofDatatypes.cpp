#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

int main(){

    cout << "- Max/Min values to be stored in the given datatype on this machine \n"
         << "Char max: " << CHAR_MAX << "\n"
         << "Char min: " << CHAR_MIN << "\n"
         << "Short max: " << SHRT_MAX << "\n"
         << "Short min: " << SHRT_MIN << "\n"
         << "Int max: " << INT_MAX << "\n"
         << "Int min: " << INT_MIN << "\n"
         << "Long max: " << LONG_MIN << "\n"
         << "Long min: " << LONG_MAX << "\n"
         << "Long-long max: " << LLONG_MIN << "\n"
         << "Long-long min: " << LLONG_MAX << "\n"
         << "Float max: " << FLT_MIN << "\n"
         << "Float min: " << FLT_MAX << "\n"
         << "... and more \n" << endl;



    cout << "- Sizeof datatypes (machine/compiler-dependent) \n"
         << "Char: " << sizeof(char) << " bytes \n"
         << "Int : " << sizeof(int) << " bytes \n"
         << "Unsigned int: " << sizeof(unsigned int) << " bytes \n"
         << "Short: " << sizeof(short) << " bytes \n"
         << "Long: " << sizeof(long) << " bytes \n"
         << "Long long: " << sizeof(long long) << " bytes \n"
         << "Float: " << sizeof(float) << " bytes \n"
         << "Double: " << sizeof(double) << " bytes \n"
         << "Long double: " << sizeof(long double) << " bytes \n"
         << "... and more \n" << endl;

    int age {28};
    double wage {22.24};
    cout << "- Sizeof variables! \n"
         << "Age (int) is " << sizeof age << " bytes \n"
         << "Wage (double) is " << sizeof wage << " bytes \n" << endl;

    return 0;
}
