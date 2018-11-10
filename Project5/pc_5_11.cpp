#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int start, duration;
    double rate100;

    cout << "Starting number of organisms:\t";
    do {
        cin >> start;

        if (start < 2)
            cout << "Starting organisms cannot be smaller than 2, enter again.\n";
    } while (start < 2);

    cout << "Daily population increase: (2% then enter 2)\t";
    do {
        cin >> rate100;

        if (rate100 < 0)
            cout << "Average daily population increase cannot be negative, enter again.\n";
    } while (rate100 < 0);

    cout << "Number of days multiplied:\t";
    do {
        cin >> duration;
        if (duration < 1)
            cout << "Number of days they multiply cannot be smaller than 1, enter again.\n";
    } while (duration < 1);

    cout << fixed << setprecision(0) << noshowpoint;

    cout << setw(5) << "Day" << setw(17) << "Population Size" << endl;

    for (int i = 0; i < duration; i++) {
        cout << setw(5) << i+1 << setw(17) << pow(1 + rate100/100, i)*start << endl;
    }

    return 0;
}