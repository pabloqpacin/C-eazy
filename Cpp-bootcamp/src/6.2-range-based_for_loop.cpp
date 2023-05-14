#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    cout << "\n========== Arrays ==========" << endl;
    int scores[] {10,20,30};
    for (auto score: scores)
        cout << score << endl;

    cout << "\n========== Vectors (1) ==========" << endl;
    vector <double> temperatures {87.9, 77.9,80.0,72.5};
    double total {};
    for (auto temp: temperatures){
        total += temp;
        cout << "Running sum: " << total << endl;
    }
    double average_temperature {};
    if (temperatures.size()!=0)
        average_temperature = total / static_cast<double>(temperatures.size());
    cout << fixed << setprecision(1);
    cout << "Average temperature: " << average_temperature << endl;

    cout << "\n========== Vectors (2) ==========" << endl;
    int size {0};
    double running_sum {};
    for (auto temps: {87.9,77.9,80.0,72.5}){
        running_sum += temps;
        ++size;
        cout << size << " Running sum: " << running_sum << endl;
    }
    double average_temp {};
    average_temp = running_sum / size;
    cout << "Average temperature:" << average_temp << endl;
    
    cout << "\n========== Collections... ==========" << endl;
    for (auto val: {1,2,3,4,5})
        cout << val << " ";
    cout << endl;

    cout << "\n========== Strings ==========" << endl;
    for (auto c: "This is a test")
        cout << ((c == ' ') ? '\t' : c);
        // if (c == ' ') cout << "\t";
        // else cout << c;
        // if (c != ' ') cout << c;

    cout << endl;
    return 0;
}


