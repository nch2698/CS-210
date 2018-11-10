#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int days;
    double total = 0.0;

    cout << "Worked days:\t";
    do {
        cin >> days;
        if (days < 1)
            cout << "Worked days cannot be smaller than 0.\n";
    } while (days < 1);

    cout << setw(5) << "Day" << setw(12) << "Salary ($)" << endl;
    cout << "--------------------\n";

    cout << fixed << setprecision(2);

    double temp = 0.01;

    for (int i = 1; i <= days; i++) {
        cout << setw(5) << i << setw(12) << temp << '\n';
        temp *= 2;
        total += temp;
    }

    cout << "--------------------\n";
    cout << "Total:\t$" << total;

    return 0;
}
