#include <iostream>
#include <cstring>

using namespace std;

bool isVowel(char c, bool firstChar) {
    int a = tolower(c);
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || (!firstChar && a == 'y');
}

char *toPigLatin(char *str) {

    if (isVowel(str[0], true)) {
        size_t len = strlen(str);
        char *temp = new char[len + 3];
        strcpy(temp, str);
        temp[len] = 'w';
        temp[len + 1] = 'a';
        temp[len + 2] = 'y';
        temp[len + 3] = '\0';
        return temp;
    } else {
        size_t len = strlen(str);
        char *temp = new char[len];
        char temp2[len];
        bool meetVowel = false;
        for (int i = 0, j = 0; i < len; ++i) {
            temp[i] = '\0';
            temp2[i] = '\0';
            char c = str[i];

            if (!meetVowel && !isVowel(c, i == 0)) {
                temp2[i] = str[i];
            } else {
                meetVowel = true;
                temp[j++] = str[i];
            }
        }
        strcat(temp, temp2);
        temp[len] = 'a';
        temp[len + 1] = 'y';
        temp[len + 2] = '\0';
        return temp;
    }
}

int main() {

    char words[5][256] = {0};

    for (int i = 0; i < 5; ++i) {
        cout << "Enter word number " << i + 1 << endl;
        cin >> words[i];
    }

    for (int j = 0; j < 5; ++j) {
        char *c = toPigLatin(words[j]);
        cout << "Pig latin version of " << words[j] << " is " << c << endl;
        delete[] c;
    }
    return 0;
}