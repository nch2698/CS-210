#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    double d;

    cout << "Calculate square root of:\t";
    cin >> d;

    double temp = d;

    cout << setprecision(20);

    for (int i = 0; i < 20 ; i++) {
        temp = (d/temp + temp) / 2.0;
    }

    cout << "SQRT(" << d << ") :\t" << temp;

    return 0;
}