#include <iostream>

using namespace std;

int main() {

    double h, h1, h2;
    int a1, a2;
    int p1 = 0, p2 = 0;

    cout << "Login - enter your height: (cm)\t";
    do {
        cin >> h;
        if (h < 0 || h > 300)
            cout << "Invalid height, enter again:\t";
    } while (h < 0 || h > 300);

    cout << "Hi Lan\n";
    cout << "\tHow old are you?\t";
    do {
        cin >> a1;
        if (a1 < 0 || a1 > 200)
            cout << "\tInvalid age, enter again:\t";
    } while (a1 < 0 || a1 > 200);
    cout << "\tWhat\'s your height:\t";
    do {
        cin >> h1;
        if (h1 < 0 || h1 > 300)
            cout << "\tInvalid height, enter again:\t";
    } while (h1 < 0 || h1 > 300);

    cout << "Hi Mai\n";
    cout << "\tHow old are you?\t";
    do {
        cin >> a2;
        if (a2 < 0 || a2 > 200)
            cout << "\tInvalid age, enter again:\t";
    } while (a2 < 0 || a2 > 200);
    cout << "\tWhat\'s your height:\t";
    do {
        cin >> h2;
        if (h2 < 0 || h2 > 300)
            cout << "\tInvalid height, enter again:\t";
    } while (h2 < 0 || h2 > 300);

    if (a1 <= 16) p1 -= 2;
    else if (a1 < 21) p1 += 5;
    else p1 += 2;

    if (a2 <= 16) p2 -= 2;
    else if (a2 < 21) p2 += 5;
    else p2 += 2;

    if (h1 >= h) p1 -= 1;
    else if ( h - h1 > 30) p1 -= 2;
    else p1 += 3;

    if (h2 >= h) p2 -= 1;
    else if ( h - h2 > 30) p2 -= 2;
    else p2 += 3;
    
    cout << "Your decision:\n";
    if (p1 > p2) cout << "\tLan, are you free on Saturday.";
    else if ( p2 > p1) cout << "\tMai, are you free on Saturday.";
    else {
        cout << "\tLan, are you free on Saturday.\n";
        cout << "\tMai, are you free on Sunday.";
    }

    cout << endl;

    return 0;
}