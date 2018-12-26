#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

bool isVowel(char c) {
    int a = tolower(c);
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

void highlightVowels(char *str) {
    size_t len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (isVowel(str[i])) {
            str[i] = static_cast<char>(toupper(str[i]));
        } else str[i] = static_cast<char>(tolower(str[i]));
    }
}

int main() {
    char str[256];
    cout << "Enter a string:\t";
    cin.getline(str, 256);
    highlightVowels(str);

    cout << "After highlighting vowels, we have: " << str << endl;
    return 0;
}