#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    const double caloriesPerMin = 3.90;

    cout << "Minutes" << "     Calories burnt" << endl;
    cout << fixed << setprecision(2);
    
    for (int min = 5; min <= 30; min += 5) {

        cout << left << setw(8) << min << right << setw(15) << caloriesPerMin * min << endl;
    }
    return 0;
}
