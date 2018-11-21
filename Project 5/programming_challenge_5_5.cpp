#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    const double rate = 1.04;
    double charge = 2500.0;
    int year;
    cout << "Years" << "     Membership Charge" << endl;

    cout << fixed << setprecision(2);

    for (year = 1; year <= 6; year++) {
        cout << left << setw(5) << year << right << setw(15) << charge * rate << endl;
        charge *= rate;
    }
    return 0;
}
