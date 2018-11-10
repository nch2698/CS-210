#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int COLUMN = 10;

    for (int i = 1, j = 0; i <= 49; i+=2) {
        cout << setw(3) << i << ' ';
        j++;
        if (j == COLUMN) {
            j = 0;
            cout << '\n';
        }
    }

    return 0;
}