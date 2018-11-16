#include <iostream>
#include <iomanip>

using namespace std;

double calculateRetail(double, double);

int main() {
    double cost, markup100;

    cout << fixed << showpoint << setprecision(2);
    cout << "Item wholesale cost:\t";
    do {
        cin >> cost;
        if (cost < 0)
            cout << "Wholesale cost cannot be negative. Enter again:\t";
    } while (cost < 0);

    cout << "Item markup percentage (20% -> 20):\t";
    do {
        cin >> markup100;
        if (markup100 < 0)
            cout << "Markup percentage cannot be negative. Enter again:\t";
    } while (markup100 < 0);

    cout << "\n\nRetail price of the item:\t$"
         << calculateRetail(cost, markup100 / 100);

    return 0;
}

double calculateRetail(double cost, double markup) {
    return cost * (1 + markup);
}