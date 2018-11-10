#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    const double burnCalpm = 3.9;

    cout << setw(10) << "Minutes" << setw(15) << "Burned Calories" << endl;

    cout << fixed << setprecision(1);

    for (int i = 5; i <= 30; i+= 5) {
        cout << setw(10) << i << setw(15) << burnCalpm * i << '\n';
    }

    return 0;
}