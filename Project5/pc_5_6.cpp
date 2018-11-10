#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int time;
    double speed;

    cout << "What is the speed of the vehicle in mph?\t";
    do {
        cin >> speed;
        if (speed < 0)
            cout << "Speed cannot be negative, enter again.\n";
    } while (speed < 0);

    cout << "How many hours has it traveled?\t";
    do {
        cin >> time;
        if (time < 1)
            cout << "Time traveled cannot be smaller than 1, enter again.\n";
    } while (time < 1);

    cout << setw(10) << left << "Hour" << setw(25) << "Distance Traveled" << endl;
    cout << "--------------------------------\n";

    for (int i = 1; i <= time; i++) {
        cout << ' ' << setw(9) << left << i << setw(10) << right << speed * i << '\n';
    }

    return 0;
}