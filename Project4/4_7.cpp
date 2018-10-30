#include <iostream>

using namespace std;

int main() {

    long seconds;

    cout << "Enter a number of seconds:\t";
    cin >> seconds;

    /**
     *  The following code does not need to cast to long
     *  because division of a long to a number in cout
     *  stream result in a long type already.
     */
    if (seconds < 60) {
        cout << seconds << " seconds" << endl;
    } else if (seconds < 3600) {
        cout << seconds / 60 << " minutes" << endl;
    } else if (seconds < 86400) {
        cout << seconds / 3600 << " hours" << endl;
    } else {
        cout << seconds / 86400 << " days" << endl;
    }

    return 0;
}