#include <iostream>

using namespace std;

// Remember to delete after use
int *maxmin(const int *list, int size) {
    int *res = new int[2];

    int max = list[0], min = list[0];

    for (int i = 1; i < size; ++i) {
        if (list[i] > max) max = list[i];
        if (list[i] < min) min = list[i];
    }

    res[0] = min;
    res[1] = max;

    return res;
}

int main() {

    const int SIZE = 7;
    int list[SIZE] = {2, 5, 7, 1, 3, 9, 1};

    cout << "Giving an array comprises of: ";

    for (int i = 0; i < SIZE; ++i) {
        cout << list[i] << ", ";
    }

    int *mm = maxmin(list, SIZE);

    cout << "\nMax of array is " << mm[1]
         << " and min is " << mm[0];

    return 0;
}