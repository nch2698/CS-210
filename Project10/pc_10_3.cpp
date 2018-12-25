#include <iostream>
#include <cstring>

using namespace std;

int countWord(char *str) {
    size_t len = strlen(str);

    int count = 0;
    bool isCurrentWord = false;

    for (int i = 0; i < len; ++i) {
        if (isspace(str[i]) == 0) {
            if (!isCurrentWord) {
                isCurrentWord = true;
                count++;
            }

        } else isCurrentWord = false;
    }

    return count;
}

int main() {
    char str[256];
    cout << "Enter a string:\t";
    cin.getline(str, 256);
    cout << "There are " << countWord(str) << " words." << endl;
    return 0;
}