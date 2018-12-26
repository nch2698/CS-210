#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

bool isVowel(char c, bool firstChar) {
    int a = tolower(c);
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || (!firstChar && a == 'y');
}

void toLowercase(char *c) {
    for (int i = 0; i < strlen(c); ++i) {
        c[i] = static_cast<char>(tolower(c[i]));
    }
}

void toUppercase(char *c) {
    for (int i = 0; i < strlen(c); ++i) {
        c[i] = static_cast<char>(toupper(c[i]));
    }
}

int countVowels(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (isVowel(str[i], i == 0))
            count++;
    }

    return count;
}

int countConsonants(char *str) {
    int count = 0;
    for (int i = 0; i < strlen(str); ++i) {
        if (!isVowel(str[i], i == 0))
            count++;
    }

    return count;
}

int main() {
    const string menu = "\n\n\nA) Count the number of vowels in the string.\n"
                        "B) Count the number of consonants in the string.\n"
                        "C) Convert the string to uppercase\n"
                        "D) Convert the string to lowercase\n"
                        "E) Display the current string\n"
                        "F) Enter another string\n"
                        "M) Display the menu\n"
                        "X) Exit the program\n";
    cout << menu << endl;
    char choice = 0;
    char str[] = "Toi la Duy";
    cout << "Enter the string:\t";
    cin.getline(str, 256);
    do {
        cout << "\nstringtool> ";

        cin >> choice;

        switch (tolower(choice)) {
            case 'a':
                cout << "\nNumber of vowels: " << countVowels(str) << endl;
                break;
            case 'b':
                cout << "\nNumber of consonants: " << countConsonants(str) << endl;
                break;
            case 'c':
                cout << "\nConverting to uppercase..." << endl;
                toUppercase(str);
                break;
            case 'd':
                cout << "\nConverting to lowercase..." << endl;
                toLowercase(str);
                break;
            case 'e':
                cout << "\nThe current string is:\t";
                cout << str << endl;
                break;
            case 'f':
                cout << "\nEnter the string:\t";
                cin.ignore(256, '\n');
                cin.getline(str, 256);
                break;
            case 'm':
                cout << menu;
                break;
            case 'x':
                cout << "\nExiting..." << endl;
                break;
            default:
                cout << "Something went wrong.";
        }
    } while (choice != 'x');

    return 0;
}