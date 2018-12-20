#include <iostream>

using namespace std;

// Remember to delete after use
void maxminSwap(int *list, int size) {

    int max = list[0], min = list[0];
    int idMax = 0, idMin = 0;

    for (int i = 1; i < size; ++i) {
        if (list[i] > max) {
            max = list[i];
            idMax = i;
        }
        if (list[i] < min) {
            min = list[i];
            idMin = i;
        }
    }

    int temp = list[idMax];
    list[idMax] = list[idMin];
    list[idMin] = temp;
}

int main() {

    const int SIZE = 7;
    int list[SIZE] = {2, 5, 7, 1, 3, 9, 1};

    cout << "Giving an array comprises of:\t";

    for (int i = 0; i < SIZE; ++i) {
        cout << list[i] << ", ";
    }

    maxminSwap(list, SIZE);

    cout << "\nAfter swap max and min, it becomes:\t";
    for (int i = 0; i < SIZE; ++i) {
        cout << list[i] << ", ";
    }

    return 0;
}