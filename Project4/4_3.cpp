#include <iostream>

using namespace std;

int main() {
    int month, day, year;

    cout << "Enter a month:\t";
    cin >> month;
    if (month < 1 || month > 12) {
        cout << "Month can only range from 1-12. Please restart.";
        return 1;
    }
    cout << "Enter a day:\t";
    cin >> day;
    if (day < 1 || day > 31) {
        cout << "Day can only range from 1-31. Please restart.";
        return 1;
    }
    cout << "Enter a 2 digits year (2018 -> 18):\t";
    cin >> year;
    if (year > 0) {
        cout << "Receive " << year << " ... ";
        year %= 100;
        cout << "Taking " << year;
    } else {
        cout << "BC years do not count. Please restart.";
        return 1;
    }


    cout << "\n\n\n" << month << '/' << day << '/' << year;

    if (month * day == year)
        cout << " is magic date." << endl;
    else
        cout << " is not magic date." << endl;

    return 0;
}