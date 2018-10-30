#include <iostream>

using namespace std;

int main() {

    int i;

    cout << "Enter a number within the range of 1 and 10 "
         << "to convert to Roman Numeral:\t";
    cin >> i;

    // Separate INPUT and OUTPUT by 3 line and then flush the stream
    cout << "\n\n" << endl;

    cout << "Number " << i << " is ";

    switch (i) {
        case 1:
            cout << "I";
            break;
        case 2:
            cout << "II";
            break;
        case 3:
            cout << "III";
            break;
        case 4:
            cout << "IV";
            break;
        case 5:
            cout << "V";
            break;
        case 6:
            cout << "VI";
            break;
        case 7:
            cout << "VII";
            break;
        case 8:
            cout << "VIII";
            break;
        case 9:
            cout << "IX";
            break;
        case 10:
            cout << "X";
            break;
        default:
            cout << "not in range of 1 and 10. "
                 << "Please restart the program and enter the valid number.";
    }

    // A newline at the end of a program will result in better
    // looking interface for some types of terminal
    cout << endl;

    return 0;
}