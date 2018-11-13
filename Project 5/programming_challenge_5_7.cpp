#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    double salary = 1.0, total = 0.0;
    int day, i;
    do {
        cout << "The number of days? ";
        cin >> day;
        if (day < 1)
            cout << "Invalid input." << endl;
    } while (day < 1);

    cout << left << setw(5) << "Days" << "     Salary per day in dollar" << endl;
    cout << fixed << setprecision(2);

    for (i = 1; i <= day; i++) {
        cout << left << setw(5) << i << right << setw(20) << salary / 100 << endl;
        total += (salary / 100);
        salary *= 2;
    }
    cout << "Total" << right << setw(20) << total;
    return 0;
}
