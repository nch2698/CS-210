#include <iostream>

using namespace std;

int main() {

    int q;
    double multiplier = 1.0;
    const double price = 99.0;
    const double DISCOUNT_TIER_1 = 0.2,
            DISCOUNT_TIER_2 = 0.3,
            DISCOUNT_TIER_3 = 0.4,
            DISCOUNT_TIER_4 = 0.5;
    cout << "How many packages do you want to buy:\t";
    cin >> q;

    // This block of code is separated from other blocks because its functionality
    // is different from others
    if (q <= 0) {
        cout << "Packages number can not be smaller or equal to 0. "
             << "Please restart and re-enter the valid input." << endl;
        return 1;
    }

    if (q < 10) {
        cout << "No discount" << endl;
    } else if (q < 20) {
        cout << DISCOUNT_TIER_1 * 100 << "% discount." << endl;
        multiplier -= DISCOUNT_TIER_1;
    } else if (q < 50) {
        cout << DISCOUNT_TIER_2 * 100 << "% discount." << endl;
        multiplier -= DISCOUNT_TIER_2;
    } else if (q < 100) {
        cout << DISCOUNT_TIER_3 * 100 << "% discount." << endl;
        multiplier -= DISCOUNT_TIER_3;
    } else {
        cout << DISCOUNT_TIER_4 * 100 << "% discount." << endl;
        multiplier -= DISCOUNT_TIER_4;
    }

    cout << "Total cost: $" << price * q * multiplier << endl;

    return 0;
}