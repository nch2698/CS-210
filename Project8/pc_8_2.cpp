#include <iostream>

const int TICKETS[] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};

using namespace std;

bool isWinner(int _assert) {
    for (int t : TICKETS) {
        if (_assert == t)
            return true;
    }
    return false;
}

int main() {
    const int TRIES = 3;

    for (int i = 0; i < TRIES; i++) {
        cout << "Enter this week\'s winning ticket:\t";
        int temp;
        cin >> temp;
        if (isWinner(temp)) {
            cout << "You won!\n";
        }
    }
    return 0;
}