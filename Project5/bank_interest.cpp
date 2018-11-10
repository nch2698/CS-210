#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

    string name;
    double deposit, interest = 0.0;
    float f100;

    cout << "Customer\'s name:\t";
    getline(cin, name);
    cout << "Deposit amount:\t";
    do{
        cin >> deposit;
        if (deposit < 0)
            cout << "Deposit cannot be negative, enter again.\n";
    } while (deposit < 0);

    cout << "Interest rate: (8% then enter 8)\t";
    cin >> f100;

    cout << "Account Name: " << name << endl;
    cout << setw(6) << "Year" << setw(15) << "Deposit"
         << setw(10) << "Interest" << setw(15) << "Total" << endl;

    cout << fixed << setprecision(0) << noshowpoint;

    for (int i = 1; i <= 12; i++) {
        cout << setw(6) << i << setw(15) << deposit << setw(10)
             << deposit * f100/100 << setw(15) << deposit * (1 + f100/100) << endl;
        deposit *= (1 + f100/100);
        interest += deposit * f100/100;
    }

    cout << "Total Interest:\t" << interest;

    return 0;
}