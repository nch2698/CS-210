#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int i;
    double f;
    cout << "Celsius" << "          Fahrenheit" << endl;
    for (i = 1; i <= 20; i++) {
        f = i * 9 / 5.0 + 32;
        cout << fixed << setprecision(2);
        cout << left << setw(8) << i << right << setw(16) << f << endl;
    }
    return 0;
}
