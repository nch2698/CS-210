#include <iostream>

using namespace std;

int main() {
    int *pint = nullptr;

    pint++;
    --pint;
    // pint /= 2;
    // pint *= 4;
    pint += 2;

    return 0;
}