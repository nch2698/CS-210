#include <iostream>
#include <string>

using namespace std;

int main() {
    int years;
    double rain = 0.0;
    cout << "Number of years:\t";
    do {
        cin >> years;
        if (years < 1)
            cout << "Period cannot smaller than 1, enter again.\n";
    } while (years < 1);

    for (int i = 1; i <= years; i++) {
        string pt1 = (i == 1) ? "st" : (i == 2 ? "nd" : "th");
        for (int j = 1; j <= 12; j++) {
            string pt2 = (j == 1) ? "st" : (j == 2 ? "nd" : "th");
            cout << "Inches of rain fall for the " << j
                 << pt2 << " month of the " << i << pt1 << " year:\t";
            double d;
            do {
                cin >> d;
                if (d < 0)
                    cout << "Rainfall inches cannot be negative, enter again:\t";
            } while (d < 0);

            rain += d;
        }
    }

    cout << "Number of months:\t" << years * 12 << endl;
    cout << "Total inches of rainfall:\t" << rain << endl;
    cout << "Average rainfall per month:\t" << rain/years/12 << endl;
    return 0;
}