#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double presentValue(double, double, double);

int main() {
    double f, t, r100;

    cout << "Expected future money:\t$";
    cin >> f;
    cout << "Expected time:\t";
    cin >> t;
    cout << "Annual Interest rate: (12% -> 12)\t";
    cin >> r100;
    cout << "\n\n\n";
    cout << "Money need to deposit:\t$"
         << presentValue(f, r100/100, t);
    return 0;
}

double presentValue(double futureMoney, double interest, double years) {
    return futureMoney / pow(1 + interest, years);
}