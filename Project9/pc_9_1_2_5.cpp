#include <iostream>

using namespace std;

int *allocIntArr(int size, int min, int max) {
    int *dest = new int[size];
    for (int i = 0; i < size; ++i) {
        do {
            cout << "Enter element " << i << " for integers array:\t";
            cin >> dest[i];
            if (dest[i] < min || dest[i] > max)
                cout << "Invalid data. Try again.";
        } while (dest[i] < min || dest[i] > max);
    }
    return dest;
}

int *allocIntArr(int size) {
    return allocIntArr(size, 1 << 31, ~(1 << 31));
}

void selSort(int *list, int size) {
    for (int i = 0; i < size; ++i) {
        int min = list[i];
        int index = i;
        for (int j = i; j < size; ++j) {
            if (list[j] < min) {
                min = list[j];
                index = j;
            }
        }
        list[index] = list[i];
        list[i] = min;
    }
}

double getAvg(const int *list, int size) {
    double temp = 0.0;
    for (int i = 0; i < size; ++i) {
        temp += list[i];
    }
    return temp/size;
}

char *getString() {
    const int LEN = 80;

    char sent[LEN] = {0}; // Bunch of zeros
    cout << "Enter a sentence:\t";
    cin.ignore(256, '\n');
    cin.getline(sent, 80);

    char *res = new char[LEN];
    for (int i = 0; i < LEN; ++i) {
        res[i] = sent[i];
        if (sent[i] == '\0')
            break;
    }

    return res;
}

int main() {
    return 0;
}