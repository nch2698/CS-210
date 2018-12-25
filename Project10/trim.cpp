#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void trimLeft(char *str) {
    size_t len = strlen(str);
    char temp[len];
    size_t cursor = 0;
    bool begin = false;
    for (int i = 0; i < len; ++i) {
        temp[i] = '\0';
        if (!begin && isspace(str[i]) != 0) continue;
        begin = true;
        temp[cursor++] = str[i];
    }
    temp[cursor] = '\0';
    strcpy(str, temp);
}

void trimRight(char *str) {
    size_t len = strlen(str);

    for (size_t i = len - 1; i >= 0; --i) {
        if (isspace(str[i]) != 0) {
            str[i] = '\0';
            continue;
        }
        break;
    }
}

void trimMiddle(char *str) {
    size_t len = strlen(str);
    char temp[len];

    bool meetSpace = false;
    int cursor = 0;
    for (int i = 0; i < len; ++i) {
        temp[i] = '\0';
        if (isspace(str[i]) != 0) {
            if (meetSpace) continue;
            meetSpace = true;
        } else meetSpace = false;
        temp[cursor++] = str[i];
    }

    strcpy(str, temp);
}

int main() {
    char str[256];
    cout << "Enter a string:\t";
    cin.getline(str, 256);
    trimLeft(str);
    cout << "Trimming left resulted in: " << str << endl;
    trimRight(str);
    cout << "Trimming right resulted in: " << str << endl;
    trimMiddle(str);
    cout << "Trimming middle resulted in: " << str << endl;

    return 0;
}