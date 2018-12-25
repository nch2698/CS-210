#include <iostream>

using namespace std;

int getLength(char *str) {
    int r = 0;
    while (str[r] != '\0') {
        r++;
    }
    return r;
}

int main() {
    char str[100];
    cout << "Enter a string:\t";
    cin.getline(str, 100);
    cout << "Your string has " << getLength(str) << " characters." << endl;
    return 0;
}