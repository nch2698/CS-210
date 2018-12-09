#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    const int SIZE = 12;
    double rf[SIZE];
    string months[] = {"January", "February", "March",
                       "April", "May", "June", "July",
                       "August", "September", "October",
                       "November", "December"};

    double max = -10000, min = 10000;
    int ms;

    cout << "How many months to enter:\t";
    do {
        cin >> ms;
        if (ms > 12 || ms < 1)
            cout << "Enter again:\t";
    } while (ms > 12 || ms < 1);

    int tm[ms];

    cout << "Which months:\t";
    for (int i = 0; i < ms; i++) {
        int temp;
        do {
            cin >> temp;
            if (temp < 1 || temp > 12)
                cout << "Unknown month. Enter again:\t";
            else tm[i] = temp;
        } while (temp < 1 || temp > 12);
    }

    cin.ignore(256, '\n');

    for (int i = 0; i < ms; i++) {
        cout << "What is the rainfall level for " << months[tm[i] - 1] << ":\t";
        cin >> rf[tm[i]];
        if (rf[tm[i]] > max) max = rf[tm[i]];
        if (rf[tm[i]] < min) min = rf[tm[i]];
    }

    cout << "\n\n\n" << fixed << showpoint << setprecision(2);
    cout << setw(11) << "Month" << setw(20) << "Rainfall (in mm)" << endl;
    for (int i = 0; i < ms; i++) {
        char c = (rf[tm[i]] == max) ? '*' : ((rf[tm[i]] == min) ? '-' : ' ');
        cout << setw(11) << months[tm[i]] << c << setw(12) << rf[tm[i]] << endl;
    }

    cout << "Note: \n\t(-): lowest\n\t(*): highest" << endl;
    return 0;
}