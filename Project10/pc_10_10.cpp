#include <iostream>
#include <cstring>

using namespace std;

/**
 * Replace every pattern of original string that match with another string
 * using c-style string
 *
 * @note a string cannot be passed to string 1 otherwise it will resulted in
 * stack memory error when C++ tries to clean up stack memory. This will occur
 * only when length of string3 larger than string2. In order to cope with this
 * we need to create new block of memory in heap so C++ will not alarm. This is
 * the difference between using string object and c-style string.
 *
 * @param string1 pointer to the original string
 * @param string2 the string to search for
 * @param string3 the string to replace with
 */
void replaceSubstring(char **string1, const char *string2, const char *string3) {
    size_t len1 = strlen(*string1), len2 = strlen(string2), len3 = strlen(string3);

    bool occurrence[len1];
    for (int j = 0; j < len1; ++j) occurrence[j] = false;


    for (int i = 0; i < len1 - (len2 > 0 ? len2 : 1) + 1; ++i) {

        if ((*string1)[i] == string2[0]) {
            bool match = false;
            for (int j = 1; j < len2; ++j) {
                if (string2[j] != (*string1)[i + j]) break;
                if ((*string1)[i + len2 - 1] == string2[len2 - 1])
                    match = true;
            }

            if (match) {
                occurrence[i] = true;
                i += len2 - 1;
            }
        }
    }

    size_t len4 = len1;
    for (int i = 0; i < len1; ++i) {
        if (occurrence[i]) len4 += (len3 - len2);
    }

    char stringres[len4 + 1];
    int offset = 0;
    for (int i = 0; i < len1; ++i) {
        if (occurrence[i]) {
            for (int j = 0; j < len3; ++j) {
                stringres[i + offset + j] = string3[j];
            }
            i += len2 - 1;
            offset += len3 - len2;
        } else stringres[i + offset] = (*string1)[i];
    }
    stringres[len4] = '\0';
    *string1 = new char[len4 + 1];

    strcpy(*string1, stringres);
}

/**
 * @note string2 and string 3 must be like const string &str because
 * if not the object of that string will be copied not the value. we can
 * make a promise not to change anything by using const keyword
 *
 * @param str1 original string
 * @param str2 the string to search for
 * @param str3 the string to replace with
 */
void replaceSubstring(string &str1, const string &str2, const string &str3){
    for (unsigned long i = 0; i <= str1.length() - str2.length() + 1; i++){
        if (str1.compare(i, str2.length(), str2) == 0){
            str1.replace(i, str2.length(), str3);
        }
    }
}

int main() {
    string str1, str2, str3;

    cout << "The ocurrences of string 2 in string 1 will be replaced by string 3.\n";
    cout << "String 1: "; getline(cin, str1);
    cout << "String 2: "; getline(cin, str2);
    cout << "String 3: "; getline(cin, str3);
    replaceSubstring(str1, str2, str3);
    cout << "Edited string 1: " << str1;
    return 0;
}