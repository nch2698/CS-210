#include <iostream>

using namespace std;

bool arrCmp(const int *a, const int *b, int size) {
    for (int i = 0; i < size; i++)
        if (a[i] != b[i]) return false;
    return true;
}

int main() {
    int size;

    cout << "Enter the size of 2 arrays:\t";
    do {
        cin >> size;
        if (size <= 0)
            cout << "Invalid size! Try again.";
    } while (size <= 0);

    int *i1 = new int[size], *i2 = new int[size];

    for (int i = 0; i < size; ++i) {
        cout << "Enter integer element " << i << " of array 1:\t";
        cin >> i1[i];
    }

    cout << "\n\n";

    for (int i = 0; i < size; ++i) {
        cout << "Enter integer element " << i << " of array 2:\t";
        cin >> i2[i];
    }

    cout << "\n\n2 arrays are " << (arrCmp(i1, i2, size) ? "similar." : "different.");

    delete[] i1;
    delete[] i2;
    return 0;
}