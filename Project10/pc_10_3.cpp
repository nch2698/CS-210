#include <iostream>
#include <cstring>
#include <cctype>
#include <string>

using namespace std;

int countWord(char *str) {
    size_t len = strlen(str);

    int count = 0;
    bool isCurrentWord = false;

    for (int i = 0; i < len; ++i) {
        if (isalnum(str[i]) != 0) {
            if (!isCurrentWord) {
                isCurrentWord = true;
                count++;
            }

        } else isCurrentWord = false;
    }

    return count;
}

int countWord(string str) {
    int count = 0;
    bool isCurrentWord = false;
    for (unsigned long i = 0; i < str.length(); ++i) {
        char c = str.at(i);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!isCurrentWord) {
                isCurrentWord = true;
                count++;
            }
        } else isCurrentWord = false;
    }
    return count;
}

int main() {
    char s[256] = {0};
    cout << "Enter a string:\t";
    cin.getline(s, 256);
    cout << "There are " << countWord(s) << " words using c-style string algorithm." << endl;

    string s2(s);
    cout << "There are " << countWord(s2) << " words using string object algorithm." << endl;
    return 0;
}