#include <iostream>

using namespace std;

const int ACCOUNTS[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 8080152, 4562555, 5552012, 5050552,
                        7825877, 1250255, 1005231, 6545231, 3852085, 7576651, 7881200, 4581002};

int main() {
    int c;
    cout << "Enter your charge account number:\t";
    cin >> c;

    for (int i : ACCOUNTS) {
        if (i == c) {
            cout << "The number is valid" << endl;
            return 0;
        }
    }

    cout << "The number is invalid" << endl;

    return 0;
}