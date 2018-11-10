#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    cout << setw(10) << "Celsius" << setw(13) << "Fahrenheit" << endl;

    cout << fixed << setprecision(1);

    for (int i = 0; i <= 20; i++) {
        cout << setw(10) << i << setw(13) << 9.0/5 * i + 32 << '\n';
    }

    return 0;
}