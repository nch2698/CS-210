#include <iostream>

using namespace std;

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

int *cpyArr(const int *list, int size) {
    int *res = new int[size];
    for (int i = 0; i < size; ++i) {
        res[i] = list[i];
    }
    return res;
}

double median(const int *list, int size) {
    int *temp = cpyArr(list, size);
    selSort(temp, size);
    double res = size % 2 == 0 ? (temp[size / 2] + temp[size / 2 - 1]) / 2.0 : temp[size / 2];
    delete[] temp;
    return res;
}

int mode(const int *list, int size) {

    if (size <= 1) return -1;

    int *temp = cpyArr(list, size);

    int maxOcc = temp[0];
    int maxFrq = 1;

    int z = 1;
    int prev = temp[0];
    for (int i = 1; i < size; ++i) {
        if (temp[i] == prev) {
            z++;
            if (z >= maxFrq) {
                maxFrq = z;
                maxOcc = temp[i];
            }
        } else z = 1;
    }

    int res = maxFrq > 1 ? maxOcc : -1;
    delete[] temp;
    return res;
}

int main() {
    int STUDENTS = 0;
    cout << "How many STUDENTS are surveyed?:\t";
    do {
        cin >> STUDENTS;
        if (STUDENTS < 0)
            cout << "Invalid number of STUDENTS. Try again.";
    } while (STUDENTS < 0);

    int *data = new int[STUDENTS];

    for (int i = 0; i < STUDENTS; ++i) {
        cout << "How many movies student " << i + 1
             << " sees in a month?\t";
        cin >> data[i];
    }

    cout << "\n\n===============================\n";

    // Average
    double sum = 0;
    for (int j = 0; j < STUDENTS; ++j) {
        sum += data[j];
    }
    cout << "Students see an average of "
         << sum / STUDENTS << " movies a month.";

    // Median
    cout << "Students see a median of "
         << median(data, STUDENTS) << " movies a month.";

    // Mode
    cout << "Students see a mode of "
         << mode(data, STUDENTS) << " movies a month.";

    delete[] data;
    return 0;
}