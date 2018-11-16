#include <iostream>

using namespace std;

void qualify() {
    cout << "You are qualified for a credit card.\n"
         << "Your annual interest rate is 12%.";
}

void noQualify() {
    cout << "You are not qualified for a credit card.\n"
         << "In order to be qualified you need:\n"
         << "\t+ Annual Income at least $17,000.00\n"
         << "\t+ Continuously working on the current job for at least the last 2 years.\n";
}

int main() {
    double salary;
    int years;
    cout << "This program will determine if you qualify\n";
    cout << "for our credit card.\n";
    cout << "What is your annual salary? ";
    cin >> salary;
    cout << "How many years have you worked at your ";
    cout << "current job? ";
    cin >> years;
    if (salary >= 17000.0 && years >= 2)
        qualify();
    else
        noQualify();
    return 0;
}