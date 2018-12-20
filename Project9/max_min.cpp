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

    return 0;
}