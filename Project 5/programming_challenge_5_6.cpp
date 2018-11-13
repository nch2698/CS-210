#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    int time, speed, i;

    do {
        cout << "What is the speed of the vehicle in mph? ";
        cin >> speed;
        if (speed < 0)
            cout << "Input invalid." << endl;
    } while (speed < 0);

    do {
        cout << "How many hours has it traveled? ";
        cin >> time;
        if (time < 1)
            cout << "Input invalid." << endl;
    } while (time < 1);

    cout << "Hours     " << "Distance traveled" << endl;
    for (i = 1; i <= time; i++) {
        cout << left << i << right << setw(15) << speed * i << endl;
    }
    return 0;
}
