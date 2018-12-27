#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

double avgLetters(char *str) {
    size_t len = strlen(str);

    int count = 0;
    double letters = 0.0;
    bool isCurrentWord = false;

    for (int i = 0; i < len; ++i) {
        if (isalnum(str[i]) != 0) {
            if (!isCurrentWord) {
                isCurrentWord = true;
                count++;
            }
            letters += 1;
        } else isCurrentWord = false;
    }

    return letters / count;
}

int main() {
    char str[256];
    cout << "Enter a string:\t";
    cin.getline(str, 256);

    cout << "The string has an average of " << avgLetters(str)
         << " letters per word" << endl;

    return 0;
}