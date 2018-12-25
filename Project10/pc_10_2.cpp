#include <iostream>
#include <cstring>

using namespace std;

void reverse(char *str) {
    size_t l = strlen(str);

    for (int i = 0; i < l / 2; ++i) {
        char temp = str[i];
        str[i] = str[l - i - 1];
        str[l - i - 1] = temp;
    }

    cout << str << endl;
}

int main() {
    char str[100];
    cout << "Enter a string to reverse:\t";
    cin.getline(str, 100);
    cout << "\t-> ";
    reverse(str);
    return 0;
}