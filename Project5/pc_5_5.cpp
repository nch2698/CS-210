#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    const double STD_FEE = 2500.0;
    double curFee = STD_FEE;

    cout << setw(5) << "Year" << setw(10) << "Fee" << endl;
    cout << fixed << setprecision(1);
    for (int i = 1; i <= 6; i++) {
        cout << setw(5) << i << setw(10) << curFee << '\n';
        curFee *= 1.04;
    }

    return 0;
}