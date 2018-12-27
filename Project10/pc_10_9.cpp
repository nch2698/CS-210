#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int findMaxIndex(int l[], int size) {

    int max = l[0], maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (max < l[i]) {
            max = l[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

char mostFreqChar(char *arr) {
    int counter[95] = {0};

    for (int i = 0; i < strlen(arr); i++) {
        if (isprint(arr[i])) {
            counter[(arr[i]) - 32]++;
        }
    }
    return static_cast<char>(findMaxIndex(counter, 95) + 32);
}

char mostFreqChar(string arr) {
    int counter[95] = {0};

    for (int i = 0; i < arr.length(); i++) {
        if (isprint(arr[i])) {
            counter[(arr[i]) - 32]++;
        }
    }
    return static_cast<char>(findMaxIndex(counter, 95) + 32);
}

int main() {
    string arr;

    cout << "Enter a string: ";
    getline(cin, arr);

    cout << "The character " << "'" << mostFreqChar(arr) << "'" << " appears most frequent" << endl;
    return 0;
}