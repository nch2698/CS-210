#include <iostream>
#include <iomanip>

using namespace std;

double fallingDistance(double);

int main() {

    cout << setw(10) << "Time" << setw(15) << "Distance" << endl;
    cout << fixed << showpoint << setprecision(2);

    for (int i = 1; i <= 10; i++) {
        cout << setw(10) << i << setw(15) << fallingDistance(i + 0.0) << endl;
    }

    return 0;
}

double fallingDistance(double time) {
    static const double g = 9.8;
    return 0.5 * g * time * time;
}